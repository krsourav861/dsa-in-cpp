#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int a[]={22,4,8,23,56,43,12,5,7,9};
    int right=9,left=0,loc=0,n=10,temp,i;
    step1:
    while (a[loc] < a[right] && loc!= right) {
        right--;
    }
if (loc == right)
{
    return a[i];
}
if (a[loc] > a[right])
{
    temp=a[loc];
    a[loc]=a[right];
    a[right]=temp;
    loc=right;
}   
while (a[loc] > a[left] && loc!= left) {
        left++;
    }
if (loc == left){
    return a[i];
}if (a[loc] < a[left]){
    temp=a[loc];
    a[loc]=a[left];
    a[left]=temp;
    loc=left;
}
goto step1;
cout << "Sorted array: ";
for (int i=0; i<10; i++){
    cout << a[i] << " ";
}
getch();
    return 0;
}