#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t ;
    std::string str ;

    std::cin >> t ;

    while(t--){
        std::cin >> str ;

        if(str.size()%2 != 0){ // odd
            std::cout << "no\n" ;
        }
        else{
//            if(str.size() == 1){
//                std::cout << "yes\n" ;
//                continue ;
//            }

            int r = 0, g = 0 ;
            FOR(i, 1, str.size()){
                if(str[i] == 'R' && str[i - 1] == 'R'){
                    r++ ;
                }
                if(str[i] == 'G' && str[i - 1] == 'G'){
                    g++ ;
                }
            }
            if(str[0] == 'R' && str[str.size() - 1] == 'R'){
                r++ ;
            }
            if(str[0] == 'G' && str[str.size() - 1] == 'G'){
                g++ ;
            }

            //std::cout << r << " " << g << "\n" ;

            if(r > 1 || g > 1){
                std::cout << "no\n" ;
            }
            else{
                if(r && !g || !r && g){ // nothing to reppace with r == g == 1 fr equal
                    std::cout << "no\n" ;
                }
                else{
                    std::cout << "yes\n" ;
                }
            }
        }
    }
}
