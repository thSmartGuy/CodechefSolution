#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

int alpha[26] ;

bool Compare(std::string a, std::string b){
    FOR(i, 0, std::min(a.size(), b.size())){
        if(alpha[a[i] - 'a'] < alpha[b[i] - 'a'])
            return true ;
        else if(alpha[a[i] - 'a'] > alpha[b[i] - 'a'])
            return false ;
    }

    return a.size() < b.size() ? true : false ;
}

void pre(std::string newOrder){
    int l = 1 ;
    FOR(i, 0, newOrder.size()){
        alpha[newOrder[i] - 'a'] = l ;
        l++ ;
    }
}

int main(){
    fast ;

    int n ;

    std::cin >> n ;

    std::string newOrder ;

    std::cin >> newOrder ;

    pre(newOrder) ;
    std::vector <std::string> ola(n) ;

    FOR(i, 0, n){
        std::cin >> ola[i] ;
    }

    std::sort(ola.begin(), ola.end(), Compare) ;

    FOR(i, 0, n){
        std::cout << ola[i] << " " ;
    }
    std::cout << "\n" ;
}

