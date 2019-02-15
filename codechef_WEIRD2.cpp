#include <iostream>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

int arr[111111] ;

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int count_[1000001] = {} ;
        for(int i = 1 ; i < n ; i++){
            std::cin >> arr[i] ;
            count_[arr[i]]++ ;
        }

        int ans = 0 ;
        for(int i = 1 ; i < n + 1 ; i++){ // i represent a here // only needs to check till n as any count will not exceed n
            for(int j = 1 ; j <= count_[i] ; j++){ // j represent b /////* j <= count(a) */
                if(count_[j] >= i){ // b is atleast a times
                    ans++ ;
                }
            }
        }

        std::cout << ans << "\n" ;
    }
}
