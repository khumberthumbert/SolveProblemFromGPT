#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    
    cin >> N;
    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        result += i;
    }
    cout << result;
    return 0;
}