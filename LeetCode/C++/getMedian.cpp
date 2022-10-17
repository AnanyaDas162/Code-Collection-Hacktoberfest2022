private:
    double getMedian(ListNode* head) {
        if(head->next == NULL){
            return head->val;
        }
        else {
            ListNode * fast = head->next;
            ListNode * slow = head;
            while(fast != NULL){
                fast = fast->next;
                if(fast==NULL){
                    return (double)(slow->val + slow->next->val) / (double)2;
                }
                fast = fast->next;
                slow = slow->next;
            }

            return slow->val;
        }
    }

public:
    ListNode* head = NULL;
    ListNode* tail = NULL;
    MedianFinder() {
        // ListNode* head = NULL;
        // ListNode* tail = NULL;
    }
    
    void addNum(int num) {      

        ListNode* node = new ListNode(num);
        //empty list
        if(head == NULL) {
            head = node;
            tail = node;
            return;
        }

        //one node
        else if(head->next == NULL){
            if(head->val <= num){
                head->next = node;
                tail = node;
            }else{
                node->next = head;
                head = node;
                tail = node->next;
            }
        }

        //multiple node
        else if(tail->val <= num){
            tail->next = node;
            tail = node;
        }

        else{
            if(tail->val > num && head->val >= num){
                node->next = head;
                head = node;
            }else{
                ListNode * curr = head->next;
                ListNode * prev = head;

                while(curr!=NULL){
                    if(curr->val >= num){
                        prev->next = node;
                        node->next = curr;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
    
    double findMedian() {
        return getMedian(head);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
