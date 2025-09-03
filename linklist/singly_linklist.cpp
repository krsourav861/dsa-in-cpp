#include <iostream> //for cout,cin etc.
#include <conio.h>  //for getch ,clrscr functions etc.
#include <stdlib.h> //for malloc and free functions
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *create_node()
{
    struct node *h1;
    h1 = (struct node *)malloc(sizeof(struct node));
    cout << "Enter any number: ";
    cin >> h1->data;
    h1->next = NULL;
    return h1;
}
void insert_start()
{
    struct node *h2;
    h2 = create_node();
    if (head == NULL)
    {
        head = h2;
    }
    else
    {
        h2->next = head;
        head = h2;
    }
}
void insert_middle()
{
    struct node *h4;

    h4 = create_node();
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        cout << "Inserting at the start." << endl;
        head = h4;
        return;
    }
    else
    {
        int value;
        cout << "Enter the value before which you want to insert the node: ";
        cin >> value;
        struct node *temp, *prev;
        temp = head;
        prev = NULL;
        while (temp->data != value && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            h4->next = head;
            head = h4;
        }
        else
        {
            prev->next = h4;
            h4->next = temp;
        }
    }
}
void insert_end()
{
    struct node *h3;
    h3 = create_node();
    if (head == NULL)
    {
        head = h3;
        return;
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = h3;
        cout << "Node has been inserted at the end." << endl;
    }
}
void delete_start()
{
    if (head == NULL)
    {
        cout << "there is no any node to delete." << endl;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        cout << "Node has been deleted from the start." << endl;
    }
}
void delete_middle() {
    if (head == NULL) {
        cout << "There is no node to delete." << endl;
        return;
    }

    int value;
    cout << "Enter the value of the node you want to delete: ";
    cin >> value;

    struct node *temp = head, *prev = NULL;

    // Traverse the list to find the node with the given value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found." << endl;
        return;
    }

    // If the node to be deleted is the first node (head)
    if (temp == head) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    // Delete the node
    delete temp;  // use delete for C++ memory management
    cout << "Node with value " << value << " has been deleted." << endl;
}
void delete_end()
{
    if (head == NULL)
    {
        cout << "There is no any node to delete." << endl;
    }
    else
    {
        struct node *temp, *prev;
        temp = head;
        prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            prev->next = NULL;
            free(temp);
        }
        cout << "Node has been deleted from the end." << endl;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    cout << "The list is: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int choice;
    cout << "1. insert a node at start" << endl;
    cout << "2. insert a node at middle" << endl;
    cout << "3. insert a node at end" << endl;
    cout << "4. delete a node at start" << endl;
    cout << "5. delete a node at middle" << endl;
    cout << "6. delete a node at end" << endl;
    cout << "7. display the list" << endl;
    cout << "8. exit" << endl
         << endl;
    while (1)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "You chose to insert a node at the start." << endl;
            insert_start();
            break;
        case 2:
            cout << "You chose to insert a node in the middle." << endl;
            insert_middle();
            break;
        case 3:
            cout << "You chose to insert a node at the end." << endl;
            insert_end();
            break;
        case 4:
            cout << "You chose to delete a node at the start." << endl;
            delete_start();
            break;
        case 5:
            cout << "You chose to delete a node in the middle." << endl;
            delete_middle();
            break;
        case 6:
            cout << "You chose to delete a node at the end." << endl;
            delete_end();
            break;
        case 7:
            cout << "You chose to display the list." << endl;
            display();
            break;
        case 8:
            cout << "Exiting..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    getch();
    return 0;
}