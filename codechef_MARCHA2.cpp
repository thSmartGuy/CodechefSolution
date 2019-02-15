#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1000001 ;

// CODE FROM HERE

int arr[MAX] ;

int main(){
    // fast() ;

    int t, k ;

    std::cin >> t ;

    while(t--){
        std::cin >> k ;

        FOR(i, 0, k) std::cin >> arr[i] ;

        int stems = 1 ;
        std::string ans = "Yes" ;
        FOR(i, 0, k){
            int leaf = arr[i] ;
            if(i == k - 1 && leaf != stems){
                ans = "No" ;
            }

            if(stems - leaf < 0){
                ans = "No" ;
                break ;
            }

            stems = (stems - leaf)*2 ;
        }

        print(ans) ;
    }
}

