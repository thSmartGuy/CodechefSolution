#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    //fast ;
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int ans = 0, temp ;
        FOR(i, 0, n){
            std::cin >> temp ;
            ans ^= 2*temp ;
        }

        std::cout << ans << "\n" ;
    }
}

