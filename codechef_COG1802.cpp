#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int p[MAX], h[MAX] ;
lld real_p[MAX], real_h[MAX] ;

int main(){
    // fast ;

    int n, q, r ;

    std::cin >> n ;

    lld l = 0 ;
    FOR(i, 0, n){
        std::cin >> p[i] >> h[i] ;
        real_p[i] = 1ll*p[i]*h[i] ;
        real_h[i] = l + h[i] ;
        l = real_h[i] ;
    }

    FOR(i, 0, n){
        std::cout << p[i] << " " ;
    }
    std::cout << "\n" ;

    FOR(i, 0, n){
        std::cout << h[i] << " " ;
    }
    std::cout << "\n" ;

    FOR(i, 0, n){
        std::cout << real_h[i] << " " ;
    }
    std::cout << "\n" ;

    std::cin >> q ;

    while(q--){
        std::cin >> l >> r ;

        auto L = std::lower_bound(real_h, real_h + n, l) - real_h ;
        auto R = std::lower_bound(real_h, real_h + n, r) - real_h ;
        std::cout << "L: " << lowerL << " R:" << lowerR << "\n" ;

        std::cout << real_p[R - 1] - real_p[L - 1] ;
    }
}
