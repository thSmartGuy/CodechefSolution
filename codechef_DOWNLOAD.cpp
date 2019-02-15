#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;

    int n, q, k, s, e, t ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> s >> e ;
        for(int j = s ; j <= e ; j++){
            time[j]++ ;
        }
    }

    std::cin >> q ;
    while(q--){
        std::cin >> t ;
        std::cout << time[t] << "\n" ;
    }
}
