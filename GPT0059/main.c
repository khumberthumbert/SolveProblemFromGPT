#include <stdio.h>


int* bubbleSort(int* arr, int size) {
	int tmp = 0;
	for (int i = 0; i < size -1 ; i++) { // ������ ���� �ڵ� ���ĵǹǷ� n-1�������� �ݺ�. ȿ�� ���ؼ�.
		for (int j = 0; j < size - i - 1; i++) { // i�� �� ������ ������ ������ ū ���� �����Ƿ� ������ ���� �ʿ� x
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	return *arr;
}

int* selectionSort(int* arr, int size) {
	int least = 0, tmp = 0;

	//������ ���ڴ� �ڵ����� ���ĵǱ� ������ (���� ���� -1) ��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < size - 1; i++) {
		least = i; //�ּڰ� �ε��� ����.

		//�ּڰ��� Ž���Ѵ�.
		for (int j = i + 1; j < size; i++) {
			if (arr[j] < arr[least]) { // �񱳰��� �� ���� �� �񱳰� �ε����� �Է�.
				least = j;
			}
		}

		// �ּҰ��� �ڱ� �ڽ��̸� �ڷ� �̵��� ���� �ʴ´�.
		if (i != least) {
			tmp = arr[i];
			arr[i] = arr[least];
			arr[least] = tmp;
		}
	}

	return *arr;
}

int* insertionSort(int* arr, int size) {

	int tmp = 0, i = 0, j = 0;
	for (i = 1; i < size; i++) //ù ������ 2��°���ʹ� �迭 �ε��� a[1]������ ����
	{
		tmp = arr[i];
		for (j = i - 1; i >= 0; j--) // i -1 ������ ó������ �ϳ��� ���ϸ鼭 �����Ƿ�
		{
			if (arr[j] > tmp) //�񱳰��� �� ũ�� ��ĭ�� ����.
			{
				arr[j + 1] = arr[j];
			}
			else break; // �񱳰��� �� ������ ������ ���� ã�����Ƿ� �����.
		}
		arr[j + 1] = tmp; // ������ ���� ���� �ִ´�.
	}
	return *arr;
}


void sort(int* arr, int size, void (*sortFunc)(int*, int)) {

}

int main(void)
{
	int N = 0;
	printf("������ �迭�� ũ��: ");
	scanf_s("%d", &N);

	printf("�迭 �Է�:");
	int arr[100] = { 0 };

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("���� ��� ���� (1:����, 2:����, 3:����): ");

	void (*fp)(int*, int);



	return 0;
}