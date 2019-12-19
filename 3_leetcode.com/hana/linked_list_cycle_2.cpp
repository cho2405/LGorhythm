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
        
        ListNode *curNode = head;
        ListNode *result = NULL;
        while(curNode!= NULL) {
            ListNode *nextNode = curNode->next;
         
            while(nextNode != NULL) {
                
                //cout << curNode->val<< "->" << nextNode->val<< endl;
                nextNode = nextNode->next;
                if(nextNode == NULL) {
                    result = NULL;
                    break;
                }
                if(nextNode == head) {
                    result = head;
                    cout << "^^" << endl;
                    break;
                }
                if(nextNode ==curNode->next) {
                    cout << "??" << endl;
                    result = nextNode;
                    break;

                }
            }
            if(result != NULL) break;
            curNode = curNode->next;
        }
        //cout << result->val << endl;
        return result;
    }
};
