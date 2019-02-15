#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int n ;
    std::cin >> n ;

    //MOST
    for(int i = 2 ; i <= n/2 ; i++){
        std::cout << i << " " ;
    }

    std::cout << 1 << " " ;
    for(int i = n/2 + 2 ; i <= n ; i++){
        std::cout << i << " " ;
    }
    std::cout << n/2 + 1 << "\n" ;

    // LEAST
    std::cout << n << " " ;
    for(int i = 1 ; i < n ; i++){
        std::cout << i << " " ;
    }
    std::cout << "\n" ;
}
