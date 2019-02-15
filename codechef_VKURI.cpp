#include <iostream>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    lld n ;
// BASED ON TRIANGULAR NUMBERS
    std::cin >> n ;
    for(lld i = 0 ; i < LLONG_MAX ; i++){
        if(i > n){
            std::cout << i - 1 ;
            break ;
        }
        else{
            n -= i ;
        }
    }
}
