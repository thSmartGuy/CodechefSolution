#include <iostream>
#include <cmath>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int a[111111], b[111111] ;
lld c[111111] ;

bool solve(lld ans, lld loons, int n){
    lld loons_req = 0 ;

    for(int i = 0 ; i < n ; i++){
        if(c[i] > ans){ // not possible for b[i] == 0 and c[i] > ans together as minimum value of ans is 0 and if b[i] == 0 then also c[i] == 0 // NO ERROR HERE
            loons_req += std::ceil((long double)(a[i] - (ans/b[i]))) ;
        }
    }

    if(loons_req > loons){
        return false ;
    }

    return true ;
}

int main(){
    // fast ;

    int n ;
    lld m, sum = 0 ;

    std::cin >> n >> m ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> a[i] ;
        sum += a[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        std::cin >> b[i] ;
        c[i] = (lld)a[i]*b[i] ;
    }

    if(sum <= m){
        std::cout << 0 ;
    }
    else{
        lld low = 0, high = LLONG_MAX ;
        lld mid, ans ;

        while(low < high){
            mid = low + (lld)(high - low)/2 ;

            if(solve(mid, m, n)){ // can decrease maximum
                high = mid ;
                ans = mid ;
            }
            else{ // increase maximum
                low = mid + 1 ;
            }
        }

        lld real_ans = LLONG_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(c[i] > ans && b[i] != 0){
                a[i] -= (lld)std::ceil((long double)(a[i] - (ans/b[i]))) ;
                c[i] = (lld)a[i]*b[i] ;
            }
            if(c[i] > real_ans){
                real_ans = c[i] ;
            }
        }

        std::cout << real_ans ;
    }
}
