#include <iostream>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int arr[111][111] ;

int findTrace(int i, int j, int n){
    int sum = 0 ;
    for(i ; i < n && j < n; i++, j++){
        sum += arr[i][j] ;
    }
    return sum ;
}

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                std::cin >> arr[i][j] ;
            }
        }

        int real_i, ans = INT_MIN, sum ;

        for(int i = 0 ; i < n ; i++){
            ans = std::max(ans, findTrace(0, i, n)) ;
        }

        for(int i = 0 ; i < n ; i++){
            ans = std::max(ans, findTrace(i, 0, n)) ;
        }

        std::cout << ans << "\n" ;
    }
}

