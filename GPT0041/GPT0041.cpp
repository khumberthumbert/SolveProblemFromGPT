#include <iostream>

using namespace std;

int main()
{
    int* arr = new int[10];
    
    
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "최대값: " << max << endl;
    cout << "최소값: " << min << endl;
}
