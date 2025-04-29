#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int value; // A[i] 값
	int index; // A[i]의 원래 인덱스
} Element;

int compare(const void* a, const void* b) {
	Element* elemA = (Element*)a;
	Element* elemB = (Element*)b;
	return elemA->value - elemB->value;
}

int main(void)
{
	int N = 0;
	scanf_s("%d", &N);

	Element* elements = (Element*)malloc(sizeof(Element*) * N);
	int* P = (int*)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &elements[i].value);
	}
	for (int i = 0; i < N; i++) {
		elements[i].index = i;
	}

	qsort(elements, N, sizeof(Element), compare);

	for (int sorted_idx = 0; sorted_idx < N; sorted_idx++) {
		int original_idx = elements[sorted_idx].index;
		P[original_idx] = sorted_idx;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", P[i]);
	}

	free(elements);
	free(P);

	return 0;
}