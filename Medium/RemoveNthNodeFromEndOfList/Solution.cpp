#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            int size = 0; 
            ListNode* fast= head;
            ListNode* slow = head;
            
            for(int i = 0; i <= n ; i++){
                fast= fast->next; 
            }
            while(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next= slow->next->next; 
            return head;
        }
    private:
        void printListNode(ListNode* head){
            while(head != NULL){
                std::cout << head->val << " ";
                head = head->next;
            }
            std::cout << "\n";
        }
};

int main(){
    ListNode fifth(5);
    ListNode fourth(4,&fifth);
    ListNode third(3,&fourth);
    ListNode second(2,&third);
    ListNode head(1,&second);

    Solution solu;
    solu.removeNthFromEnd(&head , 2);
}
