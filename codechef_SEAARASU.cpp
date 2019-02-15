#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;
template <class T> void print(T a) {std::cout << a << "\n" ;}

// CODE FROM HERE
int main(){
    fast ;

    lld t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        lld arr[n] ;

        bool one = 0 ;
        FOR(i, 0, n){
            std::cin >> arr[i] ;
            if(arr[i] == 1){
                one = 1 ;
            }
        }

        if(one){
            print(n) ;
            continue ;
        }

        lld g = 0 ;
        FOR(i, 0, n){
            g = gcd(g, arr[i]) ;
        }

        print((lld)g*n) ;
    }
}

