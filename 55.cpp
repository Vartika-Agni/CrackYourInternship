class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        if(head->next==NULL) return NULL;
        
        ListNode *tortoise=head; 
        ListNode *hare=head; 
        while(tortoise!=NULL && hare!=NULL && hare->next!=NULL){
            tortoise=tortoise->next;
            hare=hare->next->next;
             if(tortoise==hare) 
            break;
    }
       
        
         if(tortoise!=hare) return NULL;
    
        tortoise=head;

   while(tortoise!=hare)
   {
    tortoise=tortoise->next;
    hare=hare->next;
   }
        return tortoise;
        }
   
   
    
};