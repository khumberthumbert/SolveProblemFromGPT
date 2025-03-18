#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singleList.h"

MYNODE g_HeadNode = { 0 };
MYNODE g_TailNode = { 0 };
static unsigned int g_listCount = 0;


void InitList(void)
{
	ReleaseList();
	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
	g_listCount = 0;
}

int IsEmpty(void)
{
	if (g_HeadNode.pNext == &g_TailNode ||
		g_HeadNode.pNext == NULL)
		return 1;

	return 0;
}

void ReleaseList(void)
{
	if (IsEmpty())
		return;

	/*
	g_HeadNode.pNext�ּҰ� g_TailNode�� �ּҿ� ���� �ʾƾ� �ݺ�
	*/
	MYNODE* pTmp = g_HeadNode.pNext;
	MYNODE* pDelete;
	while (pTmp != &g_TailNode)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete->pszKey);
		if (pDelete->pDataCache != NULL)
			free(pDelete->pDataCache);
		free(pDelete);
	}

	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
	g_listCount = 0;
}

char* GetKey(void* thisPointer)
{
	USERDATA* pUser = (USERDATA*)thisPointer;
	return pUser->name;
	//return pUser->phone;
}

/*
offset�� �ε��� üũ��
void* calloc(int n, int size); : �־��� size�� ũ�⸦ ���� ������ n���� �Ҵ�

*/
void AddNewNode(const char* pszKey,
	const void* pData, int sizeData,
	bool bNew, unsigned int offset)
{
	MYNODE* pNewNode = calloc(1, sizeof(MYNODE));
	int lenOfKey = (int)strlen(pszKey); //key�� ���� �ľ�
	pNewNode->pszKey = malloc(lenOfKey + 1);
	strcpy_s(pNewNode->pszKey, lenOfKey + 1, pszKey);

	if (pData != NULL && sizeData > 0)
	{
		void* pNewData = malloc(sizeData);
		memcpy(pNewData, pData, sizeData);
		pNewNode->pDataCache = pNewData;
		pNewNode->sizeOfData = sizeData;
	}

	pNewNode->bNew = bNew;
	pNewNode->offset = offset;

	MYNODE* pPrevNode = g_TailNode.pPrev;
	pPrevNode->pNext = pNewNode;
	pNewNode->pPrev = pPrevNode;
	pNewNode->pNext = &g_TailNode;
	g_TailNode.pPrev = pNewNode;

	++g_listCount;
}

void* SearchListByName(char* pszKey)
{
	MYNODE* pTmp = g_HeadNode.pNext;
	while (pTmp != &g_TailNode)
	{
		if (strcmp(pTmp->pszKey, pszKey) == 0)
		{
			if (pTmp->pDataCache != NULL)
				return pTmp;

			FILE* fp = NULL;
			fopen_s(&fp, "listData.dat", "rb");

			USERDATA user = { 0 };
			fseek(fp, pTmp->offset * sizeof(USERDATA), SEEK_SET);
			if (fread(&user, sizeof(USERDATA), 1, fp) > 0)
			{
				pTmp->pDataCache = malloc(sizeof(USERDATA));
				memcpy(pTmp->pDataCache, &user, sizeof(USERDATA));
				pTmp->sizeOfData = sizeof(USERDATA);

				fclose(fp);
				return pTmp;
			}

			fclose(fp);
		}

		pTmp = pTmp->pNext;
	}

	return NULL;
}

/*
2�� �޸� file�� ������ �о����, ���α׷� �޸𸮿� �����ϴ� �Լ�
*/
int LoadListFromFile(void)
{
	ReleaseList();
	FILE* fp = NULL;
	//rb : ���̳ʸ� ��忡�� �б� -> ���� ������ �״�� �б� ����. �ٹٲ� ��ȯ ����.
	fopen_s(&fp, "listData.dat", "rb");
	if (fp == NULL)
		return 0;

	USERDATA user = { 0 };
	unsigned int offset = 0;
	//fread(void* ptr, size_t size, size_t count, FILE *file) : size_t count : ptr�� ������ �迭�� ���� �ϳ��� ũ�� �Է�
	while (fread(&user, sizeof(USERDATA), 1, fp) > 0)
	{
		AddNewNode(user.name, NULL, 0, false, offset);
		//void* memset(void* ptr, int value, size_t num); : int value : �޸𸮿� �����ϰ��� �ϴ� ���� ���� ������ ��.
		memset(&user, 0, sizeof(USERDATA));
		++offset;
	}

	fclose(fp);
	return 1;
}

int SaveNewDataToFile(void)
{
	FILE* fp = NULL;
	fopen_s(&fp, "listData.dat", "ab+");
	if (fp == NULL)
		return 0;

	MYNODE* pTmp = g_HeadNode.pNext;
	while (pTmp != NULL && pTmp != &g_TailNode)
	{
		if (pTmp->bNew == true)
			fwrite(pTmp->pDataCache, pTmp->sizeOfData, 1, fp);

		pTmp = pTmp->pNext;
	}

	fclose(fp);
	return 1;
}

int SaveNodeToFile(MYNODE* pNode)
{
	if (pNode->pDataCache == NULL || pNode->sizeOfData == 0)
		return 0;

	FILE* fp = NULL;
	fopen_s(&fp, "listData.dat", "rb+");
	if (fp == NULL)
		return 0;

	fseek(fp, pNode->offset * sizeof(USERDATA), SEEK_SET);

	if (fwrite(pNode->pDataCache, sizeof(USERDATA), 1, fp) > 0)
	{
		fclose(fp);
		return 1;
	}

	return 0;
}
