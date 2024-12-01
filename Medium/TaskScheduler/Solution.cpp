#include <iostream>
#include <vector>
#include <queue>

int leastInterval(std::vector<char>& tasks, int n){
    std::priority_queue<int> queue; 
    char count[27];

    for(char c : tasks){
        count[c-'A']++;
    }
    
    for(int i = 0 ; i < count.size(); i++){
        if(count[i] > 0){
            queue.push(count[i]);
        }
    }

    int time = 0; 
    while(!queue.empty()){
        std::vector<int> remain;
        int cycles = n+1;
        while(cycles && !queue.empty()){
            int maxFreq = pq.top();
            pq.pop();        
            if(pq.top() > 1){
                remain.push_back(maxFreq-1);
            }
            cycles--;
            time++;
        }
        for(int x: remain){
            queue.push(x);
        }
        if(queue.empty())break;
        time += cycle;
    }
    return time;
    char count[27];

    for(char c : tasks){
        count[c-'A']++;
    }
    
    for(int i = 0 ; i < count.size(); i++){
        if(count[i] > 0){
            queue.push(count[i]);
        }
    }

    int time = 0; 
    while(!queue.empty()){
        std::vector<int> remain;
        int cycles = n+1;
        while(cycles && !queue.empty()){
            int maxFreq = pq.top();
            pq.pop();        
            if(pq.top() > 1){
                remain.push_back(maxFreq-1);
            }
            cycles--;
            time++;
        }
        for(int x: remain){
            queue.push(x);
        }
        if(queue.empty())break;
        time += cycle;
    }
    return time;
}

int main(){
    std::vector<int> tasks ={"A","A","A","A","A","A","B","C","D","E","F","G"}
    std::cout << leastInerval(tasks,2) << "\n";
    return 0;
}
