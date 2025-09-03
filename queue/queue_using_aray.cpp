#include <iostream>
#include <conio.h>
#define size 10
using namespace std;
int queue[size];
int rear = -1, front = 0;
void insert()
{
    if (rear == size - 1)
    {
        cout << "queue is overflow";
    }
    else
    {
        rear++;
        cout << "enter an element: ";
        cin >> queue[rear];
    }
}
void delete1()
{
    if (front > rear)
    {
        cout << "dont  have any element to delete.";
    }
    else
    {
        int num;
        num = queue[front];
        cout << "deleted elements are: " << num;
        front++;
    }
}
void display()
{
    if (front > rear)
    {
        cout << "queue is empty.";
    }
    else
    {
        int i;
        cout << "elements are: ";
        for (i = rear; i >= front; i--)
        {
            cout << queue[i] << " | ";
        }
    }
}
int main()
{
    int choice;
    cout << "1. insert element\n2. delete element\n3. display\n4. exit";
    while (1)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete1();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice,try again...\n";
            break;
        }
    }
    getch();
    return 0;
}