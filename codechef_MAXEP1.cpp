#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

int need(int low, int high){
    int n = 1 ;

    while(n*(n + 1)/2 < high - low + 1){
        n++ ;
    }

    return n ;
}

int main(){
    // fast ;

    int n, c ;

    std::cin >> n >> c ;

    int broken ;

    int high = n, low = 1 ;

    int x = 0 ;

    int k = need(low, high) ;
    for(int i = low + k - 1 ; i <= high ; i += k){
        std::cout << "1 " << i << std::endl ;
        std::cin >> broken ;

        if(broken == 1){
            high = i - 1 ;
            std::cout << "2" << std::endl ;
            break ;
        }
        else if(broken == 0){
            low = i ;
            x = i ;
            k-- ;
        }
        else{
            break ;
        }
    }

    FOR(i, low, high + 1){
        std::cout << "1 " << i << std::endl ; // std::endl for flush
        std::cin >> broken ;

        if(broken == 0){
            x = i ;
        }
        else if(broken == 1){
            break ;
        }
    }

    std::cout << "3 " << x + 1 << std::endl ;
}

