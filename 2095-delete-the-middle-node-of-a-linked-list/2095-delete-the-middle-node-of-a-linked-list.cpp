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
    int getlen(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    void deleteNode(ListNode* node) {
        // swap the value and delete the next node
        ListNode* temp = node->next;
        int data = node->val;
        node->val = temp->val;
        temp->val = data;
        
        node->next = temp->next;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int n = getlen(head);
        if(n==1)
            return NULL;
        int pos = n/2;
        int pos2 = pos;
        // cout<<"node to be deleted "<<n;
        ListNode* temp = head;
        ListNode* prev=head;
        while(pos>0)
        {
            prev = temp;
            temp = temp->next;
            pos--;
        }
        
        if(pos2>0 and pos2<n-1)
        deleteNode(temp);
        else if(pos2 == n-1)
        prev->next = NULL;
            
        return head;
    }
};