#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

int arr[MAX] ;
int maxlr[MAX], maxrl[MAX], prefix[MAX], suffix[MAX] ;

void pre(int n){
    int count_ = 0, max_ = 0 ;
    // FOR LEFT-RIGHT
    FOR(i, 0, n){
        if(arr[i] == 0){
            count_ = 0 ;
        }
        else{
            count_++ ;
        }
        if(count_ > max_){
            max_ = count_ ;
        }
        maxlr[i] = max_ ;
    }
//    FOR(i, 0, n)
//        std::cout << maxlr[i] << " " ;
//    std::cout << "\n" ;

    // FOR RIGHT-LEFT
    max_ = 0 ; count_ = 0 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(arr[i] == 0){
            count_ = 0 ;
        }
        else{
            count_++ ;
        }
        if(count_ > max_){
            max_ = count_ ;
        }
        maxrl[i] = max_ ;
    }
//
//    FOR(i, 0, n)
//        std::cout << maxrl[i] << " " ;
//    std::cout << "\n" ;

    // FOR PREFIX ARRAY
    max_ = 0 ; bool flag = 1 ;
    FOR(i, 0, n){
        if(arr[i] && flag){
            max_++ ;
        }

        if(arr[i] == 0)
            flag = 0 ;

        prefix[i] = max_ ;
    }
//
//    FOR(i, 0, n)
//        std::cout << prefix[i] << " " ;
//    std::cout << "\n" ;

    max_ = 0 ; flag = 1 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(arr[i] && flag){
            max_++ ;
        }

        if(arr[i] == 0){
            flag = 0 ;
        }

        suffix[i] = max_ ;
    }


//    FOR(i, 0, n)
//        std::cout << suffix[i] << " " ;
//    std::cout << "\n" ;
}

int main(){
    fast ;

    std::string query ;
    int n, q, k ;

    std::cin >> n >> q >> k ;

    for(int i = 0 ; i < n ; i++){
        std::cin >> arr[i] ;
    }

    pre(n) ;

    std::cin >> query ;

    int shift = 0 ;
    int ans = 0 ;
    FOR(i, 0, q){
        if(query[i] == '!'){
            shift++;
            shift %= n ;
        }
        else{
            if(shift != 0){
                ans = std::min(k, std::max(std::max(maxlr[n - shift - 1], maxrl[n - shift]), prefix[n - shift - 1] + suffix[n - shift])) ;
            }
            else{
                ans = std::min(k, maxlr[n - 1]) ;
            }
            std::cout << ans << "\n" ;
        }
    }
}
