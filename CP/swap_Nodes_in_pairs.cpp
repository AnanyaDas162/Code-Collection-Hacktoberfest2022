class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* sol = head->next;
        ListNode* prev = NULL;
        while(head->next && head->next->next)
        {
            //cout<<head->val<<" ";
            if(prev)
                prev->next = head->next;
            ListNode* temp = head->next->next;
            head->next->next = head;
            head->next = temp;
            prev = head;
            head = head->next;
        }
        
        //for last node or two node case
        if(head->next)
        {
            ListNode* temp = head->next;
            temp->next= head;
            head->next = NULL;
            if(prev)
                prev->next = temp;
        }
        return sol;
        
    }
};
