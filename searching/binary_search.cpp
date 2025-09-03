#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a[7] = {2, 3, 5, 7, 9, 22, 33};
    int search, l = 0, r = 6, m;
    int n = 0;

    cout << "Enter a number you want to search: ";
    cin >> search;

    while (l <= r)
    {
        m = (l + r) / 2;

        if (a[m] == search)
        {
            cout << "Number is found at index " << m;
            n = 1;
            break;
        }
        else if (a[m] > search)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    if (n == 0)
    {
        cout << "Number is not found";
    }

    getch();
    return 0;
}
