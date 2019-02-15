#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111 ;
// CODE FROM HERE

struct group{
    std::string pr ;
    int val ;
};

bool comp(group p, group q){
    if(p.pr.size() == q.pr.size()){
        return p.val > q.val ;
    }
    return p.pr.size() < q.pr.size() ;
}

bool comp2(group p, group q){
    return p.val < q.val ;
}

group prettyVal[MAX], good[11111] ;

int main(){
    int n, m, a, x, r ;
    std::string s ;

    std::cin >> n >> m >> a >> x >> r ;

    std::cin >> s ;

    FOR(i, 0, m){
        std::cin >> prettyVal[i].pr >> prettyVal[i].val ;
    }

    FOR(i, 0, a){
        std::cin >> good[i].pr >> good[i].val ;
    }

    lld cost = 0, curSize = s.size() ;
    int op = 0 ;

    while(cost < x - r && curSize <= 1e6){
        cost += good[0].val ;
        op++ ;
        curSize += good[0].pr.size() ;
    }

    if(curSize > 1e6){
        op-- ;
        curSize -= good[0].pr.size() ;
    }

//        if(curSize != 1e6) op++ ;

//    std::cout << "1\n3 1 " << s.size() << "\n" ;
//    std::cout << op << "\n" ;
//
//    FOR(i, 0, op){
//        std::cout << "2 1 1 1\n" ;
//    }
//
//        if(op){
//            int allExp = 1000000 - curSize ;
//
//            int q1 = 1, q2 = allExp - 1 ;
//            if(q2 > curSize) q2 = curSize ;
//
//            std::cout << "3 " << q1 << " " << q2 << "\n" ;
//        }
}

