#include <iostream>
#include <forward_list>
#include <unordered_map>

class LRUCache {
public:
    class node{
        public:
            int key;
            int value;
            node* next;
            node* prev;

            node(int key,int value){
                this->key = key; 
                this->value= value; 
            }
    };
    int size;
    std::unordered_map<int,node* >* map;
     
    node* head;
    node* tail;

    LRUCache(int capacity) {
        size = capacity;
        map = new std::unordered_map<int,node*>;
        head = new node(-1,-1);
        tail= new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(int key,int value){
        node* newnode = new node(key,value);
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
        if(map->find(key) != map->end()){
            node* nodeValue = (*map)[key];
            int val = nodeValue->value;
            map->erase(key);
            deleteNode(nodeValue);
            map->insert_or_assign(key,nodeValue);
            return val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(map->find(key) != map->end()){
           node* existNode = map->at(key); 
           map->erase(key);
           deleteNode(existNode);
        } 
        if(map->size() == size){
            map->erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(key,value); 
        map->insert_or_assign(key,head->next);
    }
};

int main(){
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    std::cout << lRUCache->get(1) << "\n";    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    std::cout << lRUCache->get(2) << "\n";    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    std::cout << lRUCache->get(1) << "\n";    // return -1 (not found)
    std::cout << lRUCache->get(3) << "\n";    // return 3
    std::cout << lRUCache->get(4) << "\n";    // return 4
}
