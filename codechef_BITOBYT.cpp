#include <iostream>
#include <cmath>

int main(){
    int t, n ;
    long long int bits ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        n-- ;

        bits = (n < 26) ? 1 : std::pow(2, n/26) ;

        int rem = n%26 ;
        if(rem >= 0 && rem < 2){
            std::cout << bits << " 0 0\n" ;
        }
        else if(rem >= 2 && rem < 10){
            std::cout << "0 " << bits << " 0\n" ;
        }
        else{
            std::cout << "0 0 " << bits << "\n" ;
        }
    }
}
