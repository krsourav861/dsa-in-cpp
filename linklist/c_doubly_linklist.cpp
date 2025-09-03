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
struct node *create_node(int ele)
{
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->prev = NULL;
    p1->data = ele;
    p1->next = NULL;
    return p1;
}
void insert_start(int ele)
{
    struct node *h1;
    h1 = create_node(ele);
    if (head == NULL)
    {
        cout << "linklist is empty, creating first node..." << endl;
        head = h1;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *temp = head;
        h1->prev = temp->prev;
        h1->prev->next = h1;
        temp->prev = h1;
        h1->next = temp;
        head = h1;
    }
}
void insert_end(int ele)
{
    struct node *h2;
    h2 = create_node(ele);
    if (head == NULL)
    {
        cout << "linklist is empty, creating first node..." << endl;
        head = h2;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *temp = head->prev;
        temp->next = h2;
        h2->prev = temp;
        h2->next = head;
        head->prev = h2;
    }
}
void insert_middle(int ele)
{
    struct node *h3;
    h3 = create_node(ele);
    if (head == NULL)
    {
        cout << "linklist is empty, creating first node..." << endl;
        head = h3;
        head->next = head;
        head->prev = head;
        return;
    }
    struct node *temp = head;
    int num;
    cout << "enter the number before which you want to insert a node: ";
    cin >> num;
    while (temp->next->data != num && temp->next != head)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        cout << "the number before which you want to insert a new node is not found in the middle of the elements.";
    }
    else
    {
        h3->next = temp->next;
        temp->next->prev = temp->next = h3;
        h3->prev = temp;
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
        struct node *t1 = head;
        t1->next = t1->prev = NULL;
        head = NULL;
        free(t1);
    }
    else
    {
        struct node *temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        temp->prev = temp->next = NULL;
        free(temp);
    }
}
void delete_end()
{
    if (head == NULL)
    {
        cout << "there is no any node to delete";
    }
    else if (head->next == head)
    {
        struct node *t1 = head;
        t1->next = t1->prev = NULL;
        head = NULL;
        free(t1);
    }
    else
    {
        struct node *temp = head->prev;
        head->prev = temp->prev->next;
        temp->prev->next = head;
        temp->prev = temp->next = NULL;
        free(temp);
    }
}
void delete_middle()
{
    if (head == NULL)
    {
        cout << "there is no any node to delete";
    }
    else if (head->next == head)
    {
        struct node *t1 = head;
        t1->next = t1->prev = NULL;
        head = NULL;
        free(t1);
    }
    else
    {
        struct node *temp, *temp1;
        temp = head;
        int num;
        cout << "enter data which are in the middle of the nodes and you want to delete: ";
        cin >> num;
        while (temp->next->data != num && temp->next != head)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            cout << "the data you have entered is not found in the middle of the linklist.";
            return;
        }
        temp1 = temp->next;
        temp1->next->prev = temp1->prev;
        temp->next = temp1->next;
        temp1->prev = temp1->next = NULL;
        free(temp1);
    }
}
void count_nodes()
{
    if (head==NULL)
    {
        cout<<"nodes are empty.";
        return;
    }
    struct node *temp=head;
    int count=1;
    while (temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    cout<<count<<" node...";
}
void display()
{
    if (head == NULL)
    {
        cout << "there is no any node to display.";
        return;
    }
    struct node *ptr;
    ptr = head;
    do
    {
        cout << ptr->data << " ->";
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    int choice, ele;
    cout << "1. create node at start: " << endl;
    cout << "2. create node at end: " << endl;
    cout << "3. create node at middle: " << endl;
    cout << "4. delete node at start: " << endl;
    cout << "5. delete node at end: " << endl;
    cout << "6. delete node at middle: " << endl;
    cout << "7. count number of nodes: " << endl;
    cout << "8. display elements: " << endl;
    cout << "9. exit: " << endl;
    while (1)
    {
        cout << endl
             << "enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter element: ";
            cin >> ele;
            insert_start(ele);
            break;
        case 2:
            cout << "enter element: ";
            cin >> ele;
            insert_end(ele);
            break;
        case 3:
            cout << "enter element: ";
            cin >> ele;
            insert_middle(ele);
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_middle();
            break;
        case 7:
            count_nodes();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "invalid choice.";
            break;
        }
    }
    return 0;
    getch();
}