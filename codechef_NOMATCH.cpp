#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int arr[n] ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + n) ;

        lld max_ = 0 ;

        for(int i = 0 ; i < n/2 ; i++){
            max_ += arr[n - i - 1] - arr[i] ;
        }

        std::cout << max_ << "\n" ;
    }
}
