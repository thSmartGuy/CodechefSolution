#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int height[111111] ;
int color[111111] ;

int main(){
    fast ;

    int t, n, m ;
    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> height[i] ; //.first ;
            //height[i].second = i ;
        }

        for(int i = 0 ; i < n ; i++){
            std::cin >> color[i] ;
        }

        std::vector <int> ans(100001, 0) ;

        int max_ = height[n - 1] ; //.first ;
        ans[color[n - 1]]++ ;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(height[i] > max_){
                ans[color[i]]++ ;
                max_ = height[i] ;
            }
        }

        int real_ans = 0 ;
        for(int i = 1 ; i <= 100000 ; i++){
            if(ans[i]){
                real_ans++ ;
            }
        }

        std::cout << real_ans << "\n" ;
    }
}
