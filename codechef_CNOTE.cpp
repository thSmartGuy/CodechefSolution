#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
const int MAX = 111111 ;
typedef long long int lld  ;

// CODE FROM HERE
int main(){
    fast ;

    int t, x, y, k, n, p, c ;

    std::cin >> t ;

    while(t--){
        std::cin >> x >> y >> k >> n ;

        int need = x - y ;

        std::string ans = "UnluckyChef\n" ;
        FOR(i, 0, n){
            std::cin >> p >> c ;
            if(p >= need && c <= k){
                ans = "LuckyChef\n" ;
            }
        }

        std::cout << ans ;
    }
}

