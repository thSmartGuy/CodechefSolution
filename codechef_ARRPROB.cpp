#include <iostream>
typedef long long int lld ;
#define scan(n) scanf("%d", &n)
#define pin(n) printf("%d", n)

int arr[100000] ;

int main(){
    int t, n ;
    scan(t) ;

    while(t--){
        lld sum = 0 ;
        scan(n) ;
        for(int i = 0 ; i < n ; i++){
            scan(arr[i]) ;
            sum += arr[i] ;
        }

        for(int i = 0 ; i < n ; i++){
            printf("%lld", sum - arr[i]) ; printf(" ") ;
        }

        printf("\n") ;
    }
}
