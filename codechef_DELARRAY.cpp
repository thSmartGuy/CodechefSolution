#include <iostream>
#include <algorithm>
const int MAX = 100011 ;

int arr[MAX] ;
bool pre[MAX], suff[MAX] ;

int main(){
    int t ;

    std::cin >> t ;

    while(t--){
        int n ;

        std::cin >> n ;

        for(int i = 1 ; i <= n ; i++) std::cin >> arr[i] ;

        // for prefix -> (0->i) should be strictly increasing
        pre[0] = 1 ;
        arr[0] = -1*(1e9 + 10) ;
        for(int i = 1 ; i <= n ; i++){
            pre[i] = (pre[i - 1] & (arr[i] > arr[i - 1])) ;
        }   

        // for suffix -> (i->n) should be "strictly" increasing
        suff[n + 1] = 1 ;
        arr[n + 1] = (1e9 + 10) ;
        for(int i = n ; i >= 1 ; i--){
            suff[i] = (suff[i + 1] & (arr[i] < arr[i + 1])) ;
        }

        long long ans = 0 ;
        
        //for(int i = 1 ; i <= n ; i++) std::cout << pre[i] << " " ; std::cout << "\n" ;
        //for(int i = 1 ; i <= n ; i++) std::cout << suff[i] << " " ; std::cout << "\n" ;

        // continuous subarray deletion from 1th to last idx
        // last idx which have suffix = 0 will give us 1 subarray and (1...lastIdxWithSuffix0 + 1) will be another 
        // subarray that can provide us with req sequence ie..all increaseing ....and so on 
        // so total contri will be n - lo 
        // keep in mind that it is 1 indexed
        int lo = 0, hi = n + 1;
        while (hi - lo > 1){
            int mid = (lo + hi) >> 1;
            if (suff[mid])
                hi = mid;
            else
                lo = mid;
        }
        ans = (n - lo);
        //std::cout << "lo " << lo << " value : " << arr[lo] << "\n" ;

        for(int i = 1 ; i <= n - 1 ; i++){ 
            if(pre[i]){ // till pre we have no problem(already sorted)
                // what we did for deleting from starting to last suffix having 0
                // now we will do it for deletion from (i...lastSuffixHavng0or1 and arr[lastSuffixHavng0or1 + 1] > arr[i])
                int lo = i + 1, hi = n + 1;
                while (hi - lo > 1){
                    int mid = (lo + hi) >> 1;
                    if (suff[mid] == 1 and arr[mid] > arr[i])
                        hi = mid;
                    else
                        lo = mid;
                }
                ans += n - lo + 1; //*/
            }
            else break ;
        }
        // if the array is completely soreted than we have to take care of that situation 
        // for example for : 1 2 3
        // deletion from start :: {2 3}, {3} || what our function calculated =>> 3 when actual contribution will be two
        // thats why we need to handle that case by subtract pre[n] .. ie if array is completely sorted 
        // subtract 1 else the value of pre[0] ==> 0 so no effect
        std::cout << ans - pre[n] << "\n" ;
    }
}
