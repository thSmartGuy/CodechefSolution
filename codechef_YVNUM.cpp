#include <iostream>
#include <vector>
#include <algorithm>
//#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main(){
    // fast ;

    int t ;

    std::cin >> t ;

    int n ;
    while(t--){
        std::string orig ;

        std::cin >> orig ;
        std::string ans = "" ;

        ans += orig ;

        std::cout << orig << "\n" ;

        FOR(i, 1, orig.size()){

        }
    }
}

