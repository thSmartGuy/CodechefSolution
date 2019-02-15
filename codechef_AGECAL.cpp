#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(lld i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;
    int t, n ;

    std::cin >> t ;

    lld by, bm, bd, cy, cm, cd ;

    while(t--){
        std::cin >> n ;
        int month[n + 1] ;

        lld total_day = 0 ;
        FOR(i, 1, n + 1){
            std::cin >> month[i] ;
            total_day += month[i] ;
        }

        std::cin >> by >> bm >> bd ;
        std::cin >> cy >> cm >> cd ;

        lld n1 ;

        n1 = by*total_day ;

        FOR(i, 1, by){
            if(i%4 == 0){
                n1++ ;
            }
        }

        FOR(i, 1, bm){
            n1 += month[i] ;
        }

        n1 += bd ;

        //_____________________

        lld n2 = cy*total_day ;

        FOR(i, 1, cy){
            if(i%4 == 0){
                n2++ ;
            }
        }

        FOR(i, 1, cm){
            n2 += month[i] ;
        }

        n2 += cd ;

        lld ans = n2 - n1 + 1 ;
        std::cout << ans << "\n" ;
    }
}
