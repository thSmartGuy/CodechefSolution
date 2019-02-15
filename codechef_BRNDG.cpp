#include <cstdio>
#include <cmath>
#include <algorithm>

int main(){
    int t, n ;
    scanf("%d", &t) ;
    while(t--){
        int days = 0 ;
        scanf("%d", &n) ;
        while(n){
            days++ ;
            n = n - pow(2, std::floor(log2(n))) ;
        }

        printf("%d\n", days) ;
    }
}
