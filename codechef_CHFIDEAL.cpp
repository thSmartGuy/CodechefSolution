#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast ;

    int x[4] = {} ;

    x[1] = 1 ;
    int temp ;
    std::cout << "1" << std::endl ;
    std::cin >> temp ;

    x[temp] = 1 ;

    FOR(i, 1, 4){
        if(!x[i]){
            std::cout << i << std::endl ;
            break ;
        }
    }
}

