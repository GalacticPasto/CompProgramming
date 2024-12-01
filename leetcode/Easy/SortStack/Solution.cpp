#include <iostream>
#include <vector>
#include <stack>
class Solution{
public:
    void sortStack(std::stack<int>& stack){
        sort(stack); 
        while(!stack.empty()){
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << "\n";
    }
private:
    void sort(std::stack<int>& stack){
        int num = stack.top();
        stack.pop();
        if(!stack.empty())sort(stack);
        
        if(stack.empty()){
            stack.push(num);
        }
        else{
            std::vector<int> nums;
            while(num < stack.top()){
                nums.push_back(stack.top());
                stack.pop();
            }
            stack.push(num);
            for(int i = 0 ; i < nums.size() ; i++){
                stack.push(nums[i]);
            }
        }
    }
};

int main(){
    std::stack<int> stack;
    int num = 0;
    while(true){
        std::cin >> num;
        if(num == -1)break;
        stack.push(num);
    }
    Solution solu;
    solu.sortStack(stack);
}
