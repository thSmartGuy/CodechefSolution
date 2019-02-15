#include <iostream>
#include <climits>

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ; std::cout.tie(NULL) ;

    int t, n, k, temp ;
    std::cin >> t ;
    while(t-->0){
        std::cin >> n >> k ;
        int sum_array[n + 1] ;
        sum_array[0] = 0 ;

        for(int i = 1 ; i <= n ; i++){
            std::cin >> temp ;
            sum_array[i] = sum_array[i - 1] + temp ;
        }

        int max_ = INT_MIN ;
        for(int i = k ; i <= n ; i++){
            max_ = std::max(max_, sum_array[i] - sum_array[i - k]) ;
        }

        std::cout << max_ << "\n" ;
    }
}
