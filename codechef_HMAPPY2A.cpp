#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
     fast() ;

    int t ;
    lld a, b, k, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> a >> b >> k ;

        lld ans = (n/a) ;
        ans += (n/b) ;
        lld o = (a*b/gcd(a, b)) ;
        ans -= 2*(n/o) ;

        print(ans >= k ? "Win" : "Lose") ;
    }
}

