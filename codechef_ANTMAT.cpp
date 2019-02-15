#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, n, m, e1, e2 ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        std::vector <int> connec[n + 1] ;
        //std::cout << "size: " << connec[1].size() << "\n" ;

        FOR(i, 0, m){
            std::cin >> e1 >> e2 ;
            connec[e1].push_back(e2) ;
            connec[e2].push_back(e1) ;
        }

        int ans = 0 ;

        FOR(i, 1, n + 1){
            ans = std::max(ans, (int)connec[i].size()) ;
        }

        if(ans < 3){
            // CHECK IF THEIR IS A TRIANGLE POSSIBLE IF YES THEN INCREASE ANS TO 3 ELSE LEAVE IT AS IT IS
            // IF MORE THEN THREE ARE POSSIBLE THEN WE DONT NEED TO WORRY FOR ANY TRIANGLES FORMATINS AS MAX ANS AND ONLY ANS WE CAN GET
            // FROM TRIANGLE FORMATION IS 3 SO WE SIMPLY DISCARD THE TRIANGLE EVEN IF IT IS FORMING AND TAKE THE VERTEX WITH MAX EDGES
            FOR(i, 1, n + 1){
                FOR(j, 0, connec[i].size()){
                    int end_ = connec[i][j] ;
                    FOR(k, 0, connec[end_].size()){
                        int start_ = connec[end_][k] ;
                        FOR(l, 0, connec[start_].size()){
                            if(connec[start_][l] == i){
                                ans = 3 ;
                                break ; break ;break ;break ;
                            }
                        }
                    }
                }
            }
        }
        std::cout << ans << "\n" ;
    }
}
