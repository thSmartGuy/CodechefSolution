#include <iostream>
#define scan(n) scanf("%d", &n)
#define rep(i, k, n) for(int i = k ; i < n ; i++)
#define print(a) printf("%lld", a)
typedef long long int lld ;

int a[100000] ;

int main(){
    int t, n, ctr, j ;
    lld ans, count_ ;
    scan(t) ;
    while(t-->0){
        ans = 0 ;
        scan(n) ;
        rep(i, 0, n){
            scan(a[i]) ;
        }

        rep(i, 0, n){
            count_ = 0 ;
            ctr = a[i] ;
            j = i + 1 ;
            while(ctr <= a[j] && j != n){
                ctr = a[j] ;
                count_++ ;
                j = j + 1 ;
            }

            ans += 1LL*(count_ + 1)*(count_)/2 ;
            i = j - 1 ;
        }

        print(1LL*(ans + n)) ; printf("\n") ;
    }
}
