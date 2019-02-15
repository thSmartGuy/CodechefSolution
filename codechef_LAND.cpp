#include <iostream>
#include <set>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111 ;

// CODE FROM HERE

int arr[MAX][MAX] ;

int main(){
     fast() ;

    int t ;

    std::cin >> t ;

    int n, m ;
    while(t--){
        std::cin >> n >> m ;

        bool allEmpty = 1 ;
        std::set <int> s ;
        FOR(i, 0, n){
            FOR(j, 0, m){
                std::cin >> arr[i][j] ;
                if(arr[i][j] != 0) allEmpty = 0 ;
                if(arr[i][j] != 0) s.insert(arr[i][j]) ;
            }
        }

        if(allEmpty){
            FOR(i, 0, n){
                FOR(j, 0, m){
                    std::cout << "1 " ;
                }
                std::cout << "\n" ;
            }
            continue ;
        }

        if(s.size() == 1){
            FOR(i, 0, n){
                FOR(j, 0, m){
                    for(auto itr : s) std::cout << itr << " " ;
                }
                std::cout << "\n" ;
            }
            continue ;
        }

        int sum_ = (int)rand()%30 + 1 ;

        FOR(i, 0, n){
            FOR(j, 0, m){
                if(arr[i][j] == 0){
                    std::cout << sum_ << " " ;
                }
                else std::cout << arr[i][j] << " " ;
            }
            std::cout << "\n" ;
        }
    }
}

