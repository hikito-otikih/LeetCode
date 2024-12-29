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
        if (!head) return head;
        ListNode *temp = head, *d = head;
        int preVal = head -> val;
        head = head -> next;
        while (head != NULL)
        {
            if (preVal < head -> val) 
            {
                preVal = head -> val;
                d -> next = head;
                d = d -> next;
            }
            head = head -> next;
        }
        d -> next = NULL;
        return temp;
    }
};