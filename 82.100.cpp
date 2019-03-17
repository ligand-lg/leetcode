typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *my_head = new ListNode(0);
    my_head->next = head;
    ListNode *pre = my_head;
    ListNode *current = head; // pre != current
    while (current && current->next)
    {
      if (current->val != current->next->val)
      {
        pre = current;
        current = current->next;
      }
      else
      {
        int val = current->val;
        while (current && current->val == val)
        {
          current = current->next;
          ;
        }
        pre->next = current;
      }
    }
    return my_head->next;
  }
};