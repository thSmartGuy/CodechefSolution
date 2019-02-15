#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    int t, n ;
    int right ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        int a, b, c, d ;

        std::cout << "1 1 2 3\n" ;
        std::cin >> a ;
        std::cout << "1 1 2 4\n" ;
        std::cin >> b ;
        std::cout << "1 3 4 5\n" ;
        std::cin >> d ;
        std::cout << "1 3 4 6\n" ;
        std::cin >> c ;

        int ans[n + 1] ;
        ans[6] = a^b^c ;
        ans[5] = a^b^d ;

        int temp ;
        FOR(i, 5, n - 1){
            std::cout << "1 " << i << " " << i + 1 << " " << i + 2 << "\n" ;
            std::cin >> temp ;
            ans[i + 2] = ans[i]^ans[i + 1]^temp ;
        }
        // 1 n - 2 n - 1 n
//        1 => 2 2 => 2 3 => 3  4 => 3 5 => 1 6 => 1

        std::cout << "1 " << n - 1 << " " << n << " 1\n" ;
        std::cin >> temp ;
        ans[1] = temp^ans[n]^ans[n - 1] ;


        std::cout << "1 2 5 " << n << "\n" ; //" << n - 1 << " " << n << " 2\n" ;
        std::cin >> temp ;
        ans[2] = temp^ans[5]^ans[n] ;
        // b ==> 1 2 4
        ans[4] = b^ans[2]^ans[1] ;
        // a ==> 1 2 3
        ans[3] = a^ans[1]^ans[2] ;

        std::cout << "2" ;
        FOR(i, 1, n + 1){
            std::cout << " " << ans[i] ;
        }
        std::cout << "\n" ;

        std::cin >> right ;
    }
}
