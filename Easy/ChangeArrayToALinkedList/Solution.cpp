#include <iostream>
#include <vector>

class Node{
public:
      int data;
      Node* next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node* next) : data(x), next(next) {}
};
class Solution{
public:
    Node* changeToLinkedList(std::vector<int> arr){

    }
private:
    void printList(Node* head){
        while(head != nullptr){
            std::cout << head->data << " "; 
            head = head->next;
        }
    }
};
int main(){
    std::vector<int> a = {1,2,3,4};
    Solution solu;
    solu.changeToLinkedList(a);
}
