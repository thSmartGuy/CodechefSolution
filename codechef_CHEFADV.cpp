#include <iostream>
#include <cmath>

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int t, n, m, x, y, flag ;
    std::cin >> t ;

    while(t--){
        flag = 0 ;
        std::cin >> n >> m >> x >> y ;

        n--; m--;

        if(n == 0 && m == 0){
            flag = 1 ;
        }

        if((n >= x && m >= y && n%x == 0 && m%y == 0) || (n >= x && m == 0 && n%x == 0) || (m >= y && n == 0 && m%y == 0)){
            flag = 1 ;
        }
        else{
            n-- ; m-- ;

            if(n == 0 && m == 0){
                flag = 1 ;
            }

            if((n >= x && m >= y && n%x == 0 && m%y == 0) || (n >= x && m == 0 && n%x == 0) || (m >= y && n == 0 && m%y == 0)){
                flag = 1 ;
            }
        }

        if(flag == 1){
            std::cout << "Chefirnemo\n";
        }
        else{
            std::cout << "Pofik\n" ;
        }
    }
}
