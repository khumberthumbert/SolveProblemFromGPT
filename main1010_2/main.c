#include <stdio.h>

long long comb(int n, int r) {
    if (r > n - r) r = n - r; // ´ëÄª¼º
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - r + i);
        result /= i;
    }
    return result;
}

int main() {
    int N;
    scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        int r, n;
        scanf_s("%d %d", &r, &n);
        printf("%lld\n", comb(n, r));
    }

    return 0;
}
