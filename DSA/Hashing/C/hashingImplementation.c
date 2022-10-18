#include<stdio.h>
#include<stdlib.h>
#define HASH_TABLE_SIZE 13


//declaring the node structure
struct node{
    int data;
    struct node* next;
};


//create the node
struct node *CreateNode(int data)
{
    struct node *NewNode=(struct node *)malloc(sizeof(struct node));
    NewNode->data=data;
    NewNode->next=NULL;
    
    return NewNode;
}


//Insert the given element into hash table
void InsertEnd(struct node *head, int data)
{
    struct node *CreatedNode=CreateNode(data);
    
    if (CreatedNode==NULL)
    {
        printf("Error in creating new node\n");
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=CreatedNode;
    }
}


//search the given element in the hash table
void search(struct node *head, int data,int i)
{
    if(head==NULL)
    {
        printf("Element not present\n");
    }
    else{
        int flag=0;
        struct node * temp=head;
        while(temp!=NULL)
        {
            if(temp->data==data)
            {   flag=1;
                printf("Data found in the chain at posistion %d \n", i);
                break;
            }
            temp=temp->next;
        }
        
        if(flag==0)
        {
            printf("The given element doesn't exist\n");
        }
    }
}


//Delete the given element from hash table
struct node *DeleteNode(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("Couldn't delete element as the chain is empty\n");
        return head;
    }
    else{
        struct node *temp=head;
        struct node*save;
        int flag=0;
        if(head->data==data)
        {
            printf("Data of deleted element is %d\n", head->data);
            save =head;
            head=head->next;
            free(save);
            return head;
        }
        else{
             
             while(temp->next->next!=NULL)
             {
                if(temp->next->data==data)
                {
                    flag=1;
                    break;
                }
               temp=temp->next;
             }
             
             if(flag==1)
             {
                printf("Data of deleted element is %d\n", data);
                save=temp->next;
                temp->next=save->next;
                free(save);
                
            }
            else if(temp->next->next==NULL&&temp->next->data==data){
                printf("Data of deleted element is %d\n", data);
                save=temp->next;
                temp->next=save->next;
                free(save);
                
            }
            else{
                printf("Couldn't find element to be deleted\n");
            }
            
        
            return head;
        }
       
    }
}


//print the hash table
void print(struct node *head)
{
    if(head!=NULL)
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            printf("%d ->", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
    }
}


// hash function
int HashFunction(int key)
{
    return key % HASH_TABLE_SIZE;
}


int main()
{
    struct node**HashTable=(struct node **)calloc(HASH_TABLE_SIZE,sizeof(struct node *));
    for(int i=0;i<HASH_TABLE_SIZE;i++)
    {
        HashTable[i]=NULL;
    }
    
    char opt='y';
    int index;
    int key;
    int ele;
    do{ printf("**************HASHING USING CHAINING**************\n");
        printf("Choose the following operation\n");
        printf("1. Insert Element into hash table\n");
        printf("2. Search element in the hash table\n");
        printf("3. Delete the element from the hash table\n");
        printf("4. Print the element of hash table\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: {
                       printf("Enter the key to be inserted\n");
                       scanf("%d", &key);
                       index=HashFunction(key);
                       if(HashTable[index]==NULL)
                       {
                           HashTable[index]=CreateNode(key);
                       }
                       else{
                           InsertEnd(HashTable[index],key);
                       }
                       break;
                    }
                    
            case 2: {
                       printf("Enter the Element to be searched\n");
                       scanf("%d", &ele);
                       index=HashFunction(ele);
                       search(HashTable[index],ele,index);
                       break;
                    }
                    
            case 3: {
                       printf("Enter the Element to be deleted\n");
                       scanf("%d", &ele);
                       index=HashFunction(ele);
                       HashTable[index]=DeleteNode(HashTable[index],ele);
                       break;
                    }
                    
            case 4: {  
                       printf("The hash table is\n");
                       for(int i=0;i<HASH_TABLE_SIZE;i++)
                       {
                           print(HashTable[i]);
                           
                       }
                       break;
                    }
            
            default: printf("Wrong Choice entered\n");
        }
        
        
        printf("Do you want to continue(y/n)\n");
        scanf(" %c", &opt);
        
    }while(opt=='y'||opt=='Y');
    
    return 0;
}



