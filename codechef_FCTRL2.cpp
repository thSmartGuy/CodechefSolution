#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define scan(n) scanf("%d", &n)
#define rep(i, k, n) for(int i = k ; i < n ; i++)

void calcfact(int n){
    std::vector <int> ans ;
    ans.push_back(1) ;

    rep(i, 1, n + 1){
        rep(j, 0, ans.size()){
            ans[j] = ans[j]*i ;
        }

        rep(j, 0, ans.size()){
            if(ans[j] >= 10){
                if(j == ans.size() - 1){
                    ans.push_back(0) ;
                }

                ans[j + 1] += ans[j]/10 ;
                ans[j] = ans[j]%10 ;
            }
        }
    }

    std::reverse(ans.begin(), ans.end()) ;
    for(auto it : ans){
        std::cout << it ;
    }

    std::cout << "\n" ;
}

int main(){
    int t, n ;
    scan(t) ;
    while(t--){
        scan(n) ;
        calcfact(n) ;
    }
}
