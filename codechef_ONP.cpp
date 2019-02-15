#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;
    int t ;

    std::cin >> t ;
    std::string expr ;

    while(t--){
        std::cin >> expr ;

        std::vector <char> stack_ ;

        FOR(i, 0, expr.size()){
            if(expr[i] == '(' || expr[i] == ')' || expr[i] == '*' || expr[i] == '/' || expr[i] == '+' || expr[i] == '-' || expr[i] == '^'){
                if(expr[i] == ')'){
                    int j = stack_.size() - 1 ;
                    while(stack_[j] != '('){
                        std::cout << stack_[j] ;
                        stack_.pop_back() ;
                        j-- ;
                    }
                    stack_.pop_back() ;
                }
                else{
                    stack_.push_back(expr[i]) ;
                }
            }
            else{
                std::cout << expr[i] ;
            }
        }
        std::cout << "\n" ;
    }
}

