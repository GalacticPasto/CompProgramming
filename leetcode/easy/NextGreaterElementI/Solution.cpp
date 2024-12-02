#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
class Solution{
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1,std::vector<int>& nums2){
        std::stack<int> st; 
        std::unordered_map<int,int>map;
        std::vector<int> ans;
        for(int i = nums2.size()-1 ; i >= 0 ; i--){
           if(!st.empty()){
               while(!st.empty() && st.top() < nums2[i]){
                    st.pop();
               }
               if(st.empty()){map[nums2[i]] = -1;}
               else {map[nums2[i]] = st.top();}
               st.push(nums2[i]);
           }else{
               st.push(nums2[i]);
               map[nums2[i]] = -1;
           }
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};

int main(){
    Solution solu;
    std::vector<int> nums1  ={4,1,2};
    std::vector<int> nums2  ={1,3,4,2};
    std::vector<int> ans = solu.nextGreaterElement(nums1,nums2);
    for(int i : ans){
        std::cout << i << "\n";
    }
}
