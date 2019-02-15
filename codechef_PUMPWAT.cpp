#include <iostream>
#include <stack>
#include <climits>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

std::vector <std::pair <int, int>> arr(MAX) ;
std::stack <std::pair<int, int>> s ;
int rightFacing[MAX], leftFacing[MAX] ;

// LEARNED ABOUT NEXT GREATER ELEMENT
int main(){
    fast ;
    int t, n ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n){
            std::cin >> arr[i].first ;
            arr[i].second = i ;
        }


        s.push(arr[0]) ;
        FOR(i, 1, n){
            if(s.empty()){
                s.push(arr[i]) ;
            }
            else{
                while(!s.empty() && s.top() < arr[i]){
                    rightFacing[s.top().second] = i ;
                    s.pop() ;
                }
                s.push(arr[i]) ;
            }
        }

        while(!s.empty()){
            rightFacing[s.top().second] = -1 ;
            s.pop() ;
        }


        s.push(arr[n - 1]) ;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(s.empty()){
                s.push(arr[i]) ;
            }
            else{
                while(!s.empty() && s.top() < arr[i]){
                    leftFacing[s.top().second] = i ;
                    s.pop() ;
                }

                s.push(arr[i]) ;
            }
        }
        while(!s.empty()){
            leftFacing[s.top().second] = -1 ;
            s.pop() ;
        }

        int rPumps[n] = {}, lPumps[n] = {} ;

        // FOR RIGHT FACING PUMPS
        int jump ;
        for(int i = n - 1 ; i >= 0 ; i--){
            jump = rightFacing[i] ;
            if(jump != -1)
                rPumps[i] = 1 + rPumps[jump] ;
            else
                rPumps[i] = 1 ;
        }

        // FOR LEFT FACING PUMPS
        for(int i = 0 ; i < n ; i++){
            jump = leftFacing[i] ;
            if(jump != -1){
                lPumps[i] = 1 + lPumps[jump] ;
            }
            else{
                lPumps[i] = 1 ;
            }
        }

        if(rPumps[0] == 1 || lPumps[n - 1] == 1){
            std::cout << 1 << "\n" ;
        }
        else{
            int ans = INT_MAX ;

            FOR(i, 0, n - 1){
                if(lPumps[i] + rPumps[i + 1] < ans){
                    ans = lPumps[i] + rPumps[i + 1] ;
                }
            }

            if(lPumps[n - 1] < ans){
                ans = lPumps[n - 1] ;
            }

            if(rPumps[0] < ans){
                ans = rPumps[0] ;
            }

            std::cout << ans << "\n" ;
        }
    }
}
