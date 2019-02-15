#include <iostream>
#include <cmath>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    int t, n, m, d, k ;
    char c ;

    std::cin >> t ;

    while(t--){

        std::cin >> n >> m ;

        k = 0 ;
        std::pair <int, int> S[4*n*m] ;
        std::vector <int> ans(n + m, 0) ;


        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                std::cin >> c ;

                if(c == '1'){
         //           std::cout << "(" << i << " " << j << ")" << "\n" ;
                    S[k].first = i ;
                    S[k++].second = j ;
                }
            }
        }

       // std::cout << "k: " << k << "\n" ;

        for(int i = 0 ; i < k ; i++){
            for(int j = i + 1 ; j < k ; j++){
                d = (int)std::abs(S[i].first - S[j].first) + (int)std::abs(S[i].second - S[j].second) ;

                ans[d]++ ;
            }
        }

        for(int i = 1 ; i < n + m - 2 + 1 ; i++)
            std::cout << ans[i] << " " ;

        std::cout << "\n" ;
    }
}
