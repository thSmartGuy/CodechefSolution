#include <iostream>
const int N = 1111 ;
const int mod = 1000000007 ;

long long int dp[N][N] ;

void init(){
    for(int i = 1 ; i < N ; i++){
        dp[i][0] = 0 ;
        dp[i][1] = 1 ;
        dp[i][i] = 1 ;
    }

    for(int i = 1 ; i < N ; i++){
        for(int j = 1 ; j < i ; j++){
            dp[i][j] = dp[i - 1][j - 1] + (dp[i - 1][j]*j) ;
            dp[i][j] %= mod ;
        }
    }
}

//465231251

int main(){
    std::ios_base::sync_with_stdio(false) ;

    init() ;

    int t, n ;

    std::cin >> t ;

    long long int ans ;
    while(t--){
        std::cin >> n ;

        ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            ans = (ans + dp[n][i])%mod ;
        }

        std::cout << ans << "\n" ;
    }
}
