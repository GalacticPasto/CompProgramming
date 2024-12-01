#include <iostream>
#include <vector>
#include <unordered_set>

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA , ListNode* headB){
        std::unordered_set<ListNode*> set; 
        ListNode* dummyA = headA;
        ListNode* dummyB = headB;

        while(dummyA != nullptr && dummyB != nullptr){
            if(set.find(dummyA) != set.end())return dummyA;
            if(set.find(dummyB) != set.end())return dummyA;
            set.insert(dummyA);
            set.insert(dummyB);
            dummyA = dummyA->next;
            dummyB = dummyB->next;
        }
        return nullptr;
    }
};

int main(){
    std::cout << std::isalpha('.') << " ";
}
