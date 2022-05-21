







#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;           // 4
    struct node *next;  // 8
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head, int no)
{
    // Allocate memory for node (dynamically)
    // Initialise that node

    // Check whether LL is empty or not
    // If LL is empty then new node is the first node so update its address in first pointer through head

    // If LL is not empty then store the address of first node in the next pointer of our new node
    // update the first pointer thruogh head
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));     // newn = (struct node *)malloc(12);

    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)   // LL is empty
    {
        *head = newn;
    }
    else        // LL contains atleast one node
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    // Allocate memory for node (dynamically)
    // Initialise that node

    // Check whether LL is empty or not
    // If LL is empty then new node is the first node so update its address in first pointer through head

    // If LL is not empty then
    // travel till last node of LL
    // store address of new node in the next pointer of last node

    PNODE newn = NULL;
    PNODE temp=NULL;


    newn = (PNODE)malloc(sizeof(NODE));     // newn = (struct node *)malloc(12);

    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)   // LL is empty
    {
        *head = newn;
    }
    else        // LL contains atleast one node
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

            
    }
}

void Display(PNODE head)
{
    printf("Elements from linked list are : \n");

    while(head != NULL)
    {
        printf("| %d |-> ",head->data);
        head = head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head -> next;
    }
    return iCnt;
}


//Delete Fitst

void DeleteFirst(PPNODE head)     //LL is empty return

{
    PNODE temp=NULL;

    //if LL is empty return
    if(*head==NULL)
    {
        return;
    }
    else                       //LL contain atleast one node
    {
        temp=*head;
        *head=temp->next;
        free(temp);



    }

}
  ///DeleteLast

void DeleteLast(PPNODE head)

{

    PNODE temp=NULL;

    if(*head==NULL)  //LL is Empty
    {
        return;
    }
    else if((*head)->next==NULL)   //LL contain one node
    {

        free(*head);
        *head=NULL;


    }
    else      //LL contain more tha one node
    {
        temp=*head;
        while((temp->next)->next!=NULL)
        {
            temp=temp->next;

        }

        free(temp->next);
        temp->next=NULL;

    }


}



void InsertAtPos(PPNODE head,int no, int pos)
{
    //consider no of nodes are 4

    //if position is invalid return directly(<1or >5)
    // if position is 1 the call InsertFirst()
    // if position is N+1 the call InsertLast()  (position is 5)
    

    int size=0;
    PNODE newn=NULL;
    PNODE temp=NULL;
    int iCnt=0;
    size=Count(*head);

    if((pos<1)||(pos>(size+1)))
    {
        printf("position is invalide\n");
        return;
    }
    if(pos==1)
    {
        InsertFirst(head,no);
    }
    else if(pos==(size+1))
    {
        InsertLast(head,no);

    }
    else
    {   
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));     // newn = (struct node *)malloc(12);

         newn->data = no;
         newn->next = NULL;
        
        for(iCnt=1;iCnt>(pos-1);iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;


    }



}


void DeleteAtPos(PPNODE head,int pos)
{
    
    int size=0;
    PNODE newn=NULL;
    PNODE temp=NULL;
    int iCnt=0;
    PPNODE tempdelete=NULL;
    size=Count(*head);


    if((pos<1)||(pos>size))
    {
        printf("position is invalide\n");
        return;
    }
    if(pos==1)
    {
        DeleteFirst(head,no);
    }
    else if(pos==size)
    {
        DeleteLast(head);

    }
    else
    {   
        

           
        temp=*head;
        
        
        
        for(iCnt=1;iCnt>(pos-1);iCnt++)
        {
            temp=temp->next;
        }
        tempdelete=temp->next;
        temp->next=temp->next->next;
        free(tempdelete);
    }



}









int main()
{
    int iRet = 0;
    PNODE first = NULL;

    InsertFirst(&first,101);    // call by address
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
    InsertAtPos(&first,75,3);
    DeleteAtPos(&first);

    Display(first);     // Call by value

    iRet = Count(first);
    printf("Number of nodes are  : %d\n",iRet);

    InsertFirst(&first,1);

    Display(first);     // Call by value


    InsertLast(&first,111);
     InsertLast(&first,121);
    DeleteFirst(&first);
    DeleteFirst(&first);
     DeleteLast(&first);
    
    iRet = Count(first);
    printf("Number of nodes are  : %d\n",iRet);
    Display(first);

    printf("number of node are:%d\n",iRet);



    return 0;
}