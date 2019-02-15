#include <iostream>
#include <map>
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

    int t, n, tmp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::map <int, int> mp ;
        bool flg = 1 ;
        FOR(i, 0, n){
            std::cin >> tmp ;
            mp[tmp]++ ;
            if(mp[tmp] > 1) flg = 0 ;
        }

        std::cout << (flg ? "no\n" : "yes\n") ;
    }
}

