#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int index = 0 ;

struct a{
    std::string s ;
    int age ;
    int idx ;
    a(){
        idx = index++ ;
    }
};

a arr[MAX] ;
a ans[MAX] ;

bool comp(a p, a q){
    if(p.age != q.age) return p.age < q.age ;
    if(p.s != q.s) return p.s < q.s ;
    return p.idx < q.idx ;
}

bool comp2(std::string p, std::string q){
    FOR(i, 0, std::min(p.size(), q.size())){
        if(p[i] != q[i]) return (int)p[i] < (int)q[i] ;
    }

    return p.size() < q.size() ;
}

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int n, m ;
    while(t--){
        std::cin >> n >> m ;

        FOR(i, 0, n){
            std::cin >> arr[i].s >> arr[i].age ;
        }

        int start = 0, end_ = n - 1 ;
        FOR(i, 0, m){
            if(arr[start].age != arr[end_].age){
                if(arr[start].age < arr[end_].age){
                    ans[i] = (arr[start]) ;
                    start++ ;
                }
                else{
                    ans[i] = (arr[end_]) ;
                    end_-- ;
                }
            }
            else if(arr[start].s != arr[end_].s){
                if(comp2(arr[start].s, arr[end_].s)){
                    ans[i] = (arr[start]) ;
                    start++ ;
                }
                else{
                    ans[i] = (arr[end_]) ;
                    end_-- ;
                }
            }
            else{
                if(arr[start].idx < arr[end_].idx){
                    ans[i] = (arr[start]) ;
                    start++ ;
                }
                else{
                    ans[i] = (arr[end_]) ;
                    end_-- ;
                }
            }
        }

        std::sort(ans, ans + m, comp) ;

        for(int j = 0 ; j < m ; j++){
            std::cout << ans[j].idx << " " ;
        }

        std::cout << "\n" ;
    }
}

