#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head;

struct node *createnode(int data){
    
    struct node *n;
    
    n=(struct node *)malloc(sizeof(struct node));
    
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}
int levelutil(struct node *root,int level,int *max_level){
    
    if(root==0)
     return *max_level;
    
    if(*max_level<level){
        *max_level=level;
    }
    levelutil(root->left,level+1,max_level);
    levelutil(root->right,level+1,max_level);
    
}
int level(struct node *root){
    int max_level=0;
    return levelutil(root,1,&max_level);
    
}
int main(){
    
    struct node *p1=createnode(1);
    struct node *p2=createnode(2);
    struct node *p3=createnode(3);
    struct node *p4=createnode(4);
    struct node *p5=createnode(5);
    
   
    p1->right=p3;
    p1->left=p2;
    p2->left=p4;
    p2->right=p5;
    
    int k= level(p1);
    printf("%d",k);

}
