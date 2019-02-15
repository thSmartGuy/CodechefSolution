#include <iostream>

int main(){
    int t, flag = 1 ;
    while(std::cin >> t){
        if(t == 42)
            flag = 0 ;
        if(flag)
            std::cout << t << "\n" ;
    }
}
