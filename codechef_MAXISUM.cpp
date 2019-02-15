#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int t, n, k ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;
        lld A[n], B[n] ;

        FOR(i, 0, n) std::cin >> A[i] ;

        FOR(i, 0, n) std::cin >> B[i] ;

        lld sum = 0 ;

        FOR(i, 0, n){
            sum += 1LL*A[i]*B[i] ;
        }

        lld ans = sum, temp ;

        FOR(i, 0, n){
            temp = sum - 1LL*A[i]*B[i] ;

            A[i] += k ;
            temp += 1LL*A[i]*B[i] ;
            ans = std::max(ans, temp) ;

            temp -= 1LL*A[i]*B[i] ;

            A[i] -= 2*k ;
            temp += 1LL*A[i]*B[i] ;
            ans = std::max(ans, temp) ;

            A[i] += k ;
        }

        std::cout << ans << "\n" ;
    }
}

