#include <iostream>
#include <vector>
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
     fast() ;

    int t, n, k, tmp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;

        int gc = 0 ;
        FOR(i, 0, n){
            std::cin >> tmp ;

            gc = gcd(gc, tmp) ;
        }

        int primemax = 1 ;
        FOR(i, 2, std::sqrt(gc) + 1){
            while(gc%i == 0){
                gc /= i ;
                primemax = std::max(primemax, i) ; // LARGEST I WHICH DIVIDES ALL
            }
        }
        primemax = std::max(primemax, gc) ; // IN CASE the GC IS PRIME AND IS > SQRT(GC) ;

        if(primemax > k) print("NO") ; else print("YES") ;
    }
}

