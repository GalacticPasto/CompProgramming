#include <iostream>

bool checkValidString(std::string s){
    int left = 0;
    int right = 0;

    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '(' || s[i] == '*'){
            left++;
        }
        else{
            left--;
        }
        if(left < 0) return false;
    }
    if(left == 0) return true;
    for(int i = s.size()-1 ; i >= 0; i--){
        if(s[i] == ')' || s[i] == '*'){
            right++;
        }
        else{
            right--;
        }
        if(right < 0) return false;
    }
    return true;
}

int main(){
    std::string s = "(*)";
    printf("\n");
    printf("%b ",checkValidString(s));
}
