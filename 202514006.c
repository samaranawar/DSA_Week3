#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int x;
    struct NODE* next;
} NODE;

NODE* head = NULL;

void insertBeforeHead(int value)
{
    NODE* newItem = (NODE*)malloc(sizeof(NODE));

    newItem->x = value;
    newItem->next = NULL; /// precaution

    if(head == NULL)
    {
        head = newItem;
    }
    else
    {
        newItem->next = head;
        head = newItem;
    }
}

/// You will implement the following functions

void insertLast(int item)
{
    NODE* newItem=(NODE*)malloc(sizeof(NODE));
    newItem->x=item;
    newItem->next=NULL;

    if(head==NULL)
    {
        head=newItem;
        return;
    }
    NODE *cur=head;
    
    while(cur->next != NULL)
    {
        cur=cur->next;
    }
    cur->next=newItem;

    /// Write your code here
}

void insertAfterMatchedValue(int match, int item)
{
    NODE *cur=head;

    while(cur != NULL)
    {
        if(cur->x==match)
        break;

        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("not found\n");
        return;
    }
    NODE* newItem=(NODE*)malloc(sizeof(NODE));
    newItem->x=item;
    newItem->next=cur->next;
    cur->next=newItem;


    /// Write your code here
}

void insertBeforeMatchedValue(int match, int item)
{
    NODE *cur=head;
    NODE *prev=NULL;

    while(cur != NULL)
    {
        if(cur->x==match)
        break;

        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("not found\n");
        return;
    }
    NODE* newItem=(NODE*)malloc(sizeof(NODE));
    newItem->x=item;

    if(cur==head)
    {
        newItem->next=head;
        head=newItem;
    }
    else
    {
        prev->next=newItem;
        newItem->next=cur;
    }
    
    /// Write your code here
}

int deleteFirst()
{
    if(head==NULL)
    {
        printf("empty\n");
        return -1;
    }
    else
    {
        NODE *temp=head;
        head=head->next;
        free(temp);
        return 1;
    }
    /// Write your code here
}

int deleteLast()
{
    if(head == NULL)
        return -1;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return 1;
    }

    NODE *cur = head;
    NODE *prev = NULL;

    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    free(cur);

    return 1;

    /// Write your code here
}

int deleteItem(int item)
{
    NODE *cur = head;
    NODE *prev = NULL;

    /// Search the item
    while (cur != NULL)
    {
        if (cur->x == item)
            break;

        prev = cur;
        cur = cur->next;
    }

    /// Item not found or list empty
    if (cur == NULL)
        return -1;

    /// If the item is in the first node
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
        printf("Linked List is Empty\n");
        return;
    }

    NODE* cur = head;

    while(cur != NULL)
    {
        printf("%d ", cur->x);
        cur = cur->next;
    }

    printf("\n");
}

int main()
{
    printf("MENU:\n");
    printf("1. Insert before head\n");
    printf("2. Insert at last\n");
    printf("3. Insert after matched value\n");
    printf("4. Insert before matched value\n");
    printf("5. Delete first node\n");
    printf("6. Delete last node\n");
    printf("7. Delete matched item\n");
    printf("8. Print linked list\n");
    printf("0. Exit program\n");

    

int choice, value, match;

while(1)
{
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        printf("Enter value: ");
        scanf("%d", &value);
        insertBeforeHead(value);
        break;

    case 2:
        printf("Enter value: ");
        scanf("%d", &value);
        insertLast(value);
        break;

    case 3:
        printf("Enter matched value: ");
        scanf("%d", &match);

        printf("Enter new value: ");
        scanf("%d", &value);

        insertAfterMatchedValue(match, value);
        break;

    case 4:
        printf("Enter matched value: ");
        scanf("%d", &match);

        printf("Enter new value: ");
        scanf("%d", &value);

        insertBeforeMatchedValue(match, value);
        break;

    case 5:
        if(deleteFirst() == -1)
            printf("List is empty\n");
        else
            printf("First node deleted\n");
        break;

    case 6:
        if(deleteLast() == -1)
            printf("List is empty\n");
        else
            printf("Last node deleted\n");
        break;

    case 7:
        printf("Enter item to delete: ");
        scanf("%d", &value);

        if(deleteItem(value) == -1)
            printf("Item not found\n");
        else
            printf("Item deleted\n");
        break;

    case 8:
        printList();
        break;

    case 0:
        exit(0);

    default:
        printf("try 1 to 8\n");
    }

        /// Write your menu-driven code here
}

    return 0;

}