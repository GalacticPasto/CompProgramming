#include <iostream>
#include <vector>
#include <stack>

// 3 1 2 4
int subarrayMins(std::vector<int>& arr){ // O(n^2)
    int ans = 0;
    int n = arr.size(); 

    for(int i = 0 ; i < n ; i++){
        int min = arr[i];
        ans += min;
        for(int j = i + 1; j < n ; j++){
            min = std::min(arr[j],min);
            ans += min;
        }
    } 
    return ans;
}

int subarrayMinsOptimized(std::vector<int>& arr){
    int ans = 0;
    int n = arr.size();
    std::stack<int> st;
    std::vector<int> left(n,0),right(n,0);
    
    left[0] = 1;
    st.push(0);
    for(int i = 1 ; i < n ; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            left[i] = i+1;
        }
        else{
            left[i] = i - st.top();
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    right[n-1] = 1;
    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            right[i] = n-i;
        }
        else{
            right[i] = st.top() - i;
        }
        st.push(i);
    }
    
    for(int i = 0 ; i < n ; i++){
        ans += (arr[i] * left[i] * right[i]);
    }
    return ans;
}


int main(){
    std::vector<int> arr = {71,55,82,55};
    //std::vector<int> arr = {3,1,2,4};
    std::cout <<subarrayMinsOptimized(arr) << "\n";
}
