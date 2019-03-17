typedef struct ListNode {
  int val;
  ListNode *next;
} ListNode;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head)  {
    if (!head) 
      return head;
    ListNode *p = head, *q = head->next;
    while(q) {
      if (p->val != q->val){
        p->next = q;
        p = q;
      }
      q = q->next;
    }
    p->next = NULL;
    return head;
  }
};
