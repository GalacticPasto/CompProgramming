#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> alternateNumbers(std::vector<int>&a) {
    std::unordered_set<int> set;
    for(int i : a){
        set.insert(i);
    }
    int i = 0;
    for(std::unordered_set<int>::iterator it = set.begin(); it != set.end(); it++){
        if((*it) > 0 && i < a.size()){
            a[i] = *it;
            i+=2;
        }
    }
    i = 1;
    for(std::unordered_set<int>::iterator it = set.begin(); it != set.end(); it++){
        if((*it) < 0 && i < a.size()){
            a[i] = *it;
            i +=2;
        }
    }
}
