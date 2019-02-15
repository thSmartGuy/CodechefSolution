#include <iostream>
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
bool solve(int l, int d, lld s, int c){
    if(s >= l) return true ;

    if(d == 0) return false ;

    return solve(l, d - 1, 1ll*(s + s*c), c) ;
}

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int l, d, s, c ;
    while(t--){
        std::cin >> l >> d >> s >> c ;

        std::cout << (solve(l, d - 1, (lld)s, c) ? "ALIVE AND KICKING\n" : "DEAD AND ROTTING\n") ;
    }
}

