#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

std::vector <lld> ans ;

void decimal(std::string str){
    int mul = 1 ;
    lld ola = 0 ;
    for(int i = str.size() - 1 ; i >= 0 ; i--){
        ola += (str[i] - '0')*mul ;
        mul *= 2 ;
    }
    ans.push_back(ola) ;
}

void pre(){
    std::string ola ;
    for(int digit = 1 ; digit < 31 ; digit++){
        int period = 1 ;
//        std::cout << "___________________________________________________________________________________________\n" ;
//        std::cout << "digit ::" << digit << "\n" ;
        while(period <= digit){
//            std::cout << "period ::" << period << "\n" ;
            if(digit%period == 0){
                char turn = '0' ;
                ola = "" ;
                while(ola.size() < digit){
                    if(turn == '0'){
                        turn = '1' ;
                    }
                    else{
                        turn = '0' ;
                    }
                    for(int j = 1 ; j <= period ; j++){
                        ola += turn ;
                    }
                }
//                std::cout << ola << "\n" ;
                decimal(ola) ;
            }
            period++ ;
        }
    }

//    std::sort(ans..begin(), ans.end()) ;
}

int main(){
    // fast ;

    int t, l, r ;

    pre() ;

//    FOR(i, 0, ans.size()){
//        std::cout << ans[i] << " " ;
//    }
//    std::cout << "\n" ;

    std::cin >> t ;

    while(t--){
        std::cin >> l >> r ;

        int count_ = 0 ;

        FOR(i, 0, ans.size()){
            if(ans[i] >= l && ans[i] <= r){
                count_++ ;
            }
        }

        std::cout << count_ << "\n" ;
    }
}
