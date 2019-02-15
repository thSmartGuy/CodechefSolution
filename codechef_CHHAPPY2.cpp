#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::vector <int> arr(n + 1) ;
        std::set <int> index ;
        FOR(i, 1, n + 1){
            std::cin >> arr[i] ;
            index.insert(arr[i]) ;
        }

        bool flag = 0 ;
        FOR(i, 1, n + 1){
            FOR(j, 1, n + 1){
                if(arr[i] != arr[j]){
                    if(arr[arr[i]] == arr[arr[j]]){
                        flag = 1 ;
                        break ; break ;
                    }
                }
            }
        }

        if(flag){
            std::cout << "Truly Happy\n" ;
        }
        else{
            std::cout << "Poor Chef\n" ;
        }
    }
}
