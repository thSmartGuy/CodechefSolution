#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 1111 ;

// CODE FROM HERE

int buc[MAX][MAX] ;

int main(){
    // fast ;

    int n, k ;

    std::cin >> n >> k ;//buckets

    int total[n] = {} ;

    FOR(i, 0, n){ // rows is bucket
        FOR(j, 0, k){ // col is type
            std::cin >> buc[i][j] ;
            total[i] += buc[i][j] ;
        }
        if(i!=0) total[i]++ ;
    }
//
//    std::cout << "Totak Count: \n" ;
//    FOR(i, 0, n) std::cout << total[i] << "\n" ;

    double ans[k] = {1} ;

    FOR(i, 0, k){
        FOR(j, 0, n){
            if(j!=0)
                ans[i] = (double)(((double)(ans[i] + buc[j][i]))/total[j]) ;
            else
                ans[i] = (double)(((double)(buc[j][i]))/total[j]) ;
        }
    }

    FOR(i, 0, k){
        std::cout << ans[i] << " " ;
    }
    std::cout << "\n" ;
}

