#include <iostream>

using namespace std;

bool isPrime(int num) {

    if (num == 1) return false; //1은 소수가 아니다.
    if (num == 2) return true; // 2는 소수
    if (num % 2 == 0) return false; // 2를 제외한 짝수는 소수가 아니다.

    //3부터 루트num 까지 검사 (홀수만 검사하면 연산감소)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false; // 나누어 떨어지면 소수가 아니다.
    }
    return true; // 위 조건을 모두 통과하면 소수.
}

int main()
{
    int N = 0;
    cin >> N;
    int* arrs = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arrs[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (isPrime(arrs[i]))
            cout << arrs[i] << " ";
    }
    delete[] arrs;

    return 0;
}