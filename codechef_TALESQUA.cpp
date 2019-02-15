#include <iostream>
#include <algorithm>
#include <iomanip>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, a, k, x[4] ;

    std::cin >> t ;

    while(t--){
        std::cin >> a >> k ;

        std::cin >> x[1] >> x[2] >> x[3] ;

        std::sort(x + 1, x + 4) ;

        int inter_dist = x[3] - x[1] - 2*k ;
        if(inter_dist < 0)
            inter_dist = 0 ;

        double ans = std::max(0, (a - inter_dist))*(double)a ;

        std::cout << std::fixed << std::setprecision(6) <<ans << "\n" ;
    }
}
