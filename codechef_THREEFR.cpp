#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    int k, t ; //, x, y, z ;
    int x[3] ;

    std::cin >> t ;

    int c1, c2, b1, b2, b3, b4, a1, a2, a3, a4, a5, a6, a7, a8 ;
    while(t--){
        std::cin >> x[0] >> x[1] >> x[2] ;

        std::sort(x, x + 3) ;

        if(x[0] + x[1] == x[2]){
            std::cout << "yes\n" ;
        }
        else{
            std::cout << "no\n" ;
        }
    }
}

