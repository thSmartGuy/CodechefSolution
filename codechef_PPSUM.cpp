#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

void print(lld a) {std::cout << a << "\n" ;}

// CODE FROM HERE

lld sum(int n){
    lld a = 1ll*n*(n + 1)/2 ;
    return a ;
}

int main(){
    // fast ;

    int t, d, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> d >> n ;

        lld ans = n ;
        while(d--){
            ans = sum(ans) ;
        }

        print(ans) ;
    }
}

