#include <iostream>
#include <iomanip>
#include <cmath>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;
    double dh, dl, dr, k ;

    while(1){
        std::cin >> dh >> dl >> dr >> k ;

        if(dh && dl && dr && k){

        double ans, leastTime = 1e10 ;
        for(double i = dr ; i >= 0 ; i -= 0.001){
            double d1 = std::sqrt(i*i + dh*dh) ;
            double d2 = std::sqrt((dr - i)*(dr - i) + dl*dl) ;

            double timetemp = d1/k + d2 ;
            if(timetemp < leastTime){
                leastTime = timetemp ;
                ans = d1 + d2 ;
            }
            else break ;
        }
        std::cout << std::fixed << std::setprecision(2) << ans << "\n" ;

        }else break ;
    }
}

