#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

std::vector <int> a, b ;

int main(){
    // fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        a.clear() ; a.resize(n) ;
        b.clear() ; b.resize(n) ;

        FOR(i, 0, n) std::cin >> a[i] ;

        FOR(i, 0, n) std::cin >> b[i] ;

        std::sort(a.begin(), a.end()) ;
        std::sort(b.begin(), b.end()) ;

        std::reverse(b.begin(), b.end()) ;

        lld ans = 0 ;

        FOR(i, 0, n){
            ans += a[i]*b[i] ;
        }

        std::cout << ans << "\n" ;
    }
}

