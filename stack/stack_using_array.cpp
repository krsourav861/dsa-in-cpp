#include <iostream>
#include <conio.h>
#define size 10
using namespace std;
int stack[size];
int top = -1;
int num;
void push()
{
    if (top == size - 1)
    {
        cout << "stack is overflow";
    }
    else
    {
        cout << "enter a number you want to store in a stack: ";
        top++;
        cin >> stack[top]; 
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "dont have any element to delete.";
    }
    else
    {
        int n;
        n=stack[top];
        cout<<"popped element is:- "<<n<<"\n";
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        cout << "dont have any element to display.";
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << "\n";
        }
    }
}
int main()
{
    int choice;

    cout << "1. push.\n2. pop.\n3. display.\n4. exit.";
    while (1)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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