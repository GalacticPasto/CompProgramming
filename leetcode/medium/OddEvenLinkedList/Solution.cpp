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
    ListNode* oddEvenList(ListNode* head){
        printList(head);
        ListNode* dummy = head;
        ListNode* prev = head;
        ListNode* next = nullptr;
        ListNode* newHead = nullptr;
        ListNode* newDummy = nullptr;
        int count = 1;
        while(dummy != nullptr){
            if(count % 2 == 1){
                prev = dummy;
                dummy = dummy->next;
            }
            else{

                ListNode *node = new ListNode(dummy->val);
                if(newHead == nullptr){
                    newHead = node;
                    newDummy = newHead;
                }
                else{
                    newDummy->next = node;
                    newDummy = newDummy->next;
                }

                next = dummy->next;
                prev->next = next;
                dummy = next;
            }
            count++;
        }
        prev->next = newHead;
        return head;
    }
    void printList(ListNode* head){
        ListNode* dummy = head;
        while(dummy != nullptr){
            std::cout << dummy->val << " ";
            dummy = dummy->next;
        }
        std::cout << "\n";
    }
};

int main(){
    ListNode* fourth= new ListNode(5);
    ListNode* third= new ListNode(4,fourth);
    ListNode* second= new ListNode(3,third);
    ListNode* first= new ListNode(2,second);
    ListNode* head = new ListNode(1,first);
    Solution solu;
    solu.oddEvenList(head);
}
