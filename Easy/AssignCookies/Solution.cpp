#includue <iostream>
#include <unordered_set>
int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    int ans = 0;
    std::unordered_map<int,int> map;

    for(int i = 0 ; i < g.size(); i++){
        map[g[i]]++:
    }

    for(int i = 0 ; i < s.size(); i++){
        if(map.find(s[i]) != map.end()){
            map[s[i]]--;
            if(map[s[i]] == 0){
                map.earase[s[i]];
            }
            ans++;
        }
    }
    return ans;
}

int main(){

}
