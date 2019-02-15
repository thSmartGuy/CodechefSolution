#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision ;
int128_t gcd(int128_t a, int128_t b){ if(!a) return b ; return gcd(b%a, a) ;}

int arr[MAX] ;

int128_t LCM(int arr[], int n){
    int128_t a = arr[0] ;

    int128_t ans = a ;
    FOR(i, 0, n){
        ans = (ans*arr[i])/gcd(ans, arr[i]) ;
        if(static_cast<int>(boost::multiprecision::cpp_int(ans)) > 1e18){
            return 0 ;
        }
    }

    return ans ;
}

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        int128_t lo, up ;

        std::cin >> lo >> up ;

        int128_t lcm = LCM(arr, n) ;

        int128_t ans = 0 ;
        if(lcm != 0)
            ans = (up - lo + 1) - (up/lcm - (lo - 1)/lcm) ;

        print(ans) ;
    }
}

