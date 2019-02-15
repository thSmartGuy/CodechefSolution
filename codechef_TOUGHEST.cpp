#include <iostream>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int checkDisvisibleByThree(std:: string n){
    lld no = 0 ;
    for(int i = 0 ; i < n.size() ; i++){
        no += (n[i] - '0')%3 ;
    }

    if(no%3 == 0){
        return 1 ;
    }

    return 0 ;
}

int main(){
    fast ;

    int n ;

    std::cin >> n ;

    std::string arr[n] ;

    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        std::cin >> arr[i] ;

        ans += checkDisvisibleByThree(arr[i]) ;
    }

    std::cout << ans ;
}

