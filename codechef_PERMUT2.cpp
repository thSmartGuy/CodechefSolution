#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

int arr[MAX] ;

// LEARNED ABOUT INVERSE PERMUTATION

int main(){
    fast ;

    int n ;

    std::cin >> n ;
    while(n){
        FOR(i, 1, n + 1){
            std::cin >> arr[i] ;
        }

        std::string ans = "ambiguous\n" ;

        FOR(i, 1, n + 1){
            if(arr[arr[i]] != i){
                ans = "not ambiguous\n" ;
                break ;
            }
        }

        std::cout << ans ;

        std::cin >> n ;
    }
}
