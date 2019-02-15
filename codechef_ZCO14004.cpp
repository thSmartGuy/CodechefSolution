#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 2*111111 ;

// CODE FROM HERE

int arr[MAX] = {} ;

lld dp[MAX][2] = {} ;

int main(){
    fast() ;

    dp[0][0] = 0 ; dp[1][0] = 0 ; dp[2][0] = 0 ;
    dp[0][1] = 0 ; dp[1][1] = 0 ; dp[2][1] = 0 ;

    int n ;
    std::cin >> n ;

    FOR(i, 3, n + 3) std::cin >> arr[i] ;

    if(n == 1) print(arr[3]) ;
    else if(n == 2) print(arr[3] + arr[4]) ;
    else if(n == 3) print(std::max(std::max(arr[3] + arr[4], arr[4] + arr[5]), arr[3] + arr[5])) ;
    else{
        FOR(i, 3, n + 3){
            dp[i] = std::max(std::max(dp[i - 1] + dp[i - 2], arr[i] + dp[i - 2] + dp[i - 3]), arr[i] + dp[i - 1]) ;
        }

        print(std::max(std::max(dp[n - 1] + dp[n - 2], dp[n - 2] + dp[n - 3]), dp[n - 1])) ;
    }
}


