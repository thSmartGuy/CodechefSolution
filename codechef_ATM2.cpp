#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int t, n, k, temp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;

        for(int i = 1 ; i <= n ; i++){
            std::cin >> temp ;

            if(temp <= k){
                std::cout << "1" ;
                k -= temp ;
            }
            else{
                std::cout << "0" ;
            }
        }

        std::cout << "\n" ;
    }
}
