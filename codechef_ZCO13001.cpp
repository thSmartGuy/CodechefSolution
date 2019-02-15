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

int arr[MAX] ;
lld suffix[MAX] = {} ;

int main(){
     fast() ;

    int n ;

    std::cin >> n ;

    FOR(i, 0, n) std::cin >> arr[i] ;

    std::sort(arr, arr + n) ;

    for(int i = n - 1 ; i >= 0 ; i--){
        suffix[i] = suffix[i + 1] + arr[i] ;
    }

    lld ans = 0 ;

    FOR(i, 0, n - 1){
        ans += suffix[i + 1] - 1ll*arr[i]*(n - i - 1) ;
    }

    print(ans) ;
}

