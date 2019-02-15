#include <iostream>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    lld n ;

    std::cin >> n ;
    lld i ;
    for(i = 0 ; i < LLONG_MAX ; i++){
        if((lld)i*(i + 1)/2 > n){
            break ;
        }
    }

    std::cout << i - 1 ;
}

