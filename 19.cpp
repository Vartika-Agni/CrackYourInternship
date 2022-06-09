class Solution {
public:
    ListNode* removeElements(ListNode* head, int x) {
        if (!head)
        return head;
    // Until the head data is equal to the key move the head
    // pointer
    while (head && head->val == x)
        head = head->next;
    ListNode *curr = head, *prev = nullptr;
 
    while (curr) {
        if (curr->val == x)
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }
    return head;
    }
};