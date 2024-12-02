#include <iostream>

int countSetBits(int n){
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        int mask = 1;
        int set = 0;
        while(mask <= i){
            if((i & mask) > 0)set++;
            mask = mask << 1;
        }
        std::cout << i << ":" << set << "\n";
        count += set;
    }
    return count;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << countSetBits(n) << "\n";
}
