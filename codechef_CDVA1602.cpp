#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 11111 ;

// CODE FROM HERE

std::set <int> ans ;
std::vector <std::vector <int>> tree(MAX) ;
int max_level = 0 ;

void ldfs(int current, int height, int previous = -1){
    if(height > max_level){ // at current depth for the first time
        ans.insert(current) ;
        max_level = height ;
    }

    FOR(i, 0, tree[current].size()){
        if(tree[current][i] != previous){
            ldfs(tree[current][i], height + 1, current) ;
        }
    }
}

void rdfs(int current, int height, int previous = -1){
    if(height > max_level){ // at current depth for the first time
        max_level = height ;
        ans.insert(current) ;
    }

    for(int i = tree[current].size() - 1 ; i >= 0 ; i--){
        if(tree[current][i] != previous){
            rdfs(tree[current][i], height + 1, current) ;
        }
    }
}

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        tree.clear() ; ans.clear() ;
        tree.resize(n + 1) ;

        FOR(i, 1, n){
            int a, b ;
            std::cin >> a >> b ;
            tree[a].push_back(b) ;
            tree[b].push_back(a) ;
        }

        max_level = 0 ;
        ldfs(1, 1) ;
        max_level = 0 ;
        rdfs(1, 1) ;

        for(auto itr : ans)
            std::cout << itr << " " ;
        std::cout << "\n" ;
    }
}
