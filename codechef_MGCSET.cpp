#include <iostream>
#define rep(n) for(int i = 0 ; i < n ; i++)
#include <vector>

int main(){
    int t, n, m, temp, ans ;
    std::cin >> t ;
    while(t-->0){
        ans = 0 ;
        std::cin >> n >> m ;
        std::vector <int> arr ;
        rep(n){
            std::cin >> temp ;
            if(temp%m == 0){
                ans++ ;
            }
            else{
                arr.push_back(temp) ;
            }
        }
        ans = (std::pow(2, ans) - 1) ;
    }
}
