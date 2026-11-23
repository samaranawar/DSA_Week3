#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
{
    int v;
    struct Node *L, *R;
} Node;
 
Node *head, *tail;
 
void init()
{
    head = NULL;
    tail = NULL;
}
 
void createFirstElement(int x)
{
    head = (Node*)malloc(sizeof(Node));
    head -> v = x;
    head -> L = NULL;
    head -> R = NULL;
    tail = head;
}
 
void insertFirst(int x)
{
    if(head!=NULL)
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->v=x;
        temp->L=NULL;
        temp->R=NULL;
 
        temp->R=head;
        head->L=temp;
        head=temp;
        return;
    }
    createFirstElement(x);
 
 
}
 
// void insertLast(int x)
// {
 
// }
 
Node* findFirstOccurrence(int x)
{
    Node*cur=head;
    while(cur !=NULL)
    {
        if(cur->v==x)break;
        cur=cur->R;
    }
    return cur;
 
}
 
Node* findLastOccurrence(int x)
{
    Node*cur=tail;
    while(cur !=NULL)
    {
        if(cur->v==x)break;
        cur=cur->L;
    }
    return cur;
 
}
 
Node* findMiddleElement()
{
    Node* hare=head;
    Node* tor=head;
   

    while(hare!= NULL && hare->R != NULL)
    {
        tor=tor->R;
        hare=hare->R->R;

    }
    return tor;
    
}
 
// void deleteHead()
// {
 
// }
 
// void deleteTail()
// {
 
// }
 
void deleteFirstOccurrence(int x)
{
    Node*cur=head;
    Node*prev=NULL;

    if(head==NULL)
    {
        printf("not found\n");
    }

    while(cur !=NULL)
    {
        if(cur->v==x)break;
        prev=cur;
        cur=cur->R;
    }
    if(cur==NULL)
    {
        printf("not found\n");
        return;
    }
    if(cur==head)
    {
        head=head->R;
        free(cur);

        if(head==NULL)
        {
            tail=NULL;
        }
        return;    
    }
    if(cur->R==NULL)
    {
        prev->R=NULL;
        free(cur);
        tail=prev;
        return;

    }

    prev->R=cur->R;
    cur->R->L=prev;
    free(cur);

 
}
 
// void deleteLastOccurrence(int x)
// {
 
// }
 
// void sortList()
// {
 
// }
 
void printList()
{
    if(head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    Node* cur = head;

    while(cur != NULL)
    {
        printf("%d ", cur->v);
        cur = cur->R;
    }

    printf("\n");
 
}
 
// int length()
// {
 
// }
 
 
 
int main()
{
    init();
    while(1)
    {
        int choice;
        int value;
        scanf("%d",&choice);
 
        if(choice==1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            insertFirst(value);
            //break;
        }
        else if(choice==2)
        {
            Node *x=findMiddleElement();
            printf("%d\n", x->v);
            //break;
 
        }
        else if(choice==3)
        {
            printList();
 
        }
        else if(choice==4)
        {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            deleteFirstOccurrence(x);
            printList();

 
        }
    //     else if(choice==5)
    //     {
 
    //     }
    //     else if(choice==6)
    //     {
 
    //     }
    //     else if(choice==7)
    //     {
 
    //     }
    //     else if(choice==8)
    //     {
 
    //     }
    //     else if(choice==9)
    //     {
 
    //     }
    //     else if(choice==10)
    //     {
 
    //     }
    //     else if (choice == 11)
    //     {
 
    //     }
    //     else
    //     {
 
    //     }
}  // }
}