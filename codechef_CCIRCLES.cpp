#include <iostream>
#include <cmath>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int x[1111], y[1111], r[1111] ;
// double ans[1111][1111][2] ; // [0 -> range start : 1 -> range end] ==> both included
double dist[1111][1111] ;
long ans[1111111] ;

void pre(int n){
    for(int i = 0 ; i < 1111111 ; i++)
        ans[i] = 0 ;

    double minimum, maximum ;
    double d, r1, r2, x1, y1, x2, y2 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            x1 = x[i] ;
            y1 = y[i] ;
            x2 = x[j] ;
            y2 = y[j] ;
            r1 = r[i] ;
            r2 = r[j] ;
            if(r2 > r1){
                std::swap(r1, r2) ;
            }

            d = std::sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1)) ;

            dist[i][j] = d ;
            if(r1 + r2 > d && d > std::abs(r1 - r2)){ // circles are intersecting ? ==>> range -> [0:?]
                minimum = 0 ; // minimum distance is 0 ;

                // d == r1 == r2 || d == r1 && d != r2 || d == r2 && d != r1 || d != r1 && d != r2
                //ans[i][j][1] = (double) d + r1 + r2 ;
            }
            else{ // circles are seperated ? ==>> range -> [?:?]
                if(r1 + r2 > d){ // internal
                    minimum = (double) r1 - r2 - d ; // minimum
                    //ans[i][j][1] = (double) r1 - r2 + d ; // maximum // XXXXXX WRONG POINT HERE XXXXXX
                }
                else{ // external
                    minimum = (double) d - r1 - r2 ; // minimum
                    //ans[i][j][1] = (double) d + r1 + r2 ; // maximum
                }
            }

            // CORRECTION = >> MAXIMUM IS ALWAYS D + R1 + R@
            maximum = (double) d + r1 + r2 ;

        //    std::cout << "[" << std::ceil(minimum) << " : " << std::floor(maximum) << "] " ;
            ans[(int)std::ceil(minimum)]++;
            ans[(int)std::floor(maximum) + 1]-- ;
        }
    }
    //std::cout << "\n" ;

    lld add = 0 ;
    for(int i = 0 ; i < 1111110 ; i++){
        add += ans[i] ;

        ans[i] = add ;
    }
}

int main(){
    fast ;

    int n, q, k ;

    std::cin >> n >> q ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> x[i] >> y[i] >> r[i] ;
    }

    pre(n) ;

//    for(int i = 0 ; i < 30 ; i++){
//        std::cout << "i: " << i << " " << ans[i] << "\n" ;
//    }
//    std::cout << "\n" ;

    while(q--){
        std::cin >> k ;

        std::cout << ans[k] << "\n" ;
    }
}
