#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n, i, j, temp;
    cout << "enter range of number:";
    cin >> n;
    int a[n];
    cout << "enter " << n << " numbers:";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "after shorting number is:";
    for (j = 0; j < n; j++)
    {
        cout << a[j] << " ";
    }
    return 0;
}