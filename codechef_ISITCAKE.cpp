#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111 ;

// CODE FROM HERE
int main(){
    fast ;

    int t ;

    std::cin >> t ;

    while(t--){
        int temp ;
        int cake = 0 ;
        FOR(i, 0, 100){
            std::cin >> temp ;
            if(temp <= 30) cake++ ;
        }

        std::cout << (cake >= 60 ? "yes\n" : "no\n") ;
    }
}

