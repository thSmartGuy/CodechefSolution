#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

typedef long long int lld ;

lld arr[100001] ;

lld dp[33768] ;

void pre(){
    for(lld i = 0 ; 1LL*i*i < 1150000000 && i < 33768 ; i++){
        dp[i] = 1LL*i*i ;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false) ;

    lld t, n, q, l, r, count_;
    lld perfect ;
    std::cin >> t ;

    pre() ;

    while(t--){
        std::cin >> n >> q ;

        for(lld i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        while(q--){
            std::cin >> l >> r ;
            l-- ; r-- ;

            count_ = 0 ;
            for(lld i = l ; i <= r ; i++){
                perfect = arr[i] ;

                if(std::binary_search(dp, dp + 33768, perfect)){
                    count_++ ;

             //       std::cout << "(" << i << ", " << i << ")\n" ;
                }

                for(lld j = i + 1 ; j <= r ; j++){
                    perfect = perfect & arr[j] ;

                    if(std::binary_search(dp, dp + 33768, perfect)){
                        count_++ ;

             //           std::cout << "(" << i << ", " << j << ")\n" ;
                    }
                }
            }

            std::cout << count_ << "\n" ;
        }
    }
}
