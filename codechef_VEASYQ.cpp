#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 511111 ;

// CODE FROM HERE
int main(){
    fast ;

    int n, m ;

    std::cin >> n >> m ;

    int stu[MAX] = {} ;

    int k, l, r ;
    while(m--){
        std::cin >> k >> l >> r ;

        stu[l] += k ;
        stu[r + 1] -= k ;
    }

    lld lo = 0 ;
    FOR(i, 1, n + 1){
        lo += stu[i] ;
        stu[i] = lo ;
    }

    int max_ = stu[1] ;
    FOR(i, 1, n + 1){
        if(stu[i] > max_){
            max_ = stu[i] ;
        }
    }

    int cunt_ = 0 ;
    FOR(i, 1, n + 1){
        if(stu[i] == max_){
            cunt_++ ;
        }
    }

    std::cout << cunt_ << "\n" ;

    FOR(i, 1, n + 1){
        if(stu[i] == max_){
            std::cout << i << " " ;
        }
    }

}

