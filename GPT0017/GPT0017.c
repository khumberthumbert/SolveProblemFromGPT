#include <stdio.h>

int main(void)
{
    int arr[2][3] = { {1,2,3}, {4,5,6} };

    // 2차원 배열 포인터 선언
    // 정수를 3개 가지는 배열을 가리키는 포인터. p는 int[3] 배열 하나를 가리키고 있다.
    int (*p)[3] = arr;

    // 2차원 배열처럼 접근 가능
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", p[i][j]);  // 더 직관적인 접근 방식
        }
    }

    return 0;
}
