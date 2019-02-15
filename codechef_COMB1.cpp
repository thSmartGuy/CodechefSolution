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

lld ap(int n){
    return 1ll*(n + 1ll*n*(n - 1)) ;
}

int main(){
    // fast() ;

    int t ;

    std::cin >> t ;

    int l, r ;
    while(t--){
        std::cin >> l >> r ;

        if(l > 1)
            print(ap(r) - ap(l - 1)) ;
        else
            print(ap(r)) ;
    }
}

