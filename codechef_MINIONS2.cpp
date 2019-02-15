#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;
    std::cout.tie(NULL) ;

    int t, n ;
    std::cin >> t ;

    while(t--){
        std::vector <std::pair <long long, int>> tuples, indexb ;

        std::cin >> n ;
        tuples.resize(n) ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> tuples[i].first >> tuples[i].second ;
        }

        std::sort(tuples.begin(), tuples.end()) ;
        std::reverse(tuples.begin(), tuples.end()) ; // descending powers

        indexb.resize(n) ;

        for(int i = 0 ; i < n ; i++){
            indexb[i].first = tuples[i].second ;
            indexb[i].second = i ;
        }

        std::sort(indexb.begin(), indexb.end()) ;


    }
}
