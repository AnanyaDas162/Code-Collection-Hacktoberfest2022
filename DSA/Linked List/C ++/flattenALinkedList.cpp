#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *bottom;

    Node(int value) {
        data = value;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *left, Node *right) {
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
        
    Node *ans = new Node(-1);
    Node *temp = ans;
        
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->bottom = left;
            left = left->bottom;
            temp = temp->bottom;
        } else {
            temp->bottom = right;
            right = right->bottom;
            temp = temp->bottom;
        }
    }
    
    while(left != NULL) {
        temp->bottom = left;
        left = left->bottom;
        temp = temp->bottom;
    }
    
    while(right != NULL) {
        temp->bottom = right;
        right = right->bottom;
        temp = temp->bottom;
    }
    
    ans = ans->bottom;
    return ans;
    
}
    
Node *flatten(Node *root)
{
    if(root == NULL || (root->next == NULL && root->bottom == NULL))
        return root;
        
    Node *right = flatten(root->next);
    Node *temp = root;
    Node *child = temp->bottom;
    
    while(child != NULL) {
        temp -> bottom = child;
        child = child -> bottom;
        temp = temp->bottom;
    }
    
    root = merge(root, right);
    return root;
}

void print(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    } cout << endl << endl;
}

int main()
{
    Node *node = new Node(2);
    Node *head = node;
    node->bottom = new Node(4);
    node->bottom->bottom = new Node(5);
    node->bottom->bottom->bottom = new Node(8);

    node->next = new Node(9);
    node->next->bottom = new Node(11);
    node->next->bottom->bottom = new Node(12);

    node->next->next = new Node(15);
    node->next->next->bottom = new Node(18);
    node->next->next->bottom->bottom = new Node(21);
    node->next->next->bottom->bottom->bottom = new Node(22);
    node->next->next->bottom->bottom->bottom->bottom = new Node(26);
    node->next->next->bottom->bottom->bottom->bottom->bottom = new Node(33);

    /*
        2 -> 9 -> 15
        |    |     |
        4    11    18
        |    |     |
        5    12    21
        |          |
        8          22
                   |
                   26
                   |
                   33
    */

    Node *flattened = flatten(head);
    cout << "\nFlatten Linked List: ";
    print(flattened);

}