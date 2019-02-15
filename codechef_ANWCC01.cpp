#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast() ;

    int t ;

    std::cin >> t ;

    int n ;
    while(t--){
        std::cin >> n ;

        lld ans = n/2 ;
        ans = std::min(ans, 1ll*4) ;
        print(ans) ;
    }
}

