#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE

int arr[MAX] ;

int main(){
    fast() ;

    int t, n, k ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        lld min_ = 0 ;
        FOR(i, 0, n){
            if(arr[i]%k != 0){
                if(arr[i] > k)
                    min_ += std::min(arr[i]%k, k - arr[i]%k) ;
                else min_ += k - arr[i]%k ;
            }
        }

        print(min_) ;
    }
}

