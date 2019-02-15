#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1e6 + 5 ;

// CODE FROM HERE
int arr[5] ;
std::vector <int> count_, num ;

int solve(int len, int val){
    int req = 0 ;
    if(len < num.size()){
        FOR(i, len, num.size()){
            req += num[i] ;
        }

        FOR(i, 0, len){
            if(num[i] > val){
                req += num[i] - val ;
            }
        }
        return req ;
    }

    FOR(i, 0, num.size()){
        if(num[i] > val){
            req += num[i] - val ;
        }
    }

    return req ;
}

int main(){
    fast() ;
    int t ;
    std::cin >> t ;

    std::string s ;
    while(t--){
        count_.assign(30, 0) ; num.clear() ;

        std::cin >> s ;

        FOR(i, 0, s.size()) count_[s[i] - 'A']++ ;

        FOR(i, 0, 30) if(count_[i]) num.push_back(count_[i]) ;

        std::sort(num.begin(), num.end()) ; std::reverse(num.begin(), num.end()) ;
        bool equal_ = 1 ;

        {
            int start_ = num[0] ;
            FOR(i, 1, num.size()){
                if(num[i] != start_){
                    equal_ = 0 ; break ;
                }
            }
        }

        if(equal_){
            print("0") ;
            continue ;
        }

        int length = s.size() ;
        int ans = s.size() ;
        FOR(k, 1, std::min(length + 1, 27)){
            if(length%k == 0){  // TO BREAK INTO K LETTERS
               int loc = solve(k, length/k) ; // EACH TERM VALUE SHOULD BE SUM/K

                ans = std::min(ans, loc) ;
            }
        }

        print(ans) ;
    }
}
// JBGGGGGL
