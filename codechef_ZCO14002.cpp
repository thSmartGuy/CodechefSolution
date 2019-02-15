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

lld dp[MAX] = {} ;

int main(){
    fast() ;

    int n ;
    std::cin >> n ;

    FOR(i, 3, n + 3) std::cin >> arr[i] ;

    FOR(i, 3, n + 3)
        dp[i] = arr[i] + std::min(std::min(dp[i - 1], dp[i - 2]), dp[i - 3]) ;

    if(n == 1) print(arr[3]) ;
    else if(n == 2) print(std::min(arr[3], arr[4])) ;
    else if(n == 3) print(std::min(std::min(arr[3], arr[4]), arr[5])) ;
    else print(std::min(std::min(dp[n + 2], dp[n + 1]), dp[n])) ;
}

