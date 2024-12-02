#include <iostream>
#include <vector>

class Solution{
    bool hasCycle = false;
    public:
        bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){
            std::vector<std::vector<int>> graph = buildGraph(numCourses,prerequisites);    
            std::vector<bool> visited(numCourses);
            std::vector<bool> detectCycle(numCourses);

            for(int i = 0 ; i < numCourses; i++){
               if(!visited[i]){
                    dfs(graph,visited,detectCycle,i); 
               } 
            } 
            if(hasCycle){return false;}
            
            for(int i = 0 ; i < numCourses ;i++){
                if(visited[i] == false)return false;
            } 
            return true;
        } 
    private:
        std::vector<std::vector<int>> buildGraph(int numCourses, std::vector<std::vector<int>>& prerequisites){
            std::vector<std::vector<int>> graph(numCourses); 
            for(std::vector<int> vector : prerequisites){
                graph[vector[0]].push_back(vector[1]);
            } 
            return graph;
        }
        void dfs(std::vector<std::vector<int>>& graph,std::vector<bool>& visited,std::vector<bool>& detectCycle,int canITakeIt){
                visited[canITakeIt] = true; 
                detectCycle[canITakeIt] = true; 
                for(int required: graph[canITakeIt]){
                    if(hasCycle){
                        return;
                    }
                    else if(!visited[required]){
                        dfs(graph,visited,detectCycle,required);
                    }
                    else if(detectCycle[required]){
                        hasCycle = true;
                    }
                } 
                detectCycle[canITakeIt] = false;
        }

};
