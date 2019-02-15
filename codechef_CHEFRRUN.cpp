#include <iostream>
#include <set>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int arr[MAX] ;

int main(){
    fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int tmp ;
        FOR(i, 0, n){
            std::cin >> tmp ;

            arr[i] = (i + 1 + tmp)%n ;
        }

        int ans = 0 ;
        FOR(i, 0, n){
            std::set <int> st ;
            st.insert(i) ;

            int nxt = arr[i] ;

            while(st.find(nxt) == st.end()){
                st.insert(nxt) ;
                nxt = arr[nxt] ;
            }

            if(nxt == i) ans++ ;
        }

        std::cout << ans << "\n" ;
    }
}

