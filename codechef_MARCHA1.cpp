#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE

int notes[MAX] ;

bool check(int n, int sum){
    if(sum == 0) return true ;

    if(n == 0) return false ;

    return (check(n - 1, sum) || check(n - 1, sum - notes[n - 1])) ;
}

int main(){
    fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        int m ;
        std::cin >> n >> m ;

        FOR(i, 0, n) std::cin >> notes[i] ;

        bool isPos = check(n, m) ;
        std::cout << (isPos ? "Yes\n" : "No\n") ;
    }
}
