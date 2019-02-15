#include <iostream>

long long int solve(int n){
    if(n <= 1){
        return 1 ;
    }

    return n*solve(n - 1) ;
}

int main(){
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::cout << solve(n) << "\n" ;
    }
}
