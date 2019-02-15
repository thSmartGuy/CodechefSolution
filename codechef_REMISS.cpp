#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, a, b ;

    std::cin >> t ;

    while(t--){
        std::cin >> a >> b ;
        std::cout << std::max(a, b) << " " << a + b << "\n" ;
    }
}
