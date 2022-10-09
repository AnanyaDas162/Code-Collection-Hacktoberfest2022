/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node)
{
	if (node == NULL)
		return 1;

	/* false if the max of the left is > than us */
	if (node->left != NULL
		&& maxValue(node->left) >= node->data)
		return 0;

	/* false if the min of the right is <= than us */
	if (node->right != NULL
		&& minValue(node->right) <= node->data)
		return 0;

	/* false if, recursively, the left or right is not a BST
	*/
	if (!isBST(node->left) || !isBST(node->right))
		return 0;

	/* passing all that, it's a BST */
	return 1;
}

// This code is contributed by shubhamsingh10
