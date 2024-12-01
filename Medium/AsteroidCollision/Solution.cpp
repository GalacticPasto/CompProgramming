#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

class Solution{
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids){
       std::stack<int> st;
       
        for(int i = 0 ; i < asteroids.size() ; i++){
            bool same = false;
            while(!st.empty() && (std::abs(asteroids[i]) <= std::abs(st.top()) 
                || std::abs(asteroids[i]) >= std::abs(st.top()))){
                if(asteroids[i] < 0 && st.top() < 0 || asteroids[i] > 0 && st.top() > 0 || st.top() < 0 && asteroids[i] > 0){
                    st.push(asteroids[i]);
                    break;
                }
                else if(std::abs(asteroids[i]) >= std::abs(st.top())){
                    if(std::abs(asteroids[i]) == std::abs(st.top())){
                        same = true;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty() && !same)st.push(asteroids[i]);    
        }
        std::vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    //std::vector<int> arr = {10,2,-5};
    std::vector<int> arr = {-10,-2,-5};
    Solution solu;
    solu.asteroidCollision(arr);
}
