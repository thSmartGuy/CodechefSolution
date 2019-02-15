#include <iostream>
#define rep(i, k, n) for(int i = k ; i < n ; i++)
#include <vector>
#include <climits>

int main(){
    int t, n, k, temp, max_ ;
    std::cin >> t ;
    while(t-->0){
        max_ = INT_MIN ;
        std::cin >> n >> k ;
        std::vector <int> freq(200001, 0) ;
        rep(i, 0, n){
            std::cin >> temp ;
            max_ = std::max(max_, temp) ;
            freq[temp]++ ;
        }

        rep(i, 0, 200001){
            if(freq[i] == 0){
                if(k == 0){
                    std::cout << i << "\n" ;
                    break ;
                }
                k-- ;
            }
        }
    }
}
