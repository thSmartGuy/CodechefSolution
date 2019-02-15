#include <iostream>
#include <cmath>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
typedef long long int lld ;

int loons[111111] ;
int candies[111111] ;
lld loonsCandies[111111] ;
lld real_ans ;

bool solve(lld ans, int n, lld m){
    lld loons_req = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(loonsCandies[i] > ans && candies[i] != 0){
            loons_req += std::ceil((long double)(loons[i] - (ans/candies[i]))) ;
        }
    }

    if(loons_req > m){
        return 0 ;
    }

    return 1 ;
}

int main(){
    fast ;

    int n ;
    lld sum = 0, m ;

    std::cin >> n >> m ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> loons[i] ;
        sum += loons[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        std::cin >> candies[i] ;
        loonsCandies[i] = (lld)candies[i]*loons[i] ;
    }

    if(sum <= m){
        std::cout << 0 ;
    }
    else{

        lld high = LLONG_MAX ;
        lld low = 0 ;
        lld mid, ans = LLONG_MAX ;
        while(low < high){
            mid = low + (high - low)/2 ;

            if(solve(mid, n, m)){ // loons are left
                high = mid ; // reduce high answer is lower
                ans = mid ;
            }
            else{
                low = mid + 1 ; // increase low
            }
        }

        real_ans = LLONG_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(loonsCandies[i] > ans){
                loons[i] -= std::ceil((long double)(loons[i] - (ans/candies[i]))) ;
            }

            if(candies[i]*loons[i] > real_ans){
                real_ans = (lld)candies[i]*loons[i] ;
                loons[i] += std::ceil((long double)(loons[i] - (ans/candies[i]))) ;
            }
        }

        std::cout << real_ans ;
    }
}

