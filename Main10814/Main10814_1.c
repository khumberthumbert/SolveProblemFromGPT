#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct User
{
	int age;
	char name[101];
} User;

void bubbleSort(User* user, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (user[j].age > user[j + 1].age)
			{
				//swap
				User temp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	User* user = (User*)malloc(sizeof(User) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &user[i].age);
		fgets(user[i].name, sizeof(user[i].name), stdin);
	}

	bubbleSort(user, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d %s", user[i].age, user[i].name);
	}

	free(user);

	return 0;
}