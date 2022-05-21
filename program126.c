#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
    struct node *prev;    //*
};

typedef struct node  NODE;
typedef struct node  * PNODE;
typedef struct node ** PPNODE;
void Display(PNODE head)
{
    printf("Data from linked list is:\n");
    while (head!=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
    

}

int Count(PNODE head)
{
    int iCnt=0;
    while ((head!=NULL))
    {
        iCnt++;
        head=head->next;
    }
    return iCnt;
    

}

void InsertFirst(PPNODE head ,int no)
{
    PNODE newn=NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;       //*

     //LL is empty
    
     if((*head)!=NULL) 
    {
        newn->next=*head;
        (*head)->prev=newn;
       


    }
     *head=newn;

}

void InsertLast(PPNODE head,int no)
{
     PNODE newn=NULL;
     PNODE temp=NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;       //*

    if(*head==NULL)   //LL is empty
    {
        *head=newn;
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newn;
        newn->prev=temp;


        
    }

}

void DeleteFirst(PPNODE head )
{
    if((*head==NULL))
    {
        return;
    }
    if((*head)->next=NULL)   //single Node
    {
        free(*head);
        *head=NULL;

    }
    else                //more tha one node
    {
         *head=(*head)->next;  //*
        free((*head)->prev);   //*
        (*head)->prev=NULL;    //*

    }


}

void DeleteLast(PPNODE head )
{

    PNODE temp=NULL;
     if((*head==NULL))
    {
        return;
    }
    if((*head)->next=NULL)   //single Node
    {
        free(*head);
        *head=NULL;

    }
    else                //more tha one node
    {   temp=*head;
        while(temp->next->next !=NULL)
        {
            free(temp->next);
            temp->next=NULL;

        }

       

    }

}
void DeleteAtpos(PPNODE head,int pos)
{
    
    PNODE temp=NULL;
    
    int iCnt=0;
    int size=0;
    size=Count(*head);

    if((pos<1)||(pos>size))
    {
        printf("Invalide position\n");
        return;
    }

    if(pos==1)
    {
        DeleteFirst(head);

    }
    else if(pos==size)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE newn=NULL;
      temp=*head;
    newn =(PNODE)malloc(sizeof(NODE));

    
    newn->next=NULL;
    newn->prev=NULL; 

    for(iCnt=1;iCnt<(size-1);iCnt++)
    {
        temp=temp->next;
    }
      temp->next=temp->next->next;
      free(temp->next->prev);
      temp->next->prev=temp;
    
    }


}
void InsertAtpos(PPNODE head,int no,int pos )
{ 
    PNODE temp=NULL;
    int iCnt=0;
    int size=0;
    size=Count(*head);

    if((pos<1)||(pos>(size+1)))
    {
        printf("Invalide position\n");
        return;
    }

    if(pos==1)
    {
        InsertFirst(head,no);

    }

    else if(pos==size-1)
    {
        InsertLast(head,no);
    }
    else
    {
        PNODE newn=NULL;
      temp=*head;
    newn =(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL; 

    for(iCnt=1;iCnt<(size-1);iCnt++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;
    }


}


int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertLast(&first,51);
    InsertLast(&first,101);
    
    Display(first);
    iRet=Count(first);
    printf("elements are:%d\n",iRet);
    DeleteAtpos(&first,3);
    Display(first);

     DeleteFirst(&first);
     DeleteLast(&first);
    
     Display(first);
    iRet=Count(first);
    printf("elements are:%d\n",iRet);

    return 0;
}