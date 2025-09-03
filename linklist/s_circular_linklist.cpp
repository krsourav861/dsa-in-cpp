#include <iostream>
#include <conio.h>
using namespace std;
struct cslink
{
    int data;
    struct cslink *next;
};
struct cslink *head = NULL;
struct cslink *create_node()
{
    struct cslink *h1;
    h1 = (struct cslink *)malloc(sizeof(struct cslink));
    cout << "enter data: ";
    cin >> h1->data;
    return h1;
}
void insert_start()
{
    struct cslink *h2;
    h2 = create_node();
    if (head == NULL)
    {
        head = h2;
        head->next = head;
    }
    else
    {
        struct cslink *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        h2->next = head;
        temp->next = h2;
        head = h2;
    }
}
void insert_middle()
{
    if (head == NULL)
    {
        struct cslink *h1;
        h1 = create_node();
        head = h1;
        head->next = head;
    }
    else if (head->next == head)
    {
        struct cslink *h2;
        h2 = create_node();
        struct cslink *temp = head;
        h2->next = head;
        temp->next = h2;
        head = h2;
    }
    else
    {
        struct cslink *temp1;
        temp1 = head;
        int n;
        cout << "enter the data before you want to put the node: ";
        cin >> n;
        while (temp1->next != head && temp1->next->data != n)
        {
            temp1 = temp1->next;
        }
        if (temp1->next->data != n)
        {
            cout << "node not found";
            return;
        }
        else
        {
            struct cslink *h3;
            h3 = create_node();
            h3->next = temp1->next;
            temp1->next = h3;
        }
    }
}
void insert_end()
{
    if (head == NULL)
    {
        struct cslink *h1;
        h1 = create_node();
        head = h1;
        head->next = head;
    }
    else
    {
        struct cslink *h2, *temp;
        h2 = create_node();
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = h2;
        h2->next = head;
    }
}
void delete_start()
{
    if (head == NULL)
    {
        cout << "there is no any node to delete";
    }
    else if (head->next == head)
    {
        struct cslink *temp;
        temp = head;
        free(temp);
        head = NULL;
    }
    else
    {
        struct cslink *temp1, *temp2;
        temp2 = temp1 = head;
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }
        head = temp2->next;
        temp1->next = head;
        free(temp2);
    }
    
}
void delete_middle()
{
    if (head == NULL)
    {
        cout << "there is no any node to delete";
        return;
    }
    struct cslink *temp,*temp1;
    temp = head;
    int n,count=0;
    cout << "enter the data you want to delete: ";
    cin >> n;
    while (temp->next->data!=n)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp->next->next;
    free(temp1);
}
void delete_end()
{
if (head==NULL)
    {
        cout<<"there is no any node to delete: ";
    }
    else if (head ->next==head)
    {
        struct cslink *temp;
        temp=head;
        free(temp);
        head=NULL;
    }
    else{
        struct cslink *temp1,*temp2;
        temp1=temp2=head;
        while (temp1->next->next!=head) 
        {
            temp1= temp1->next;
        } 
        temp2=temp1->next;
        temp2->next=NULL;
        temp1->next=head;
    }

}
void display()
{
    struct cslink *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "linklist is empty.\n";
    }
    else
    {
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    int choice;
    cout << "1. insert a node at start: " << endl;
    cout << "2. insert a node at middle: " << endl;
    cout << "3. insert a node at end: " << endl;
    cout << "4. delete a node at start: " << endl;
    cout << "5. delete a node at middle: " << endl;
    cout << "6. delete a node at end: " << endl;
    cout << "7. display the list: " << endl;
    cout << "8. exit: " << endl
         << endl;
    while (1)
    {
        cout << "Enter your choice: ";
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
            insert_end();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_middle();
            break;
        case 6:
            delete_end();
            break;
        case 7:
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