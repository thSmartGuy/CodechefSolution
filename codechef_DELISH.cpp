#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 11111 ;

// CODE FROM HERE
int arr[MAX] ;

int main(){
     fast() ;

    int t, n, tmp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        bool neg = 0 ;
        FOR(i, 0, n){
            std::cin >> arr[i] ;

            if(arr[i] < 0) neg = 1 ;
        }

        if(!neg){
            lld pref[n], suff[n] ;

            lld l = 0 ;
            FOR(i, 0, n){
                l += arr[i] ;
                pref[i] = l ;
            }

            l = 0 ;
            for(int i = n - 1 ; i >= 0 ; i--){
                l += arr[i] ;
                suff[i] = l ;
            }

            lld max_diff = -1 ;

            FOR(i, 0, n - 1){
                max_diff = std::max(max_diff, std::abs(pref[i] - suff[i + 1])) ;
            }

            print(max_diff) ;
        }
        else{
            std::vector <lld> ans ;

            lld sum = 0 ;

            arr[n] = (arr[n - 1] > 0 ? -1 : 1) ;
            bool neg = false ;
            FOR(i, 0, n + 1){
                if(i == n){
                    ans.push_back(sum) ;
                    break ;
                }

                if(arr[i] > 0 && neg == true){
                    ans.push_back(sum) ;
                    neg = false ;
                    sum = 0 ;
                }

                if(arr[i] < 0 && neg == false){
                    ans.push_back(sum) ;
                    neg = true ;
                    sum = 0 ;
                }

                sum += arr[i] ;
            }

            std::sort(ans.begin(), ans.end()) ;

            print(ans[ans.size() - 1] - ans[0]) ;
        }
    }
}

