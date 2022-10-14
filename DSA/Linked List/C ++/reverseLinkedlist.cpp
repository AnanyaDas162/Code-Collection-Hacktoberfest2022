// Iterative C++ program to reverse a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* Function to reverse the linked list */
	void reverse()
	{
		// Initialize current, previous and next pointers
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;
			// Reverse current node's pointer
			current->next = prev;
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/




// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	Node* reverse(Node* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		/* reverse the rest list and put
		the first element at the end */
		Node* rest = reverse(head->next);
		head->next->next = head;

		/* tricky step -- see the diagram */
		head->next = NULL;

		/* fix the head pointer */
		return rest;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(n)
*/



// Head recursive C++ program to reverse a linked list
#include <iostream>
using namespace std;

// Linked list node
class Node {
public:
	int data;
	Node* next;

	// constructor: automatically assigns the value to the
	// data and next pointer to NULL
	Node(){};
	Node(int val)
		: data(val)
		, next(NULL){};
};

void reverseUtil(Node* curr, Node* prev, Node** headref)
{
	// Base Case - If curr is last node
	if (curr->next == NULL) {
		// Update head of the linked list
		*headref = curr;
		// Update next to prev node
		curr->next = prev;
		return;
	}
	// Recursive Call for next node
	reverseUtil(curr->next, curr, headref);
	// Update next to prev node
	curr->next = prev;
}

void reverse(Node** headref)
{
	// If linked list is empty or contains single node
	if (*headref == NULL || (*headref)->next == NULL)
		return;
	// Call reverseUtil() with prev as NULL
	reverseUtil(*headref, NULL, headref);
}

// Function to insert a node at the end of linked list
void push(Node** headref, int x)
{
	Node* newptr = new Node(x);
	if (*headref == NULL) {
		*headref = newptr;
	}
	else {
		Node* temp = *headref;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newptr;
	}
}

// Functio to print the linked list
void print(Node* headref)
{
	while (headref != NULL) {
		cout << headref->data << " ";
		headref = headref->next;
	}
	cout << "\n";
}

int main()
{
	Node* head = NULL;

	// head->1->2->3->4->5->6->NULL
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);

	cout << "Given Linked List\n";
	print(head);

	reverse(&head);
	cout << "Reversed Linked List\n";
	print(head);
	return 0;
}

/*
Time Complexity : O(N)

Auxiliary Space: O(N) for call stack
*/


