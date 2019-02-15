#include <iostream>
#include <set>
const int N = 1e5 + 1 ;

int arr[N] ;

int main(){
    std::set <int> ans ;
    std::ios_base::sync_with_stdio(false) ;

    int t, n, temp ;

    std::cin >> t ;

    while(t--){
        ans.clear() ;
        std::cin >> n ;

        for(int i = 1 ; i <= n ; i++){
            std::cin >> temp ;

            ans.insert(temp) ;
        }

        int count_ = 0 ;
        for(auto itr = ans.begin() ; itr != ans.end() ; itr++){
            if(*itr > n || *itr < 1){
                count_++ ;
            }
        }

        count_ += n - (int)(ans.size()) ;

        std::cout << count_ << "\n" ;
    }
}
