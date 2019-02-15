#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 5*111111 ;

// CODE FROM HERE

int budget[MAX] ;
lld revenue[MAX] ;

int main(){
     fast() ;

    int n ;

    std::cin >> n ;

    FOR(i, 0, n) std::cin >> budget[i] ;

    std::sort(budget, budget + n) ;

    int mul = n ;
    FOR(i, 0, n){
        revenue[i] = 1ll*budget[i]*mul ;
        mul-- ;
    }

    std::sort(revenue, revenue + n) ;

    print(revenue[n - 1]) ;
}

