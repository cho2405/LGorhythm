/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f, *ff;
        f = ff = head;
                
        if (f == NULL) return NULL;
        
        while (true) {
            if (f->next == NULL || ff->next == NULL) return NULL;
            else {
                f = f->next;
                ff = ff->next;
            }
            
            if (ff->next == NULL) return NULL;
            else ff = ff->next;
            
            if (f == ff) {
                f = head;                
                while (f != ff) {
                    f = f->next;
                    ff = ff->next;
                }
                break;
            }
        }
        
        return f;
    }
};
