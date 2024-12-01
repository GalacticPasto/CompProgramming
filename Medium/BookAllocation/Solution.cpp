#include <iostream>
#include <vector>
#include <numeric>
class Solution{
public:
    int findPages(std::vector<int>& arr,int n, int m){

        int max = std::accumulate(arr.begin(),arr.end(),0);
        int min = *(std::max_element(arr.begin(),arr.end())); 
        
        int ans = 0;
        for(int i = min ; i <= max ; i++){
            bool possible = isPossible(arr,m,i);
            if(possible){
                continue;
            }
            else{
                ans = i;
                break;
            }
        }
        return ans; 
    }
private:
    bool isPossible(std::vector<int>& arr,int noOfStudents,int noOfPages){
        int sum = 0;
        int students = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(sum + arr[i] > noOfPages){
                students++; 
                sum = arr[i];
            }
            else{
                sum +=arr[i];
            }
        }
        return (students>= noOfStudents);
    }
};

int main(){
    std::vector<int> arr = {12,34,67,90};
    Solution solu;
    std::cout << solu.findPages(arr,arr.size(),2) << "\n";
}
