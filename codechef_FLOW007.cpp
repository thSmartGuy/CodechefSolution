#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, n ;
    bool startingZeroes ;

    std::cin >> t ;

    while(t--){
        startingZeroes = 1 ;
        std::cin >> n ;

        while(n){
            if(startingZeroes && n%10 != 0){
                startingZeroes = 0 ;
            }
            if(n%10 == 0 && !startingZeroes)
                std::cout << n%10 ;

            if(n%10 != 0){
                std::cout << n%10 ;
            }

            n /= 10 ;
        }

        std::cout << "\n" ;
    }
}
