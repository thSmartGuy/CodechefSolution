#include <iostream>
#include <cmath>

std::pair <double, double> ansArray[1111][1111] ;
double xArray[1111], yArray[1111], rArray[1111] ;
double dist[1111][1111] ;

void pre(int n){
    double d, r1, r2, x1, y1, x2, y2 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            if(i == j){
                ansArray[i][j].first = 0 ;
                ansArray[i][j].second = 0 ;
            }
            else{
                x1 = xArray[i] ;
                y1 = yArray[i] ;
                x2 = xArray[j] ;
                y2 = yArray[j] ;

                d = std::sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1)) ;
                r1 = rArray[i] ; r2 = rArray[j] ;

                dist[i][j] = d ;
                if(r1 + r2 < d){
                    ansArray[i][j].first = d - r1 - r2 ;
                    ansArray[i][j].second = d + r1 + r2 ;
                }
                else{
                    if(d == r1 + r2){
                        ansArray[i][j].first = 0 ;
                        ansArray[i][j].second = d + r1 + r2 ;
                    }
                    else if(d == std::max(r1, r2)){
                        ansArray[i][j].first = 0 ;
                        ansArray[i][j].second = d + r1 + r2 ;
                    }
                    else if(r1 == r2 && d == r1){
                        ansArray[i][j].first = 0 ;
                        ansArray[i][j].second = d + r1 + r2 ;
                    }
                    else if(d < std::max(r1, r2) && d > 0){
                        ansArray[i][j].first = std::max(r1, r2) - d - std::min(r1, r2) ;
                        ansArray[i][j].second = d + r1 + r2 ;
                    }
                    else{ // d == 0
                        ansArray[i][j].first = std::abs(r1 - r2) ;
                        ansArray[i][j].second = std::abs(r1 - r2) ;
                    }
                }
            }
        }
    }
}

int main(){
    int n, q, x, y, r, k ;

    std::cin >> n >> q ;

    for(int i = 1 ; i <= n ; i++){
        std::cin >> x >> y >> r ;

        xArray[i] = x ;
        yArray[i] = y ;
        rArray[i] = r ;
    }

    pre(n) ;

    int ans ;
    while(q--){
        ans = 0 ;
        std::cin >> k ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                if(dist[i][j] == 0){
                    if(rArray[i] == rArray[j]){
                        //pass
                    }
                    else{
                        if(k >= ansArray[i][j].first && k <= ansArray[i][j].second){
                            ans++ ;
                        }
                    }
                }
                else{
                    if(k >= ansArray[i][j].first && k <= ansArray[i][j].second){
                        ans++ ;
                    }
                }
            }
        }

        std::cout << ans << "\n" ;
    }
}
