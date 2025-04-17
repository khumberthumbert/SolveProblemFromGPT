#include <stdio.h>
/*
함수포인터를 이용한 전략패턴. 행동(알고리즘)을 캡슐화해서, 동적으로 선택하거나 교체할 수 있게 해주는 패턴.
프로그램의 핵심 로직은 그대로 두고, 구체적인 처리 방법(전략)을 외부에서 주입하는 방식.
*/

//구체 전략
int* bubbleSort(int* arr, int size) {
	int tmp = 0;
	for (int i = 0; i < size -1 ; i++) { // 마지막 값은 자동 정렬되므로 n-1번까지만 반복. 효율 위해서.
		for (int j = 0; j < size - i - 1; j++) { // i번 돌 때마다 마지막 값에는 큰 값이 들어오므로 끝까지 비교할 필요 x
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr;
}

//구체 전략
int* selectionSort(int* arr, int size) {
	int least = 0, tmp = 0;

	//마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수 -1) 만큼 반복한다.
	for (int i = 0; i < size - 1; i++) {
		least = i; //최솟값 인덱스 설정.

		//최솟값을 탐색한다.
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[least]) { // 비교값이 더 작을 때 비교값 인덱스를 입력.
				least = j;
			}
		}

		// 최소값이 자기 자신이면 자료 이동을 하지 않는다.
		if (i != least) {
			tmp = arr[i];
			arr[i] = arr[least];
			arr[least] = tmp;
		}
	}

	return arr;
}

//구체 전략
int* insertionSort(int* arr, int size) {

	int tmp = 0, i = 0, j = 0;
	for (i = 1; i < size; i++) //첫 시작은 2번째부터니 배열 인덱스 a[1]번부터 시작
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--) // i -1 번부터 처음까지 하나씩 비교하면서 넣으므로
		{
			if (arr[j] > tmp) //비교값이 더 크면 한칸씩 당긴다.
			{
				arr[j + 1] = arr[j];
			}
			else break; // 비교값이 더 작으면 삽입할 곳을 찾았으므로 멈춘다.
		}
		arr[j + 1] = tmp; // 삽입할 곳에 값을 넣는다.
	}
	return arr;
}


void sort(int* arr, int size, void (*sortFunc)(int*, int)) {
	sortFunc(arr, size);
}

int main(void)
{
	int N = 0;
	printf("정렬할 배열의 크기: ");
	scanf_s("%d", &N);

	printf("배열 입력: ");
	int arr[100] = { 0 };

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("정렬 방식 선택 (1:버블, 2:선택, 3:삽입): ");

	//strategy인터페이스
	void (*sortFuncs[])(int*, int) = { bubbleSort, selectionSort, insertionSort };

	int type = 0;
	scanf_s("%d", &type);

	if (type > 0 && type <= 3) {
		//sortFuncs[type - 1] -> 전략 선택자.
		sort(arr, N, sortFuncs[type - 1]); //전략을 실행하는 쪽.
		for (int i = 0; i < N; i++) {
			printf("%d ", arr[i]);
		}
	}



	return 0;
}