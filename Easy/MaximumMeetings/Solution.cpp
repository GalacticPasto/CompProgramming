#include <iostream>
#include <vector>

bool comparator(std::pair<int,int>& a, std::pair<int,int>& b){
    return (a.second < b.second);
}

int maximumMeetings(std::vector<int>& start, std::vector<int>& end){
    int ans= 0;
    int n = start.size();
    std::vector<std::pair<int,int>> meetings;
    
    for(int i = 0 ; i < n ; i++){
        meetings.push_back({start[i],end[i]});
    }
    std::sort(meetings.begin(),meetings.end(),comparator); 
    
    int last = meetings[0].second;
    for(int i = 0 ; i < n ; i++){
        if(last < meetings[i].first){
            ans++;
            last = meetings[i].second;
        }
    }
    return ans;
}

int main(){
    std::vector<int>start = {1,3,0,5,8,5};
    std::vector<int>end = { 2,4,6,7,9,9}; 
    printf("%d\n",maximumMeetings(start,end));
}
