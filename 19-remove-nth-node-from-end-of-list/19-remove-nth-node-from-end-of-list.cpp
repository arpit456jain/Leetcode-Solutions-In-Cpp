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
    int findlength(ListNode* head)
    {
        int length =0 ;
        ListNode *temp= head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        // cout<<length;
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = findlength(head);
        if(l == n)
        {
            head = head->next;
            return head;
        }
            
        int del = l - n - 1;
        cout<<del;
        ListNode* temp = head;
        while(del>0)
        {
            temp = temp->next;
            del--;
            
        }
        temp->next = temp->next->next;
        return head;
    }
};