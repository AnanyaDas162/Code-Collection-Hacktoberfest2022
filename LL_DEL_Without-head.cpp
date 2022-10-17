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

Node* Create_node(int n)
{
    ptr =new Node;
    ptr->data=n;
    ptr->next=NULL;
}


void del_Node(Node* node)
{
    if(!node->next)
        return;

    Node* del=node->next;
    node->data = del->data;
    node->next=del->next;

    free(del);

    
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

   
         cout<<"Now the list is: \n";
         Display(start);

        data = 2, pos = 3;
        //Insert_Pos(&start, pos, data);
       Node* del=start->next->next->next;
       del_Node(del);

        Display(start);
   
    return 0;
} 