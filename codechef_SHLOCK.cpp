#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE
int arr[MAX] ;

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    std::string s ;
    while(t--){
        std::cin >> s;

        int n = s.size() ;

        FOR(i, 0, n) arr[i] = (int) s[i] - 'a' + 1 ;

        int ans = 0 ;

        FOR(i, 0, n){
            FOR(j, 0, n){
                if(arr[i] + arr[j] == 27){
                    ans = std::max(ans, std::abs(i - j)) ;
                }
            }
        }

        print(ans) ;
    }
}

