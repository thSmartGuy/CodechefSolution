#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 100001 ;

// CODE FROM HERE

int main(){
     fast() ;
    int t, n ;

    std::cin >> t ;
    while(t--){
        std::cin >> n ;

        int gc = 0, tmp ;

        std::cin >> tmp ;
        gc = tmp ;

        bool flg = 0 ;
        FOR(i, 1, n){
            std::cin >> tmp ;
            gc = gcd(gc, tmp) ;
            if(gc == 1){
                flg = 1 ;
            }
        }

        if(flg) print(n) ;
        else print(-1) ;
    }
}

