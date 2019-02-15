#include <iostream>
#include <map>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    std::string s ;
    while(t--){
        std::cin >> s ;

        int count_[256] = {0} ;
        int sum_ = 0 ;
        FOR(i, 0, s.size()){
            count_[s[i]]++ ;
        }

        FOR(i, 0, 256) sum_ += count_[i] ;

        bool flag = 1 ;
        FOR(i, 0, 256){
            if((double)count_[i] == (double)sum_/2){
                flag = 0 ;
                break ;
            }
        }

        std::cout << (flag ? "NO\n" : "YES\n") ;
    }
}

