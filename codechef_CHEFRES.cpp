#include <iostream>
#include <algorithm>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

int main(){
    fast ;
    int t, n, m, l, r ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;


        std::vector <int> interval(2*n) ;

        for(int i = 0 ; i < 2*n ; i+=2){
            std::cin >> interval[i] >> interval[i + 1] ;
        }

        std::sort(interval.begin(), interval.end()) ;

        /*
        for(int i = 0 ; i< 2*n ; i+=2){
            std::cout << "| " << interval[i] << " | " << interval[i + 1] << " | " ;
        }
        std::cout << "\n" ;*/

        int query ;
        for(int i = 0 ; i < m ; i++){
            std::cin >> query ;

            int itr = std::lower_bound(interval.begin(), interval.end(), query + 1) - interval.begin() ;

            //std::cout << itr << " :: " ;
            if(itr == 2*n){
                std::cout << "-1\n" ;
            }
            else if(itr%2 == 1){
                std::cout << "0\n" ;
            }
            else{
                std::cout << interval[itr] - query << "\n" ;
            }
        }
    }
}
