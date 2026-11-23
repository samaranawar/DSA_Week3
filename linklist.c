 #include<stdio.h>
 #include<stdlib.h>

 typedef struct NODE{
    int x;
    struct NODE* next;
 }NODE;

 NODE* head=NULL;

//  NODE* DeleteMatched(int item)
//  {
//     NODE*cur, *prev;
//     while(cur->next!=item) //crawling in link list//cur->next!=NULL use korle last ta print hoyna manually print korte hobe
//     {
//         prev=cur;
//         cur=cur->next;
    
//     }
//     if(cur==NULL) return -1;
//     if(cur==head)
//     {
//         head=cur->next;
//         free(cur);
//     }

//  }
  
 void insertBeforeHead(int item)
 {
    if(head==NULL)
    {
        NODE *p=(NODE*)malloc(sizeof(NODE));
        //p er x er value item
        p->x=item;
        p->next = NULL; 

        if(head==NULL)
        {
            head=p;
            return;
        }
        p->next=head;
        head=p;
    }
 }

 void printList()
 {
    NODE* cur=head;
    while(cur!=NULL) //crawling in link list//cur->next!=NULL use korle last ta print hoyna manually print korte hobe
    {
        printf("%d", cur->x);
        cur=cur->next;
    }
 }

 int main()
 {
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        else if(n==1)
        {
            int item;
            scanf("%d", &item);
            insertBeforeHead(item);
        }
        else if(n==2)
        {
            printList();
        }
        else if(n==3)
        {
            int status= DeleteMatched(item);
            if(status==1)printf("Deleted\n");
            else printf("Element not found\n");
        }
    }
 }

// #include<stdio.h>
// #include<stdlib.h>
 
// typedef struct NODE
// {
//     int x;
//     struct NODE* next;
// } NODE;
 
// NODE* head = NULL;
 
// void insertBeforeHead(int item)
// {
//     NODE* p = (NODE*)malloc(sizeof(NODE));
//     p->x=item;
//     p->next = NULL;
 
//     if(head==NULL)
//     {
//         head=p;
//         return;
//     }
//      p->next = head;
//      head = p;
 
// }
 
// void printList()
// {
//     NODE* cur = head;
//     while(cur!=NULL)
//     {
//         printf("%d ",cur->x);
 
//         cur=cur->next;
//     }
// }
 
 
// int main()
// {
 
//     int n;
//     while(1)
//     {
//         scanf("%d",&n);
//         if(n==0) break;
//         else if(n==1)
//         {
//             int item; scanf("%d",&item);
//             insertBeforeHead(item);
//         }
//         else if(n==2)
//         {
//             printList();
//         }
 
//     }
 
 
// }