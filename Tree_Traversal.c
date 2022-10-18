/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* then print the data of node */
    printf("%d ", node->data);
    
    
    /* first recur on left child */
    printPreorder(node->left);
 
    
 
    /* now recur on right child */
    printPreorder(node->right);
}

/* Given a binary tree, print its nodes in posteorder*/
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printPostorder(node->left);
 
    
 
    /* now recur on right child */
    printPostorder(node->right);
    
    /* then print the data of node */
    printf("%d ", node->data);
}

 
/* Driver code*/
int main()
{
    struct node* root = newNode(25);
    root->left = newNode(15);
    root->right = newNode(50);
    root->left->left = newNode(10);
    root->left->right = newNode(22);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(12);
    root->left->right->left = newNode(18);
    root->left->right->right = newNode(24);
    root->right->left = newNode(35);
    root->right->right = newNode(70);
    root->right->left->left = newNode(31);
    root->right->left->right = newNode(44);
    root->right->right->left = newNode(66);
    root->right->right->right = newNode(90);
 
      // Function call
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);
    
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
    
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
    
 
    
    return 0;
}
