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
    // fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int arr[n + 1] ;

        FOR(i, 1, n + 1) std::cin >> arr[i] ;

        int cum[n + 1] = {} ;

        FOR(i, 1, n + 1){
            if(arr[i] == 0)
                cum[i] += cum[i - 1] - 1 ;
            else
                cum[i] += cum[i - 1] + 1 ;
        }

        bool flag = 1 ;
        FOR(i, 1, n + 1) if(cum[i] < 0) flag = 0 ;

        std::cout << (flag ? "Valid\n" : "Invalid\n") ;
    }
}

