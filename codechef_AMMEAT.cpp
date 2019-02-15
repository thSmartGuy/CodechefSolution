#include <iostream>
#include <algorithm>

typedef long long int lld ;

lld arr[8] ;

int main(){
    int t, n ;
    lld m, sum ;

    std::cin >> t ;

    while(t--){
        sum = 0 ;
        std::cin >> n >> m ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + n) ;

        int i ;
        for(i = n - 1 ; i >= 0 ; i--){
            sum += arr[i] ;
            if(sum >= m){
                break ;
            }
        }

        if(sum >= m){
            std::cout << n - i << "\n" ;
        }
        else{
            std::cout << -1 << "\n" ;
        }
    }
}
