class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;

        ListNode* prev = head;
        ListNode* forward = head;
        int ctr = 0;

        while(forward!=NULL){
            if(ctr>n){
                prev = prev->next;
            }
            ctr++;
            forward = forward->next;
        }

        if(prev==head && ctr==n){
            return head->next;
        }

        ListNode* temp = prev->next;
        prev->next = prev->next->next;
        temp->next = NULL;

        return head;


    }
};