#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int gcd(int a, int b){
    if(!a) return b ;
    return gcd(b%a, a) ;
}

int main(){
    fast ;

    int t, n, temp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::vector <int> arr(n) ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }

        std::sort(arr.begin(),arr.end()) ;

        int diff ;

        int ans = arr[1] - arr[0] ;
        FOR(i, 2, arr.size()){
            diff = arr[i] - arr[i - 1] ;
            if(ans<diff)
            ans = gcd(ans, diff) ;
            else
            ans = gcd(diff, ans) ;
        }
        if(ans < arr[0] + 360 - arr[n - 1])
        ans = gcd(ans, arr[0] + 360 - arr[n - 1]) ;
        else
        ans = gcd(arr[0] + 360 - arr[n - 1], ans) ;

        std::cout << 360/ans - n << "\n" ;
    }
}
