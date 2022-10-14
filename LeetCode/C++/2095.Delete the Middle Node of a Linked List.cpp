class Solution {
public:
    int sze(ListNode* head)
    {
        int cnt=0;
        while(head)
        {
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int size=sze(head);
        if(size==1)
            return  NULL;
        ListNode* temp=head;
        size=(size/2)-1;
        while(size--)
            temp=temp->next;
        temp->next=temp->next->next;
        return head;
    }
};
