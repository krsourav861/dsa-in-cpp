#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *create_node()
{
    cout << "creating new node..." << endl;
    struct node *h1;
    h1 = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data: ";
    cin >> h1->data;
    h1->prev = NULL;
    h1->next = NULL;
    return h1;
}
void insert_start()
{
    struct node *h2;
    h2 = create_node();
    if (head == NULL)
    {
        cout << "linklist is empty." << endl;
        cout << "inserting first node..." << endl;
        head = h2;
    }
    else
    {
        cout << "inserting node at start..." << endl;
        struct node *temp;
        temp = head;
        head = h2;
        head->next = temp;
        temp->prev = head;
    }
}
void insert_last()
{
    struct node *h2;
    h2 = create_node();
    if (head == NULL)
    {
        cout << "linklist is empty." << endl;
        cout << "inserting first node..." << endl;
        head = h2;
    }
    else
    {
        cout << "inserting node at last..." << endl;
        struct node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = h2;
        h2->prev = temp;
    }
}
void insert_middle()
{
    struct node *h2;
    h2 = create_node();
    if (head == NULL)
    {
        cout << "linklist is empty" << endl;
        cout << "inserting first node..." << endl;
        head = h2;
    }
    else
    {
        cout << "inserting node at middle..." << endl;
        struct node *temp, *temp1;
        temp = head;
        cout << "enter the data after which you want to insert the node" << endl;
        int data;
        cin >> data;
        while (temp->data != data && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->data == data)
        {
            temp1 = temp->next;
            temp->next = h2;
            h2->prev = temp;
            h2->next = temp1;
            if (temp1 != NULL)
            {
                temp1->prev = h2;
            }
        }
        else
        {
            cout << "node not found" << endl;
        }
    }
}
void delete_start()
{
    if (head == NULL)
    {
        cout << "No any node to delete." << endl;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
}
void delete_middle()
{
    if (head == NULL)
    {
        cout << "No any node to delete." << endl;
    }
}
void delete_last()
{
    if (head == NULL)
    {
        cout << "No any node to delete." << endl;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "linklist is empty." << endl;
    }
    else
    {
        cout << "linklist is: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    cout << "1. Insert a node at start." << endl;
    cout << "2. Insert a node at middle." << endl;
    cout << "3. Insert a node at end." << endl;
    cout << "4. Delete a node at start." << endl;
    cout << "5. Delete a node at middle." << endl;
    cout << "6. Delete a node at end." << endl;
    cout << "7. Display the list." << endl;
    cout << "8. Exit." << endl;
    while (1)
    {
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            insert_start();
            break;
        case 2:
            insert_middle();
            break;
        case 3:
            insert_last();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_middle();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "Exiting the program..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    getch();
    return 0;
}