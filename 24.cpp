class Solution {
public:
    bool isPalindrome(ListNode* head) {
         ListNode* slow= head;
        stack <int> s;
  
        while(slow != NULL){
                s.push(slow->val);
 
                // Move ahead
                slow = slow->next;
        }
 
        while(head != NULL ){
             
             int i=s.top();
            s.pop();
 
             // Check if data is not
             // same as popped element
            if(head -> val != i){
                return false;
            }
 
            // Move ahead
           head=head->next;
        }
 
return true;
    }
};