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

int find_(int n){
    int a = 1 ;

    while(1ll*a*(a + 1)/2 < n){
        a++ ;
    }

    if(1ll*a*(a + 1)/2 > n){
        a-- ;
    }

    return a ;
}

int main(){
    // fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        print(find_(n)) ;
    }
}

