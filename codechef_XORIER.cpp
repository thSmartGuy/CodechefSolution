#include <iostream>
#include <algorithm>
#include <unordered_map>

//const int size_ = 1e6 + 1 ;
std::pair <int, int> arr[100000] ;

int zeroTwo(int n, int x)
{
    int count_ = 0;
    std::unordered_map<int, int> m;

    for (int i=0; i<n ; i++)
    {
        int xor_ = x^arr[i].second ;

        if (m.find(xor_) != m.end())
            count_ += m[xor_];

        m[arr[i].second]++;
    }


    return count_ ;
}

int main(){
    std::ios_base::sync_with_stdio(false) ;

    //calcPrimes() ;
    int t, n, xored, temp ;
    long long int count_ ;
    std::cin >> t ;

    while(t--){
        count_ = 0 ;
        std::cin >> n ;
        for(int i = 0 ; i < n ; i++){
            std::cin >> temp ;

            arr[i].first = temp%2 ;
            arr[i].second = temp ;
        }

        std::sort(arr, arr + n) ;

        int cut = n ;

        for(int i = 0 ; i < n ; i++){
            if(arr[i].first == 1){
                cut = i ;
                break ;
            }
        }

        count_ = ((1LL*cut*(cut - 1))/2) + ((1LL*(n - cut)*(n - cut - 1))/2) ;

        count_ -= zeroTwo(n, 0) ;
        count_ -= zeroTwo(n, 2) ;

        std::cout << count_ << "\n" ;
    }
}

