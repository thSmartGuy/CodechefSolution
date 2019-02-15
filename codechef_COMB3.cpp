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

struct a{
    int val, idx, partner ;
    a(){
        partner = MAX ;
    }
};

a arr[MAX] ;

bool comp(a p, a q){
    if(p.val == q.val)
        return p.idx < q.idx ;
    return p.val < q.val ;
}

int kills[MAX] = {} ;

int main(){
     fast() ;

    lld n, k ;

    std::cin >> n >> k ;

    std::map <int, int> mp ;

    FOR(i, 1, n + 1){
        std::cin >> arr[i].val ;
        mp[arr[i].val]++ ;
        arr[i].idx = i ;
    }

    int x, y ;
    FOR(i, 0, k){
        std::cin >> x >> y ;

        arr[x].partner = arr[y].val ;
        arr[y].partner = arr[x].val ;
    }

    std::sort(arr + 1, arr + n + 1, comp) ;

//    FOR(i, 1, n + 1){
//        std::cout << arr[i].val << " " << arr[i].idx << " " << arr[i].partner << "\n" ;
//    }

    FOR(i, 1, n + 1){
        if(arr[i].partner == MAX){
            kills[arr[i].idx] = i - 1 ;
            int count_ = 0 ;
            int j = i - 1 ;
            while(arr[j].val == arr[i].val){
                count_ ++ ;
                j-- ;
            }

            kills[arr[i].idx] -= count_ ;
        }
        else{
            if(arr[i].partner <= arr[i].val){
                if(arr[i].partner != arr[i].val){
                    kills[arr[i].idx] = i - 2 ;
                    int count_ = 0 ;
                    int j = i - 1 ;
                    while(arr[j].val == arr[i].val){
                        count_ ++ ;
                        j-- ;
                    }

                    kills[arr[i].idx] -= count_ ;
                }
                else{
                    kills[arr[i].idx] = i - 1 ;
                    int count_ = 0 ;
                    int j = i - 1 ;
                    while(arr[j].val == arr[i].val){
                        count_ ++ ;
                        j-- ;
                    }

                    kills[arr[i].idx] -= count_ ;
                }
            }
            else{
                kills[arr[i].idx] = i - 1 ;
                int count_ = 0 ;
                int j = i - 1 ;
                while(arr[j].val == arr[i].val){
                    count_ ++ ;
                    j-- ;
                }

                kills[arr[i].idx] -= count_ ;
            }
        }

        kills[arr[i].idx] = std::max(kills[arr[i].idx], 0) ;
    }

    FOR(i, 1, n + 1) std::cout << kills[i] << " " ;
}

