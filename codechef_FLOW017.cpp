#include <iostream>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, arr[3] ;

    std::cin >> t ;

    while(t--){
        FOR(i, 0, 3){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + 3) ;

        std::cout << arr[1] << "\n" ;
    }
}
