#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 11

typedef long long int lld  ;

int gcd(int a, int b){
    if(!a) return b ; return gcd(b%a, a) ;
}

int main(){
    fast ;

    int t, n, m ;
    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        std::vector <int> arr(n), orig(n), temp(n) ;
        std::vector < std::pair<int, int>> lr(m) ;

        FOR(i, 0, n){
            std::cin >> arr[i] ;
        }
        orig = arr ;

        FOR(i, 0, m){
            std::cin >> lr[i].first >> lr[i].second ;
        }

        FOR(i, 0, m){
            int l = lr[i].first - 1 ;
            int r = lr[i].second ;
            std::reverse(orig.begin() + l, orig.begin() + r) ;
        }

        std::sort(lr.begin(), lr.end()) ;

        int a = 0, b = 0 ;
        do{
            temp = arr ;

            FOR(i, 0, m){
                int l = lr[i].first - 1 ;
                int r = lr[i].second ;
                std::reverse(temp.begin() + l, temp.begin() + r) ;
            }

            if(temp == orig)
                a++ ;
            b++ ;
        }while(std::next_permutation(lr.begin(), lr.end())) ;

        int div = gcd(a, b) ;
        std::cout << a/div << "/" << b/div << "\n" ;
    }
}
