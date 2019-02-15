#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

// NOT ORIGINAL SOLUTION
int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int i = 0 ;
        for(i ; i < 42949 ; i++){
            std::cout << "100000 " ;
        }
        // limit == 4294967295
        // covered till now ==> 4294900000

        for(i ; i < n ; i++){
            std::cout << "1 " ;
        }
        //minimum possible till now =>> n = 99991 || 99991 - 42949 == 57042*1 + 4294900000 ==> 4294957042
        //maximum possible till now =>> n = 100000 || 100000 - 42949 == 57051*1 + 4294900000 ==> 4294957051

        // Given Code will always return 1 as Minimum index while ans is 42949
        // as (4294967295 + 100000)%(2^32 - 1) == 100000
        std::cout << "\n" ;
    }
}

