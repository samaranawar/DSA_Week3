#include<iostream>
using namespace std;

class NODE{
public:
    int x;
    struct NODE* next;

    NODE()
    {
        this->x = 0;
        this->next = NULL;
    }
    NODE(int value)
    {
        this->x = value;
        this->next = NULL;
    }
};


NODE* head = NULL;

void insertBeforeHead(int value)
{
    NODE* newItem = new NODE(value);

    if(head==NULL)
    {
        head = newItem;
    }
    else
    {
        newItem->next = head;
        head = newItem;
    }
}

void insertLast(int item)
{
    NODE* newItem = new NODE(item);

    if(head == NULL)
    {
        head = newItem;
    }
    else
    {
        NODE* cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newItem;
    }
}

void insertAfterMatchedValue(int match, int item)
{
    if (head == NULL) return;

    NODE* cur = head;

    while (cur != NULL)
    {
        if (cur->x == match)
        {
            NODE* newItem = new NODE(item);
            newItem->next = cur->next;
            cur->next = newItem;

            return;
        }
        cur = cur->next;
    }
}

void insertBeforeMatchedValue(int match, int item)
{
    if (head == NULL) return;

    NODE* cur = head;
    NODE* prev = NULL;
    while (cur != NULL)
    {
        if (cur->x == match)
        {
           NODE* newItem = new NODE(item);

            if (cur == head)
            {
                newItem->next = head;
                head = newItem;
            }
            else
            {
                prev->next = newItem;
                newItem->next = cur;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int deleteFirst()
{
    if (head==NULL)
    {
        return -1;
    }
    NODE *temp = head;
    head = head->next;
    free(temp);
    return 1;
}

int deleteLast()
{
    if (head==NULL)
    {
        return -1;
    }
    NODE *cur=head;
    NODE *prev=NULL;
    while (cur->next!=NULL)
    {
        prev = cur;
        cur=cur->next;
    }
    if (prev == NULL)
    {
        head = NULL;
        free(cur);
        return 1;
    }
    prev->next=NULL;
    free(cur);
    return 1;
}

int deleteMatchedItem(int item)
{
    NODE *cur = head;
    NODE *prev = NULL;

    while (cur != NULL)
    {
        if (cur->x == item)
            break;

        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
        return -1;

    if (cur == head)
    {
        head = head->next;
        free(cur);
    }
    else
    {
        prev->next = cur->next;
        free(cur);
    }

    return 1;
}

void printList()
{
    if(head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    NODE* cur = head;

    while(cur != NULL)
    {
        cout << cur->x << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    cout << "MENU:" << endl;
    cout << "1. Insert before head" << endl;
    cout << "2. Insert at last" << endl;
    cout << "3. Insert after matched value" << endl;
    cout << "4. Insert before matched value" << endl;
    cout << "5. Delete first node" << endl;
    cout << "6. Delete last node" << endl;
    cout << "7. Delete matched item" << endl;
    cout << "8. Print linked list" << endl;
    cout << "0. Exit program" << endl;

    while(1)
    {
        int ch,item,match;
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            cin >> item;
            insertBeforeHead(item);
            break;
        case 2:
            cin >> item;
            insertLast(item);
            break;
        case 3:
            cin >> match >> item;
            insertAfterMatchedValue(match, item);
            break;
        case 4:
            cin >> match >> item;
            insertBeforeMatchedValue(match, item);
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteLast();
            break;
        case 7:
            cin >> item;
            deleteMatchedItem(item);
            break;
        case 8:
            printList();
            break;
        case 0:
            return 0;
        }
    }
}

