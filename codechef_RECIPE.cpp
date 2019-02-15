#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
const int MAX = 111 ;
typedef long long int lld  ;

int arr[MAX] ;

lld gcd(lld a, lld b){if(!a) return b ; return gcd(b%a, a) ;}

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int div = 0 ;
        FOR(i, 0, n){
            std::cin >> arr[i] ;

            div = gcd(div, arr[i]) ;
        }

        FOR(i, 0, n){
            std::cout << arr[i]/div << " " ;
        }
        std::cout << "\n" ;
    }
}
