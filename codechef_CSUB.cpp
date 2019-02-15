#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;

    std::string str ;
    int t, n, count_ ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        std::cin >> str ;

        count_ = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(str[i] == '1'){
                count_++ ;
            }
        }

//        std::cout << ((lld)(count_*(count_ + 1))/2) << "\n" ; // GIVING WA
          std::cout << (1LL*count_*(count_ + 1))/2 << "\n" ; // ACCEPTED
    }
}

