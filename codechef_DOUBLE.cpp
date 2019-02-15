#include <iostream>

int main(){
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        if(n%2 == 0){
            std::cout << n << "\n" ;
        }
        else{
            std::cout << n - 1 << "\n" ;
        }
    }
}
