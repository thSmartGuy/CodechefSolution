#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

int D[MAX] ;

int main(){
    fast ;

    const int limitD = 1e9 ;
    int t, n, q, query ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> q ;

        lld mul = 1 ;
        FOR(i, 0, n){
            std::cin >> D[i] ;
        }

        FOR(i, 0, n){
            mul *= D[i] ;

            if(mul >= limitD){
                break ;
            }
        }

        while(q--){
            std::cin >> query ;

            if(mul > query){
                std::cout << 0 << " " ;
            }
            else{
                std::cout << (1LL*query)/mul << " " ;
            }
        }
        std::cout << "\n" ;
    }
}
