#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int t, n, m ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        std::string arr[n] ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }


        int ans = 0 ;
        FOR(j, 0, m){
            int c = 0 ;
            FOR(i, 0, n){
                if(arr[i][j] == '1'){
                    c++ ;
                }
            }
            ans += c*(c - 1)/2 ;
        }

        std::cout << ans << "\n" ;
    }
}

