#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

std::string dectobin(int a){
    std::string b = "" ;

    while(a){
        b += ((char)a%2 + '0') ;
        a >>= 1 ;
    }

    std::reverse(b.begin(), b.end()) ;

    return b ;
}

int findk(std::string src, std::string dest){
    int k = 1 ;
    FOR(i, 0, std::min(src.size(), dest.size())){
        if(src[i] == dest[i]){
            k = i + 1 ;
        }
        else{
            break ;
        }
    }

    return k ;
}

int main(){
    int t, i, j ;

    std::cin >> t ;

    while(t--){
        std::cin >> i >> j ;
//
//        std::string src, dest ;
//
//        src = dectobin(i) ;
//        dest = dectobin(j) ;
//
////        std::cout << src << " : " << dest << "\n" ;
//
//        int k = findk(src, dest) ;
//
////        std::cout << "k: " << k << "\n" ;
//
//        std::cout << src.size() + dest.size() - 2*k << "\n" ;

        int ans = 0 ;

        while(i != j){
            if(i > j){
                i /= 2 ;
                ans++ ;
            }

            if(j > i){
                j /= 2 ;
                ans++ ;
            }
        }

        std::cout << ans << "\n" ;
    }
}

