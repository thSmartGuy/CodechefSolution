#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    int n, m, c ;

    std::cin >> n >> m >> c ;

    std::cout << "3\n" ;
    FOR(i, 0, n){
        FOR(j, 0, m){
            std::cout << "25 " ;
        }
        std::cout << "\n" ;
    }
}

