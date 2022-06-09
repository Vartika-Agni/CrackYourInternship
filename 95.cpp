class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, bool> track;
    ListNode* temp = head;
    while (temp) {
        if (track.find(temp->val) == track.end()) {
            cout << temp->val << " ";
        }
        track[temp->val] = true;
        temp = temp->next;
    }
        return head;
    }
};