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
        std::vector <int> count_(n + 1, 0) ;

        FOR(i, 1, n + 1){
            std::cin >> arr[i] ;
            index.insert(arr[i]) ;
        }

        for(auto itr = index.begin() ; itr != index.end() ; itr++){
            count_[arr[arr[*itr]]]++ ;
        }

        bool flag = 0 ;
        FOR(i, 1, n + 1){
            if(count_[i] >= 2){
                flag = 1 ;
                break ;
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
