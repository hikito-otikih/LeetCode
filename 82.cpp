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
        ListNode *ans = new ListNode(), *res = ans, *prevPtr = NULL;
        int prev = -1e9;
        while (head)
        {   
            if (prev < head -> val)
            {
                prevPtr = res;
                res -> next = head;
                res = res -> next;
                prev = head -> val;
            }
            else
            {
                if (prevPtr != NULL)
                {
                    res = prevPtr;
                    prevPtr = NULL;
                }
            }
            head = head -> next;
        }
        res -> next = NULL;
        return ans -> next;
    }
};