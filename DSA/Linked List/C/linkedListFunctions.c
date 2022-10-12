#include<stdio.h>
#include<stdlib.h>

//*********************************declaring node structure*********************************
struct node{
    int data;
    struct node *next;
    struct node *previous;
};

//*************************************creating new node**************************************

struct node *createNode(int data)
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Error while creating new node\n");
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        newNode->previous=NULL;
    }
    return newNode;
}

//**********************************inserting node at beginning******************************

struct node *insertBeginning(struct node *head)
{   int data;
    printf("Enter data of node to be inserted\n");
    scanf("%d",&data);
    if(head==NULL)
    {
        head=createNode(data);
        printf("Node inserted at beginning successfully\n");
    }
    else{
        struct node *curNode=createNode(data);
        curNode->next=head;
        curNode->next->previous=curNode;
        head=curNode;
        printf("Node inserted at beginning successfully\n");
    }
    return head;
}

//**********************************inserting node at end**********************************

struct node *insEnd(struct node *tail)
{   int data;
    printf("Enter data of node to be inserted\n");
    scanf("%d",&data);
    if(tail==NULL)
    {
        tail=createNode(data);
        printf("Node inserted at end successfully\n");
    }
    else{
        struct node *temp=createNode(data);
        tail->next=temp;
        temp->previous=tail;
        tail=temp;
        
       printf("Node inserted at end successfully\n"); 
    }
   return tail;
}

//********************************insert node after node with data x********************************
struct node *insertX(struct node *head,struct node *tail)
{
    int x;
    int data;
    if(head==NULL)
    {   printf("List is Empty\n");
        return NULL;
    }
    printf("Enter the value of x\n");
    scanf("%d",&x);
    struct node *temp=head;
    
    while((temp->data!=x)&&(temp->next!=NULL))
    {
        temp=temp->next;
    }
    if(temp->next==NULL&&temp->data!=x)
    {
        printf("No node present with data x\n");
    }
    else if(temp==tail){
        printf("Enter data of new node to be inserted\n");
        scanf("%d",&data);
        struct node *newNode=createNode(data); 
        tail->next=newNode;
        newNode->previous=tail;
        tail=newNode;   
    }
    else{
        printf("Enter data of new node to be inserted\n");
        scanf("%d",&data);
        struct node *newNode=createNode(data);
        newNode->next=temp->next;
        newNode->previous=temp;
        temp->next->previous=newNode;
        temp->next=newNode;
        printf("Node inserted successfully\n");
    }
    return tail;
}

//*****************************************delete middle node************************************
struct node *deleteMiddle(struct node *head,struct node *tail)
{
    int n=0;
    int data;
    int mid;
    int count;
    if(head==NULL)
    {
        printf("No node present\n");
        return NULL;
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    temp=head;
    struct node *save;
    if(n==1)
    {
       data=head->data;
       free(head);
       head=NULL;
       printf("Data of deleted element is : %d\n",data);
    }
    else if(n%2!=0)
    {   count=1;
        mid=(n+1)/2;
        while(count<mid-1)
        {
           temp=temp->next;
           count++;
        }
        save=temp->next;
        data=save->data;
        temp->next=save->next;
        save->next->previous=temp;
        free(save);
        printf("Data of deleted element is : %d\n",data);
    }
    else{
        temp=head;
        count=1;
        mid=n/2;
        if(mid==1)
        {
           data=head->data;
           save=head;
           head=tail;
           tail->previous=NULL;
           free(save);
           printf("Data of deleted element is : %d\n",data);
        }
        else{
             while(count<mid-1)
            {
               temp=temp->next;
               count++;
            }
            save=temp->next;
            data=save->data;
            save->next->previous=temp;
            temp->next=save->next;
            free(save);
            printf("Data of deleted element is : %d\n",data);
        }
    }
    return head;
}

//****************************************delete last node*****************************************
struct node *deleteLast(struct node *tail)
{   int data;
    if(tail==NULL)
    {
        printf("Can't be deleted as list is empty\n");
    }
    else if(tail->previous==NULL)
    {   data=tail->data;
        free(tail);
        tail=NULL;
        printf("Data of last deleted node is : %d\n",data);
    }
    else{
        struct node *save=tail;
        data=save->data;
        save->previous->next=NULL;
        tail=tail->previous;
        free(save);
        printf("Data of last deleted node is : %d\n",data);
    }
    return tail;
}

//**************************************print even position nodes**********************************

void printEven(struct node *head)
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(head->next==NULL)
    {
        printf("Only single element present\n");
        
    }
    else{
        struct node *temp=head;
        printf("%d ",temp->next->data);
        temp=temp->next;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {   if(temp->next->next!=NULL) 
                {temp=temp->next->next;
                printf("%d ",temp->data);
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        printf("\n");
    }
    
    return;
}

//*********************************sum of content at odd position nodes************************
void sumOdd(struct node *head)
{
    int sum=0;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else{
        struct node *temp=head;
        sum+=temp->data;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
               if(temp->next->next!=NULL)
               {
                   temp=temp->next->next;
                   sum+=temp->data;
               }
               else{
                   break;
               }
            }
            else{
                break;
            }
        }
        printf("Sum of elements present at odd position in the list is %d\n",sum);
    }
    return;
}

//*****************************************reverse the linked list****************************
struct node *reverse(struct node *head)
{
   if(head->next==NULL)
   {
       return head;
   }
   
   
   
    struct node *temp=head;
    struct node *next=NULL;
    struct node *back=NULL;
    while(temp!=NULL)
    {
      next=temp->next;
      temp->next=back;
      temp->previous=next;
      back=temp;
      temp=next;
    }
    head=back;
    head->previous=NULL;
    printf("List reversed successfully, print the list to see the result\n");
    return head;
}

//***************************************delete alternate nodes******************************
struct node *deleteAlternate(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct node *save=head;
        head=head->next;
        head->previous=NULL;
        free(save);
        struct node *temp=head;
        struct node *delete;
        while(temp!=NULL)
        {
           if(temp->next!=NULL)
           {
               delete=temp->next;
               temp->next=delete->next;
               delete->next->previous=temp;
               temp=temp->next;
               free(delete);
           }
           else {
               break;
           }
        }
    }
    printf("Element deleted at alternate positions, print the new list\n");
    return head;
}

//**********************************************print list**************************************
void printList(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    
    return;
}

//**************************************main driver function**************************************

int main()
{
    struct node *head=NULL;
    struct node *tail=NULL;
    int ch;
    int y=1;
    do{
         printf("Choose any operation\n");
         printf("1. Insert a node at the beginning.\n");
         printf("2. Insert a node at the end.\n");
         printf("3. Take an element from the user (say x) and insert a node after the node with content x.\n");
         printf("4. Delete the middle node.\n");
         printf("5. Delete the last node.\n");
         printf("6. Print the nodes which are at an even number position.\n");
         printf("7. Print the sum of the content of the nodes which are at an odd number position.\n");
         printf("8. Reverse the linked list in constant space.\n");
         printf("9. Delete the alternate nodes from the linked list.\n");
         printf("10.Print the linked list\n");
         printf("11.Exit\n");
         scanf(" %d",&ch);
         switch(ch)
         {
             case 1: {head=insertBeginning(head);
                      if(head->next==NULL)
                       tail=head;
                      break;}
             case 2: {tail=insEnd(tail);
                       if(tail->previous==NULL)
                        head=tail;
                       break;}
             case 3: tail = insertX(head,tail); break;
             case 4: {head=deleteMiddle(head,tail); 
                      if(head==NULL)
                      tail=NULL;
                      break;}
             case 5: {tail=deleteLast(tail);
                      if(tail==NULL)
                      head=tail;
                      break;}
             case 6: printEven(head); break;
             case 7: sumOdd(head); break;
             case 8: {tail=head;
                      head=reverse(head); 
                      break;}
             case 9: {head=deleteAlternate(head);
                      break;}
             case 10: printList(head); break;
             case 11: y=0; break;
         }
    }while(y==1);
    return 0;
}


