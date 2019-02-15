#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define first x
#define second y

typedef long long int lld  ;

int arr[1111][1111] ;

int main(){
    fast ;

    int t, n, m, q, a, b, x, y ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                std::cin >> arr[i][j] ;
            }
        }

        lld sumArray[n + 1][m + 1] ;

        for(int i = 0 ; i < m + 1 ; i++){
            sumArray[0][i] = 0 ;
        }


        for(int i = 0 ; i < n + 1 ; i++){
            sumArray[i][0] = 0 ;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                sumArray[i][j] = arr[i][j] + sumArray[i - 1][j] + sumArray[i][j - 1] - sumArray[i - 1][j - 1] ;
            }
        }

  /*      std::cout << "\n\n" ;
        for(int i = 0 ; i < n + 1 ; i++){
            for(int j = 0 ; j < m + 1 ; j++){
                std::cout << sumArray[i][j] << " " ;
            }
            std::cout << "\n" ;
        }
*/
        std::cin >> q ;

        lld ans ;
        while(q--){
            std::cin >> a >> b >> x >> y ;

            ans = sumArray[x][y] - sumArray[x][b - 1] - sumArray[a - 1][y] + sumArray[a- 1][b - 1] ;
            std::cout << ans << "\n" ;
        }
    }
}

