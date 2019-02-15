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

int findbags(int k, int r){
    int n = 0 ;
    int sum = 0 ;

    while(sum <= k){
        n++ ;
        sum = ((n*(n + 1))/2)*r ;
    }

    n-- ;

    return n ;
}

int main(){
    // fast() ;

    int n, k, r ;

    std::cin >> n >> k >> r ;

    int ans = findbags(k, r) ;

    if(ans >= n){
        print(0) ;
    }
    else{
        print(n - ans) ;
    }
}

