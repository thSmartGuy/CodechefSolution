#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int h[150] ;

int main(){
    fast ;

    int t, n, k ;

    std::cin >> t ;

    h[0] = 0 ;
    while(t--){
        std::cin >> n >> k ;

        int count_ = 0 ;

        for(int i = 1 ; i <= n ; i++){
            std::cin >> h[i] ;

            if((h[i] - h[i - 1]) > k){
                count_ += (h[i] - h[i - 1])/k ;

                if((h[i] - h[i - 1])%k == 0){
                    count_ -- ;
                }
            }
        }

        std::cout << count_ << "\n" ;
    }
}

