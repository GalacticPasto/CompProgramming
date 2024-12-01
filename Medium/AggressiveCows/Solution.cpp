#include <iostream>
#include <vector>
#include <unordered_map>
class Solution{
public:
    int aggressiveCows(std::vector<int>& stalls,int k){
        int ans = 0;
        for(int i = 1 ; i < stalls.size(); i++){
            bool yes = isPossible(stalls,k,i);
            if(yes){
                ans = i;
            }
            else{
                break;
            }
        }
        return ans;
    } 
private:
    bool isPossible(std::vector<int>& stalls,int noOfCows,int spacing){
        int cows = 1;
        int last = stalls[0];
        for(int i = 1; i < stalls.size() ; i++){
            if(stalls[i] - last >= spacing){
                cows++;
                last = stalls[i];
            }
        }
        return (cows >= noOfCows);
    }
};

int main(){
    Solution solu;
    std::vector<int> cows = {0,3,4,7,10,9};
    std::cout << solu.aggressiveCows(cows,4) << "\n";
}
