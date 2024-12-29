struct cmp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists)
        {
            if (list)
                pq.push(list);
        }
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next)
                pq.push(top->next);
        }
        return head->next;
    }
};