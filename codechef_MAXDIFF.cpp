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
        int arr[n] ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + n) ;

        lld sum1 = 0, sum2 = 0 ;

        FOR(i, 0, k){
            sum1 += arr[i] ;
        }

        FOR(i, k, n){
            sum2 += arr[i] ;
        }

        lld ans = std::abs(sum2 - sum1) ;
        sum1 = 0 ; sum2 = 0 ;

        std::reverse(arr, arr + n) ;

        FOR(i, 0, k){
            sum1 += arr[i] ;
        }

        FOR(i, k, n){
            sum2 += arr[i] ;
        }

        ans = std::max(ans, std::abs(sum2 - sum1)) ;

        std::cout << ans << "\n" ;
    }
}

