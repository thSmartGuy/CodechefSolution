#include <iostream>

int arr[100011] ;
/// BRUTE--FORCE
long long ans ;

void findMax(int n){
    long long sum = 0 ;

    for(int i = 0 ; i < n ; i++){
        sum += (long long)(i + 1ll)*arr[i] ;
    }
//
//    if(sum > ans){
//        for(int i = 0 ; i < n ; i++) std::cout << arr[i] << " " ; std::cout << "\n" ;
//    }

    ans = std::max(ans, sum) ;
}

void recur(int idx, int n, bool swapped){
    if(idx == n) return ;

    if(idx == n - 1){
        findMax(n) ;
    }

    if(swapped){ // than cannot swap again
        recur(idx + 1, n, 0) ;
    }
    else{
        if(idx + 1 < n && arr[idx + 1] < arr[idx]){
            std::swap(arr[idx], arr[idx + 1]) ;
            recur(idx + 1, n, 1) ;
            std::swap(arr[idx], arr[idx + 1]) ;
        }
        recur(idx + 1, n, 0) ;
    }
    return ;
}

int main(){
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        ans = 0 ;

        //for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;
        //recur(0, n, 0) ;
        //std::cout << ans << "\n" ;

    /// OPTIMIZED SOLUTION

        for(int i = 1 ; i <= n ; i++) std::cin >> arr[i] ;
        long long dp[n + 1] ;

        dp[0] = 0 ; // if no elements than max is 0
        dp[1] = arr[1] ;// if only one element than that only is the answer

        for(int i = 2 ; i <= n ; i++){
            dp[i] = std::max(
                dp[i - 1] + (long long)arr[i]*i, /// include this also as without this we will only comparing from last last case
                ///             and leaving the comparison from last case
                ///dp[i - 2] + arr[i - 1]*(i - 1) + arr[i]*i, ==((equivalent to) dp[i - 2] + arr[i]*i)=> // this  can be removed as
                ///                        it is already gets covered in above case
                dp[i - 2] + (long long)arr[i - 1]*(i) + (long long)arr[i]*(i - 1)
            );
        }

        std::cout << dp[n] << "\n" ;
    }
}
