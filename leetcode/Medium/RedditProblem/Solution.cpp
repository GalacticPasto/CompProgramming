#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string>> func(std::vector<std::vector<std::string>>& records){
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<int>> map;
    std::vector<std::string> enterOnly;
    std::vector<std::string> exitOnly;
    
    for(std::vector<std::string> ppl : records){
        if(map.find(ppl[0]) == map.end()){
            std::vector<int> enterAndExit(2);
            if(ppl[1] == "enter"){
                enterAndExit[0]++;
            }
            else{
                enterAndExit[1]++;
                exitOnly.push_back(ppl[0]);
            }
            map.insert(std::make_pair(ppl[0],enterAndExit));
        }
        else{
            std::unordered_map<std::string,std::vector<int>>::iterator pos = map.find(ppl[0]);
            if(ppl[1] == "enter"){
                pos->second[0]++;
                if(pos->second[0] > pos->second[1]){
                    enterOnly.push_back(pos->first);
                }
            }
            else{
                pos->second[1]++;
                if(pos->second[1] > pos->second[0]){
                    exitOnly.push_back(pos->first);
                }
            }
        }
    }
    result.push_back(enterOnly);
    result.push_back(exitOnly);
    return result;
}

int main(){
    std::vector<std::vector<std::string>> records = {{"Paul", "enter"},
        {"Pauline", "exit"},
        {"Paul", "enter"},
        {"Paul", "exit"},
        {"Martha", "exit"},
        {"Joe", "enter"},
        {"Martha", "enter"},
        {"Steve", "enter"},
        {"Martha", "exit"},
        {"Jennifer", "enter"},
        {"Joe", "enter"},
        {"Curtis", "exit"},
        {"Curtis", "enter"},
        {"Joe", "exit"},
        {"Martha", "enter"},
        {"Martha", "exit"},
        {"Jennifer", "exit"},
        {"Joe", "enter"},
        {"Joe", "enter"},
        {"Martha", "exit"},
        {"Joe", "exit"},
        {"Joe", "exit"}
    };
    std::vector<std::vector<std::string>> result = func(records);
    for(std::vector<std::string> record : result){
        for(std::string st : record){
            std::cout << st << " " ; 
        }
        std::cout << "\n";
    } 
}
