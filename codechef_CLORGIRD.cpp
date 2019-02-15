#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int mat[1111][1111] ;

bool possible(int i, int j){
    if(mat[i][j] == 0 || mat[i][j + 1] == 0 || mat[i + 1][j] == 0 || mat[i + 1][j + 1] == 0){ // CONTAINS OBSTACLES
        return false ;
    }
    return true ;
}

void fill_(int i, int j){ // FILL WITH OBSTACLES AKA 0
    mat[i][j] = 5 ;
    mat[i][j + 1] = 5 ;
    mat[i + 1][j] = 5 ;
    mat[i + 1][j + 1] = 5 ;
}

int main(){
    fast ;

    int t, n, m ;
    char c ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                std::cin >> c ;
                if(c == '.'){
                    mat[i][j] = 1 ; // empty
                }
                else{
                    mat[i][j] = 0 ; // obstacle
                }
            }
        }

        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = 0 ; j < m - 1 ; j++){
                if(possible(i, j)){
                    fill_(i, j) ; // fill all with 0 SAME AS MARKING AS FILLED
                }
            }
        }

        bool possible_ = 1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1){
                    possible_ = false ;
                    break ;
                    break ;
                }
            }
        }

        if(possible_){
            std::cout << "YES\n" ;
        }
        else{
            std::cout << "NO\n" ;
        }
    }
}

