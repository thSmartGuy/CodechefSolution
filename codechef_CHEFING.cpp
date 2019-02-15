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
int arr[MAX][26] ;

void init(){
    FOR(i, 0, MAX){
        FOR(j, 0, 26){
            arr[i][j] = 0 ;
        }
    }
}

int main(){
     fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        init() ;

        std::string s ;
        FOR(i, 0, n){
            std::cin >> s ;

            FOR(j, 0, s.size()){
                arr[i][s[j] - 'a']++ ;
            }
        }

        int ans = 26 ;

        FOR(j, 0, 26){
            FOR(i, 0, n){
                if(arr[i][j] == 0){
                    ans-- ;
                    break ;
                }
            }
        }

        print(ans) ;
    }
}

