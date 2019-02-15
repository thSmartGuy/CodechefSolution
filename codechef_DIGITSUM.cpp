#include <iostream>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

int digitSum(int n){
    if(n%9 == 0)
        return 9 ;

    return n%9 ;
}

int main(){
    fast ;
    int t, m, n, x, ans ;

    std::cin >> t ;

    while(t--){
        ans = 0 ;
        std::cin >> m >> n >> x ;

        if(n - m + 1 < 9){
            for(int i = m ; i <= n ; i++){
                if(digitSum(i) == x){
                    ans++ ;
                    break ;
                }
            }
        }
        else{
            ans = (n - m + 1)/9 ;
           // std::cout << "ans : " << ans << "\n" ;

            for(int i = m + 9*ans ; i <= n ; i++){
                if(digitSum(i) == x){
                    ans++ ;
                    break ;
                }
            }
        }

        std::cout << ans << "\n" ;
    }
}
