#include <iostream>
#include <iomanip>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    int t ;
    lld q, p ;

    std::cin >> t ;

    while(t--){
        std::cin >> q >> p ;

        if(q <= 1000){
            std::cout << std::fixed << std::setprecision(6) << (double)q*p << "\n" ;
        }
        else{
            std::cout << std::fixed << std::setprecision(6) << (double)0.9*q*p << "\n" ;
        }
    }
}

