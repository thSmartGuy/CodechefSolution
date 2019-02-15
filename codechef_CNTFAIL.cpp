#include <iostream>
#include <map>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;
template <class T> void print(T a){std::cout << a << "\n" ;}
// CODE FROM HERE
int arr[MAX] ;

int main(){
    // fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::map <int, int> mp ;

        bool faulty = 0 ;
        FOR(i, 0, n){
            std::cin >> arr[i] ;
            if(arr[i] >= n)
                faulty = 1 ;
            mp[arr[i]]++ ;
        }

        if(faulty || n == 1 || mp.size() > 2){
            print(-1) ;
            //std::cout << "-1\n" ;
            continue ;
        }

        std::sort(arr, arr + n) ;

        if(arr[0] == arr[n - 1]){
            if(arr[0] == n - 1)
                print(0) ;
                //std::cout << "0\n" ;
            else if(arr[0] == 0)
                print(n) ;
                //std::cout << n << "\n" ;
            else
                print(-1) ;
                //std::cout << "-1\n" ;
        }
        else if(arr[n - 1] - arr[0] > 1){
               print(-1) ;
               //std::cout << "-1\n" ;
        }
        else{
            int one = arr[0] ;
            int fail_ = 0 ;
            int pass_ = 0 ;
            FOR(i, 0, n){
                if(arr[i] != one){
                    fail_++ ;
                }
                else{
                    pass_++ ;
                }
            }

            if(arr[n - 1] != pass_){
                print(-1) ;
                //std::cout << "-1\n" ;
                continue ;
            }

            print(fail_) ;
            //std::cout << fail_ << "\n" ;
        }
    }
}

