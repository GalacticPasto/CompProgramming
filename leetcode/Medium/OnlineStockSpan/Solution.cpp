#include <iostream>
#include <vector>
#include <stack>

class StockSpanner{
    std::stack<std::pair<int,int>>* st;
public:
    StockSpanner(){
        st = new std::stack<std::pair<int,int>>;
    }
    int next(int price){
        if(st->empty()){
            st->push({price,1});
        }
        else if(st->top().first <= price){
            int count = 0;
            while(!st->empty() && st->top().first <= price){
                count += st->top().second;
                st->pop();
            }
            st->push({price,count + 1});
        }
        else{
            st->push({price,1});
        }
        return st->top().second;
    }
};
/*class StockSpanner{
public:
    std::vector<std::pair<int,int>>* v;
    StockSpanner(){
        v = new std::vector<std::pair<int,int>>;
    }
    int next(int price){
        if(v->empty()){
            v->push_back({price,1});
        }
        else if(price < v->back().first){
            v->push_back({price,1});
        }
        else{
            int size = v->size();
            int count = 0;
            std::vector<std::pair<int,int>>::reverse_iterator  it = v->rbegin();
            while(it != v->rend() && it->first <= price){
                count++;
                it++;
            }
            v->push_back({price,count + 1});
        }
        return v->back().second;
    }
};*/

int main(){
    StockSpanner *stockSpanner = new StockSpanner();
    std::cout << stockSpanner->next(100)<< "\n"; // return 1
    std::cout << stockSpanner->next(80) << "\n";// return 1
    std::cout << stockSpanner->next(60) << "\n";// return 1
    std::cout << stockSpanner->next(70) << "\n";// return 2
    std::cout << stockSpanner->next(60) << "\n";// return 1
    std::cout << stockSpanner->next(75) << "\n";// return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    std::cout << stockSpanner->next(85) << "\n";// return 6
}

