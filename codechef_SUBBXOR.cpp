#include <bits/stdc++.h>
using namespace std ;

struct node {
    node *zero, *one ;
    long long count[2] ;
    
    node(){
        zero = one = NULL ;
        count[0] = count[1] = 0 ;
    }
};

long long ans ;

void count(node *root, long long num, long long B, long long level){
    if(level == -1 || !root) return ;
    
    char curIdx = ((num & (1ll << level)) ? '1' : '0') ;
    char bIdx = ((B & (1ll << level)) ? '1' : '0') ;
    
    if(curIdx == bIdx) {
        if(bIdx == '1'){   // if bi == curi == 1 then all subtree starting with 1 will be added to answer as 1^1 == 0 < 1(bi)
            ans += root -> count[1] ;
        }
        count(root->zero, num, B, level - 1) ;
    }
    else{
        if(bIdx == '1'){ // if bi == 1 && curi == 0 then all subtree starting with 0 will be added to answer as 0^0 == 0 < 1(bi)
            ans += root -> count[0] ;
        }
        count(root->one, num, B, level - 1) ;
    }
    return ;
}

void insert(node *root, long long num, long long level){
    if(level == -1) return ;
    
    char a = (num & (1ll << level) ? '1' : '0') ;
    
    if(a == '0'){
        if(!root -> zero){
            root -> zero = new node() ;
        }
        root->count[0]++ ;
        insert(root->zero, num, level - 1) ;
    }
    else{
        if(!root -> one){
            root -> one = new node() ;
        }
        root->count[1]++ ;
        insert(root->one, num, level - 1) ;
    }
}

long long solve(std::vector<int> &A, int B) {
    long long tmp = 0 ;
    ans = 0 ;
    
    node *root = new node() ;
    for(int a: A) {
        tmp ^= a ;
        
        count(root, tmp,  B, 30) ;
        insert(root, tmp, 30) ;
    }
    count(root, 0, B, 30) ;
    
    return ans ;
}

int main() {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0) ; std::cout.tie(0) ; 
    
    int t;
    std::cin >> t ;
    
    int n, k ;
    std:vector <int> arr ;
    while(t--){
        std::cin >> n >> k ;
        arr.resize(n) ;
        
        for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;
        std::cout << solve(arr, k) << "\n" ;
    }
}