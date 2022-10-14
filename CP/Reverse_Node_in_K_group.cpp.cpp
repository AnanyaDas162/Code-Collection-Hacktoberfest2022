//Recursive Solution

//Function for finding length of a node
int getLength(ListNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}


ListNode* ReverseList(ListNode *head, int k, int length)
{

   	//Base case 
    if (length < k) return head;

   	//step 1 -> reverse first k element
    ListNode *previous = NULL;
    ListNode *current = head;
    ListNode *forward = NULL;
    int count = 0;

    while ((current != NULL) && (count < k))
    {
        forward = current->next;
        current->next = previous;

       	// 1 step sabhi ko aage badhaoo
        previous = current;
        current = forward;
        count++;
    }

   	//Step 2 -> Make a recursive call if node is avilable after k

    if (forward != NULL)
    {
        head->next = ReverseList(forward, k, length - k);
    }

   	//step 3 -> return previous beacuse eventually our previous become head of given Node
    return previous;
}


class Solution
{
    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            int length = getLength(head);
            return ReverseList(head, k, length);
        }
};
