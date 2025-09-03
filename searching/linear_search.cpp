#include <iostream>
#include <conio.h>
using namespace std;
void linear_search(int j,int a[],int search,int k){
    int i;
    for (i = 0; i < j; i++)
    {
        if (a[i] == search)
        {
            cout << "number is found at place:  "<<i+1<<"!";
        }
        else
            k--;
        if (k == 0)
        {
            cout << "number is not found!";
        }
    }
}
int main()
{
    int i, search, k, j;
    cout << "how many number u want to enter: ";
    cin >> j;
    int a[j];
    k=j;
    cout << "Enter " << j << " number:\n";
    for (i = 0; i < j; i++)
    {
        cin >> a[i];
    }
    cout << "enter a number u want to search: ";
    cin >> search;
    linear_search(j,a,search,k);
    getch();
    return 0;
}