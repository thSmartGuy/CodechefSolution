#include <iostream>
#include <vector>
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
// JUST TESTING
    int t ;

    std::cin >> t ;

    int n ;
    while(t--){
        std::cin >> n ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        FOR(i, 0, n) std::cout << arr[i] << " " ;
        std::cout << "\n" ;
    }
}

