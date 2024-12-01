#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
    public:
        Node* copyRandomList(Node* head){
            std::unordered_map<Node*, Node*> map;
            
            Node* copyPrev = nullptr;
            Node* copy= nullptr;
            Node* dummy = head; 
            while(dummy != nullptr){
                Node* node = new Node(dummy->val);
                map[dummy] = node;
                dummy = dummy->next;
            }
            dummy = head;
            while(dummy != nullptr){
                map[dummy]->next = map[dummy->next];
                map[dummy]->random= map[dummy->random];
                dummy = dummy->next;
            }
            return map[head];
        }
};

int main(){
    Solution solu;
    Node* node = new Node(7);
    Node* node1 = new Node(13);
    Node* node2 = new Node(11);
    Node* node3 = new Node(10);
    Node* node4 = new Node(1);
    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    solu.copyRandomList(node);

}
