class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;

        for (ListNode *n1 = l1, *n2 = l2; (n1 != NULL) || (n2 != NULL);) {
            int v1 = n1 ? n1->val : 0;
            int v2 = n2 ? n2->val : 0;

            int sum = v1 + v2 + (carry ? 1 : 0);
            ptr->next = new ListNode(sum % 10);
            carry = sum / 10;

            n1 = n1 ? n1->next : NULL;
            n2 = n2 ? n2->next : NULL;
            ptr = ptr->next;
        }

        if (carry) {
            ptr->next = new ListNode(1);
        }


        return head->next ? head->next : head;
    }
};


// optimized

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return auxWithCarry(l1, l2, 0);
    }

    ListNode* auxWithCarry(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == NULL && l2 == NULL && carry == 0)
            return NULL;

        int sum = carry;
        if (l1 != NULL)
            sum += l1->val;
        if (l2 != NULL)
            sum += l2->val;

        return new ListNode(sum % 10, auxWithCarry((l1 == NULL)? NULL : l1->next, (l2 == NULL)? NULL : l2->next, sum / 10));
    }
};