#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<std::string> generateString(int n){
        std::vector<std::string>result;
        std::string str;
        str.insert(0,n,'0');
        result.push_back(str);
        generate(result,str,0);
        return result;
    }


private:
    void generate(std::vector<std::string>& result,std::string& str,int indx){
        for(int i = indx ; i < str.size() ; i++){
            if(i == 0){
                str[i] = '1';
                result.push_back(str);
                generate(result,str,i+1);
                str[i] = '0';
            }
            else if(i > 0 && str[i-1] != '1'){
                str[i] = '1';
                result.push_back(str);
                generate(result,str,i+1);
                str[i] = '0';
            } 
        }
    } 
};

int main(){
    Solution solu;
    int n;
    std::cin >> n;
    std::vector<std::string> res = solu.generateString(n);
    for(std::string str : res){
        std::cout << str << " ";
    }
    std::cout << "\n";
}
