class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = new ListNode(), *odd = oddHead;
        ListNode *evenHead = new ListNode(), *even = evenHead;
        while (head && head -> next)
        {
            odd -> next = head;
            head = head -> next;
            odd = odd -> next;

            even -> next = head;
            head = head -> next;
            even = even -> next;
        }
        if (head) 
        {
            odd -> next = head;
            odd = odd -> next;
        }
        odd -> next = evenHead -> next;
        even -> next = NULL;
        return oddHead -> next;
    }
};