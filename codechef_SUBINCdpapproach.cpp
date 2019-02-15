#include <iostream>
#include <cstdio>
#define scan(n) scanf("%d", &n)
#define rep(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld ;

int a[100000] ;

int main(){
    int t, n ;
    scan(t) ;
    while(t-->0){
        lld qans = 0 ;
        scan(n) ;
        rep(i, 0, n){
            scan(a[i]) ;
        }

        int ans[n] ;
        ans[0] = 1 ;
        rep(i, 1, n){
            if(a[i] >= a[i - 1]){
                ans[i] = ans[i - 1] + 1 ;
            }
            else{
                ans[i] = 1 ;
            }
        }

        rep(i, 0, n){
            qans += ans[i] ;
        }

        std::cout << qans << "\n" ;
    }
}
