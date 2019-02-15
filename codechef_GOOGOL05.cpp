#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int n ;

    std::cin >> n ;

    std::map <std::string, int> subject ;

    std::string temp ;
    FOR(i, 0, n){
        std::cin >> temp ;

        subject[temp]++ ;
    }

    for(auto itr : subject){
        std::cout << itr.first << " " << itr.second << "\n" ;
    }
}

