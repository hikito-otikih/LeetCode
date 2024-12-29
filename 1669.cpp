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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tailList2 = list2, *temp = list1;
        while (tailList2 -> next != NULL) tailList2 = tailList2 -> next;
        for (int i = 1; i < a; i ++) list1 = list1 -> next;
        ListNode *dd = list1 -> next;
        list1 -> next = list2;
        list1 = dd;
        for (int i = a; i <= b; i ++) list1 = list1 -> next;
        tailList2 -> next = list1;
        return temp;
    }
};