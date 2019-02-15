#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE

bool eval(std::string s){
    lld a = 0 ;

    int i = 0 ;
    char first, sec ;
    for(i; i < s.size() ; i++){
        a += (int)(s[i] - '0') ;
        if(s[i + 1] != '+' && s[i + 1] != '-'){
            a *= 10 ;
        }
        else{
            first = s[i + 1] ;
            i+=2 ;
            break ;
        }
    }

//    std::cout << "first " << first << "\n" ;

    lld b = 0 ;
    for(i; i < s.size() ; i++){
        b += (int)(s[i] - '0') ;
        if(s[i + 1] != '+' && s[i + 1] != '-'){
            b *= 10 ;
        }
        else{
            sec = s[i + 1] ;
            i+=2 ;
            break ;
        }
    }

    lld c = 0 ;
    for(i; i < s.size() ; i++){
        c += (int)(s[i] - '0') ;
        if(s[i + 1] != '='){
            c *= 10 ;
        }
        else{
            i+=2 ;
            break ;
        }
    }
//    std::cout << "sec " << sec << "\n" ;

    lld ans = 0 ;
    ans+= a ;
    ans += (first == '-' ? -1*b : b) ;
    ans += (sec == '-' ? -1*c : c) ;
//    std::cout << "ans: " << ans << "\n" ;

    lld res = 0 ;
    for(i; i < s.size() ; i++){
        res += (int)(s[i] - '0') ;
        if(s[i + 1] != '=' && i + 1 != s.size()){
            res *= 10 ;
        }
        else{
            i+=2 ;
            break ;
        }
    }

    return res == ans ;
}

int main(){
    // fast() ;

    int t ;

    std::cin >> t ;

    std::string s ;
    while(t--){
        std::cin >> s ;

        std::cout << (eval(s) ? "Valid Equation\n" : "Invalid Equation\n") ;
    }
}
