// 1721. Swapping Nodes in a Linked List

// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

// Solution

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
    
    void insert(ListNode** root,int item)
    {
         ListNode *temp = new ListNode;
         temp->val = item;
         temp->next = *root;
         *root = temp;
    }
    
     ListNode* arrayToList(vector<int> a,int n){
         ListNode *root = NULL;
         for(int i=0;i<n;i++)
         {
             insert(&root,a[i]);
         }
         return root;
     }
    
    vector<int> llTraversal(ListNode* head)
    {
        vector<int> a;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            a.push_back(curr->val);
            curr = curr -> next;
        }
        return a;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> a = llTraversal(head);
        
        reverse(a.begin(),a.end());
        
        int x = a[k-1];
        int y = a[a.size()-k];
        
        a[k-1] = y;
        a[a.size()-k] = x;
        
        return arrayToList(a,a.size());
        
    }
};