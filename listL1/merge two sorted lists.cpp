

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;
        //traverse both the list simultaneously
        while(list1!=NULL && list2!=NULL)
        {
            //compare both the element
            if(list1->val < list2-> val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr)
        {
            temp->next=list1;
        }
        else
            temp->next =  list2;
        return (dummy->next);
    }
};

// DP


class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)
      return list1 ? list1 : list2;
    if (list1->val > list2->val)
      swap(list1, list2);
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};