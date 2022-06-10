class Solution {
public:
    int _getIntesectionNode(int d, ListNode* head1, ListNode* head2);
        int getCount(ListNode* head);

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
        
int _getIntesectionNode(int d, ListNode* head1, ListNode* head2)
{
    ListNode* current1 = head1;
    ListNode* current2 = head2;

    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
             return -1;
        }
        current1 = current1->next;
    }
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
        
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
    }
 
int getCount(ListNode* head)
{
    ListNode* current = head;
 
    // Counter to store count of nodes
    int count = 0;
 
    // Iterate till NULL
    while (current != NULL) {
 
        // Increase the counter
        count++;
 
        // Move the Node ahead
        current = current->next;
    }
     return count;
}
    }
};