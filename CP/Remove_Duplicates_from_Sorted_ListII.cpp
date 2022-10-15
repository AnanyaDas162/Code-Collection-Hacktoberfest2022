//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
     ListNode* ptr = head, *prev;
        
        while(ptr!=NULL && ptr->next!=NULL){
            int v = ptr->val;
            if(ptr->next->val == v){
                while(ptr->next!=NULL && ptr->next->val == v)
                    ptr = ptr->next;
                
                if(v == head->val){//starts with duplicate values
                    head = ptr->next;
                   // prev = head;
                }
                else
                    prev->next = ptr->next;
            }
            else prev = ptr;
            ptr = ptr->next;
        }
        
        return head;
             
        
    }
};