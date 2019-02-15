#include <iostream>
#include <cmath>
#include <climits>
typedef long long int lld ;

lld sol[31][31] ;

void init(){
    for(int i = 0 ; i < 31 ; i++){
        for(int j = 0 ; j < 31 ; j++){
            if(i == j){
                sol[i][j] = 0 ;
            }
            else{
                sol[i][j] = pow(2, i) + pow(2, j) ;
            }
        }
    }
}

lld findMin(int n){
    lld min_ = INT_MAX ;
    for(int i = 0 ; i < 31 ; i++){
        for(int j = 0 ; j < 31 ; j++){
            if(i!=j && std::abs(sol[i][j] - n) < min_){
                min_ = std::abs(sol[i][j] - n) ;
                if(min_ == 0){
                    break; break;
                }
            }
        }
    }

    return min_ ;
}

int main(){
    int t, n;
    lld min_ ;
    std::cin >> t ;
    init() ;
    while(t--){
        min_ = INT_MAX ;
        std::cin >> n ;
        min_ = findMin(n) ;
        std::cout << min_ << "\n" ;
    }
}
