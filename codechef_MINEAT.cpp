#include <cstdio>
#include <algorithm>
#include <iostream>
#define scan(n) scanf("%d", &n)
#define scan2(n, m) scanf("%d%d", &n, &m)
#define rep(i, k, n) for(int i = k ; i < n ; i++)
#include <cmath>
#include <climits>

int a[100000] ;

long long solve(long long hr, int n){
    long long ans = 0 ;
    rep(i, 0, n){
        ans += (a[i] + hr - 1)/hr ; // ** ** * ** ** **
    }
    return ans ;
}

int main(){
    int t, max_, min_, h, n, k ;
    long long hr;
    scan(t) ;
    while(t-->0){
        scan2(n, h) ;
        rep(i, 0, n)
            scan(a[i]) ;

        min_ = 1 ; max_ = 1e9 ;
        while(max_ - min_ > 1){
            k = min_ + max_ >> 1 ; // same as (max_ + min_)/2 no overflow
            hr = solve(k, n) ;
            if(hr <= h){
                max_ = k ;
            }
            else{
                min_ = k ;
            }
        }

        if(solve(min_, n) <= h)
            k = min_ ;
        else{
            k = max_ ;
        }
        std::cout << k << "\n" ;
    }
}

