#include <iostream>
#include <algorithm>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::vector <int> ramT, ramD, shyamT, shyamD ;

        std::string ans = "yes\n" ;
        std::cin >> n ;
        ramT.resize(n) ;
        FOR(i, 0, n){
            std::cin >> ramT[i] ;
        }
        std::sort(ramT.begin(), ramT.end()) ;

        std::cin >> n ;
        ramD.resize(n) ;
        FOR(i, 0, n){
            std::cin >> ramD[i] ;
        }
        std::sort(ramD.begin(), ramD.end()) ;

        std::cin >> n ;
        shyamT.resize(n) ;
        FOR(i, 0, n){
            std::cin >> shyamT[i] ;
            if(std::binary_search(ramT.begin(), ramT.end(), shyamT[i]) != 1){
                ans = "no\n" ;
            }
        }

        std::cin >> n ;
        shyamD.resize(n) ;
        FOR(i, 0, n){
            std::cin >> shyamD[i] ;
            if(std::binary_search(ramD.begin(), ramD.end(), shyamD[i]) != 1){
                ans = "no\n" ;
            }
        }

        std::cout << ans ;
    }
}
