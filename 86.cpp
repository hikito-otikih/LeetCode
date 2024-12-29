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
    ListNode* partition(ListNode* head, int x) {
        ListNode *LeftPart = new ListNode(), *RightPart = new ListNode();
        ListNode *tempLeft = LeftPart, *tempRight = RightPart;
        while (head)
        {
            if (head -> val < x) 
            {
                LeftPart -> next = head;
                LeftPart = LeftPart -> next;
            }
            else
            {
                RightPart -> next = head;
                RightPart = RightPart -> next;
            }
            head = head -> next;
        }
        LeftPart -> next = tempRight -> next;
        RightPart -> next = NULL;
        return tempLeft -> next;
    }
};