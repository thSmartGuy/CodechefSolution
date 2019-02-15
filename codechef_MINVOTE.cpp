#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld ;

int arr[1111111] ;
lld sum[1111111] ;

int main(){
    fast ;

    int t, n, low, high, where, mid ;

    std::cin >> t ;

    lld l ;
    while(t--){
        std::cin >> n ;

        l = 0 ;
        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
            sum[i] = (lld)(l + arr[i]) ;
            l = sum[i] ;
        }

        std::vector <int> ans(n + 1, 0) ;

        for(int i = 0 ; i < n ; i++){ // i ==>> VOTER
            // KHA TAK KA VOTE DEGA PATA LAGAO
            // APNE SE PICHE WALO ME

            low = 0 ; high = i - 1 ; where = i ;

            while(low <= high){
                mid = low + (high - low)/2 ;

                if(sum[i - 1] - sum[mid] > arr[i]){
                    low = mid + 1 ;
                }
                else{
                    where = mid ;
                    high = mid - 1 ;
                }
            }
            ans[where]++;
            ans[i]--;


            // AAPNE SE AAGE WALO ME
            low = i ; high = n - 1 ; where = i + 1 ; // where is denoting atleast side wale ko vote to dega hi

            while(low <= high){
                mid = low + (high - low)/2 ;

                if(sum[mid - 1] - sum[i] > arr[i]){
                    high = mid - 1 ;
                }
                else{
                    where = mid ;
                    low = mid + 1 ;
                }
            }
            ans[i + 1]++;
            ans[where + 1]--;

        }

        l = 0 ;
        for(int i = 0 ; i < n ; i++){
            l += ans[i] ;
            std::cout << l << " " ;
        }
        std::cout << "\n" ;
    }
}
