#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int N = 0, M = 0, result = 64;

	scanf_s("%d %d", &N, &M);

	char** arr = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (M + 1));
		scanf_s("%s", arr[i]);
	}

	for (int row = 0; row <= N - 8; row++) {
		for (int col = 0; col <= M - 8; col++) {
			int repaintWhiteStart = 0;
			int repaintBlackStart = 0;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					char current = arr[row + i][col + j];

					//W로 시작하는 경우
					if ((i + j) % 2 == 0)
					{
						if (current != 'W') repaintWhiteStart++;
						if (current != 'B') repaintBlackStart++;
					}
					else {
						if (current != 'B') repaintWhiteStart++;
						if (current != 'W') repaintBlackStart++;
					}
				}
			}

			int minPaint = repaintWhiteStart < repaintBlackStart ? repaintWhiteStart : repaintBlackStart;

			//최소값 갱신
			if (minPaint < result) result = minPaint;
		}
	}
	printf("%d", result);

	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}

	free(arr);

	return 0;
}