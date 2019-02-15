#include <iostream>
#include <vector>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
//typedef long long int lld  ;
//lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
//const int MAX = 111111 ;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

// CODE FROM HERE
std::vector <std::pair<int128_t, int128_t>> ola ;

bool solve(int128_t days, int128_t need, int128_t min_){
    int128_t sum = 0, temp ;

    FOR(i, 0, ola.size()){

        temp = ola[i].first + days*ola[i].second ;
        if(temp >= min_)
            sum += temp ;

        if(sum >= need){
            return true ;
        }
    }

    return false ;
}

int main(){
    fast ;

    int n ;
    int128_t w, l ;

    std::cin >> n >> w >> l ;
    ola.resize(n) ;

    FOR(i, 0, n){
        std::cin >> ola[i].first >> ola[i].second ;
    }

    int128_t low = 0, high = w ;
    int128_t mid, ans = w ;
    while(low <= high){
        mid = low + (high - low)/2 ;

        if(solve(mid, w, l)){
            ans = mid ;
            high = mid ;
            if(low == high){
                break ;
            }
        }
        else{
            low = mid + 1 ;
        }
    }

    std::cout << ans ;
}
