#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);
 int Height(struct node *root,int level,int *max_level){
    
    if(root==NULL)
     return *max_level;
     
    if(*max_level<level){
        *max_level=level;
    }
    Height(root->left,level+1,max_level);
    Height(root->right,level+1,max_level);
} 
int height1(struct node *root){
    int max_level=0;
    return Height(root,1,&max_level);
} 

void printLevelOrder(struct node* root)
{
    int h = height1(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
       if(root->data>=5 &&root->data<=45)
        printf("%d ", root->data);
        
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 

int main()
{
    struct node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(50);
    root->left->left = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
 
    return 0;
}
