#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct node
{
    int value;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void insertHead(int val)
{
    //create a new node
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = val;
    newItem->next = NULL;

    if (head == NULL) tail = newItem;
    //insert the new node at the head
    newItem->next = head;
    head = newItem;
}

void insertTail(int val)
{
    //create a new node to be inserted
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = val;
    newItem->next = NULL;
    if (head == NULL)
    {
        head = newItem;
        tail = newItem;
        return;
    }

    newItem->next = NULL;
    tail->next = newItem;
    tail = newItem;
}
void printList()
{
    if (head == NULL) return;
    struct node *cur =  head;
    while (cur != NULL)
    {
        printf("%d \t", cur->value);
        cur = cur->next;
    }
}
int deleteHead()
{
    struct node *cur;
    if (head == NULL) return -1;
    cur = head;
    head = head->next;

    if (head == NULL) tail = NULL;

    int val = cur->value;
    free(cur);
    return val;
}
