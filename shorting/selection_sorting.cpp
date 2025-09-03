#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int min, n, index,i, j, temp;
    cout << "enter number of index:";
    cin >> n;
    int a[n];
    cout << "enter " << n << " numbers:";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n-1; i++)
    {
        min = a[i];
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        temp = a[i];
        a[i] = min;
        a[index] = temp;
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }

    return 0;
}