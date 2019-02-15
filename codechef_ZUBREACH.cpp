#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, n, rx, ry, x, y, yDanger, xDanger ;

    std::cin >> t ;

    std::string move_ ;

    FOR(j, 0, t){
        x = 0, y = 0 ;
        std::cin >> xDanger >> yDanger >> rx >> ry ;

        std::cin >> n ;
        std::cin >> move_ ;

        FOR(i, 0, n){
            if(move_[i] == 'U'){
                y++ ;
            }
            else if(move_[i] == 'D'){
                y-- ;
            }
            else if(move_[i] == 'R'){
                x++ ;
            }
            else{
                x-- ;
            }
        }

        if(x == rx && y == ry){
            std::cout << "Case " << j + 1 << ": REACHED\n" ;
        }
        else if(x > xDanger || x < 0 || y > yDanger || y < 0){
            std::cout << "Case " << j + 1 << ": DANGER\n" ;
        }
        else{
            std::cout << "Case " << j + 1 << ": SOMEWHERE\n" ;
        }
    }
}
