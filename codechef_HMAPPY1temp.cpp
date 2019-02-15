#include <iostream>
#include <deque>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

std::deque arr ;

void pre(int n){

}

int main(){
    // fast ;

    int n, q, k, temp ;
    std::string query ;

    std::cin >> n >> q >> k ;

    FOR(i, 0, n){
        std::cin >> temp ;
        arr.push_back(temp) ;
    }
    pre(n) ;

    std::cin >> query ;

    FOR(i, 0, query.size()){

    }
}
