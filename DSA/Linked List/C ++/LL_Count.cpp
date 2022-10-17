#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    
}*start,*newptr,*save,*ptr;

Node* getNode(int n)
{
    ptr =new Node;
    ptr->data=n;
    ptr->next=NULL;
}
int getCount(Node* head)
{
    int count = 0; 
   
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


void Display(Node* np)
{
    while(np!=NULL)
    {
        cout<<np->data<<"->";
        np=np->next;
    }
    cout<<"!!\n";
}

int main()
{
    

    int data,pos;

    Node* start = NULL;
    start = getNode(3);
    start->next = getNode(5);
    start->next->next = getNode(8);
    start->next->next->next = getNode(10);
    start->next->next->next->next = getNode(11);
    start->next->next->next->next->next = getNode(12);
    start->next->next->next->next->next->next = getNode(15);
   
         cout<<"Now the list is: \n";
         Display(start);

        data = 2, pos = 3;
        //Insert_Pos(&start, pos, data);
       cout<<"The length of the list is : ";
       cout<<getCount(start);
   
    return 0;
} 
