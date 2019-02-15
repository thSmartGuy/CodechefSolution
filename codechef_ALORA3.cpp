#include <iostream>
#include <map>
#include <vector>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 26 ;

// CODE FROM HERE
int main(){
    fast() ;
    int t, n, m ;
    std::string s ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        std::cin >> s ;

        int dp[26][26] ;
        FOR(i, 0, 26){
            FOR(j, 0, 26){
                dp[i][j] = (i == j) ;
            }
        }

        char a, b ;
        FOR(i, 0, m){
            std::cin >> a >> b ;
            dp[a - 'a'][b - 'a'] = 1 ;
        }

        FOR(k, 0, 26){
            FOR(i, 0, 26){
                FOR(j, 0, 26){
                    if(!dp[i][j]){
                        dp[i][j] = dp[i][k] & dp[k][j] ;
                    }
                }
            }
        }

        int alpha[26] ;

        FOR(i, 0, 26){
            FOR(j, 0, i + 1){
                if(dp[i][j]){
                    alpha[i] = j ;
                    break ;
                }
            }
        }

        FOR(i, 0, s.size()){
            s[i] = (char)(alpha[(int)(s[i] - 'a')] + 'a') ;
        }

        print(s) ;
    }
}

