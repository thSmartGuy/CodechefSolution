#include <iostream>
#include <vector>

std::vector <int> arr[100001] ;

void pre(){
    for(int i = 0 ; i <= 100000 ; i++){
        if(i <= 4)
            arr[i].resize(100001) ;
        else{
            arr[i].resize(4) ;
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ; std::cout.tie(NULL) ;

    int t, n, m, q, x, y ;
    std::string row, col ;
    pre() ;
    std::cin >> t ;

    while(t--){
        std::cin >> col >> row ;
        n = col.size() ;
        m = row.size() ;


        for(int i = 1 ; i <= n ; i++){
            arr[0][i] = (int)(col[i - 1] - '0') ;
        }

        for(int i = 1 ; i <= m ; i++){
            arr[i][0] = (int)(row[i - 1] - '0') ;
        }

        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n && j < arr[i].size() ; j++){
                arr[i][j] = 1 ^ (arr[i - 1][j] & arr[i][j - 1]);
            }
        }

        /*
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n && j < arr[i].size() ; j++){
                std::cout << arr[i][j] << " " ;
            }
            std::cout << "\n" ;
        }*/

        std::cin >> q ;
        while(q--){
            std::cin >> x >> y ;
            int diff = std::min(x, y) - 3 ;
            if(diff > 0){
                x -= diff ;
                y -= diff ;
            }

            std::cout << arr[x][y] ;
        }
        std::cout << "\n" ;
    }
}
