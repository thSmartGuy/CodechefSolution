#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;
int main(){
    fast ;

    int t, n, vote ;

    std::cin >> t ;

    while(t--){
        int win = 0 ;
        std::cin >> n ;
        FOR(i, 0, n){
            std::cin >> vote ;
            win += vote ;
        }

        if(win >= 0){
            std::cout << "YES\n" ;
        }
        else{
            std::cout << "NO\n" ;
        }
    }
}
