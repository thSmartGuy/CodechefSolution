#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int arr[111111] ;

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + n) ;

        std::cout << arr[0] + arr[1] << "\n" ;
    }
}

