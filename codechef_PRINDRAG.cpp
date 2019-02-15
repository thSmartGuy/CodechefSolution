#include <iostream>
#include <algorithm>
#include <climits>
typedef long long int lld ;

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie() ; std::cout.tie() ;

    int t, n, p, ans, flag ;
    std::cin >> t ;

    while(t-->0){
        std::cin >> n >> p ;
        int arr[n] ;
        int max_ = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
            max_ = std::max(max_, arr[i]) ;
        }
  //      std::cout << sum << "\n" ;
        std::sort(arr, arr + n) ;
        std::reverse(arr, arr + n) ;

        int ans[n] = {} ;

        lld l_sum, r_sum ;
        int l_index, r_index, j ;


        for(int i = 0 ; i < n ; i++){
            l_index = i ; r_index = i ; l_sum = arr[0] ; r_sum = arr[0] ;
            j = 0 ;
//                while(j <= n - 1)
            if(n - i > i){ // add to right
                while(r_sum < p && r_index <= n - 1 && j <= n - 1){
                    if(r_index+1 == n)
                        r_index = n ;
                    else{
                        r_sum += arr[++j] ;
                        r_index++ ;
                    }
                }
            }
            else{ // add to left
                while(l_sum < p && l_index > -1 && j <= n - 1){
                    if(l_index - 1 == -1){
                        l_index = 0 ;
                        break ;
                    }
                    else{
                        //std::cout << "adding index " << j + 1
                        l_sum += arr[++j] ;
                        --l_index ;
                    }
                }
            }

            while(l_index > -1 && l_sum < p && j <= n - 1){
                if(l_index - 1 == -1){
                    l_index = 0 ;
                    break ;
                }
                else{
                    l_sum += arr[++j] ;
                    --l_index ;
                }
            }

            while(r_index <= n - 1 && j <= n - 1 && r_sum < p){
                if(r_index+1 == n)
                    r_index = n ;
                else{
                    r_sum +=arr[++j];
                    ++r_index ;
                }
            }

         /*   std::cout << "r_index: " << r_index << "\n" ;
            std::cout << "l_index: " << l_index << "\n" ;

            std::cout << "r_sum: " << r_sum << "\n" ;
            std::cout << "l_sum: " << l_sum << "\n" ;
*/
            if(l_index == r_index == 1){
                ans[i] = n ;
            }
            else
                ans[i] = l_index + n - r_index ;
        }

        for(int i = 0 ; i < n ; i++)
            std::cout << ans[i] << " " ;

       // for(int i = (n)/2 - 1 ; i >= 0 ; i--)
        //    std::cout << ans[i] << " " ;

        std::cout << "\n" ;
    }
}
