#include <iostream>
#include <iomanip>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast ;

    int t ;
    double bas ;

    std::cin >> t ;

    while(t--){
        std::cin >> bas ;

        double hra = (bas >= 1500 ? 500 : 0.1 * bas) ;

        double da = (bas >= 1500 ? .98*bas : .9*bas) ;

        double ans = bas + da + hra ;

        std::cout << std::fixed << std::setprecision(3) << ans << "\n" ;
    }
}

