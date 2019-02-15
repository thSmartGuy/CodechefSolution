#include <iostream>

int main(){
    int t, flag, n, k ;
    std::cin >> t ;
    std::string lap ;
    while(t--> 0){
        flag = 1 ;
        std::cin >> lap ;
        n = lap.size() ;
        int l[26] = {}, r[26] = {};

        for(int i = 0 ; i < n /2 ; i++){
            l['z' - lap[i]]++ ;
        }

        for(int i = (n+1)/2 ; i < n ; i++){
            r['z' - lap[i]]++ ;
        }

        flag = 1 ;

        for(int i = 0 ; i < 26 ; i++){
            if(l[i] != r[i]){
                flag = 0 ;
                std::cout << "NO\n" ;
                break ;
            }
        }

        if(flag){
            std::cout << "YES\n" ;
        }
    }
}
