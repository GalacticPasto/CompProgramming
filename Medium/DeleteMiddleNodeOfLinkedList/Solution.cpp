#include <iostream>
#include <vector>

class ListNode{
public:
    int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* deleteMiddleNode(ListNode* head){
        ListNode* fast= head;
        ListNode* slow= head;
        ListNode* prev = nullptr;
        
        while(fast != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        } 
        prev->next = prev->next->next;
        return head;
    }
};

