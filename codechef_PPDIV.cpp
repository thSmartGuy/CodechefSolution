#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#include <chrono> 
using namespace std::chrono; 

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

const int mod = 1e9 + 7 ;

std::set<long long> perfectPowers ; 
void pre(long long n){
    perfectPowers.insert(1); 
  
    for (long long i = 2 ; i * i <= n ; i++){ 
        long long j = i * i; 
        perfectPowers.insert(j); 
        while (j * i <= n) { 
            perfectPowers.insert(j * i); 
            j = j * i; 
        } 
    } 
}

long long modInverse(long long a, long long b = mod - 2){
	long long res = 1 ;

	while(b){
		if((b&1ll)){
			res = (res*a)%mod ;
		}

		a = (a*a)%mod ;

		b >>= 1ll ;
	}

	return res ;
}

long long getSquareSum(long long num){

	// std::cout << "getSquareSum till " << num << " :: " ;

	long long sum = 0 ;

	sum = num%mod ;
	sum %= mod ;
	sum = (sum*((num + 1ll)%mod))%mod ;
	sum %= mod ;
	sum = (sum*(((2*num)%mod + 1)%mod)%mod)%mod ;

	// std::cout << sum << "\n" ;

	return sum%mod ;
}

int main(){
	// fast();	
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	// auto start = high_resolution_clock::now(); 

	pre(1e4) ; 
	
	// auto stop = high_resolution_clock::now(); 
		
	// auto duration = duration_cast<milliseconds>(stop - start); 
	
	// std::cout << "time taken: " << duration.count() << "\n"; 

	// std::cout << "last element: " << *perfectPowers.rbegin() << "size: " << perfectPowers.size() << "\n" ;

	long long n ;
	while(t--){
		std::cin >> n ;
		
		long long ans = 0 ;

		for(auto it: perfectPowers){
			if(it > n) break ;
			// std::cout << "add " << it << " " << n/it << " times\n" ;
			ans = (ans + (it*(n/it)%mod))%mod ;
		}

		if(n > 1e4){
			long long till = std::sqrt((long double)n) ;

			long long from = 1e4 ;

			// std::cout << "sum till 1e6: " << getSquareSum(1e6) << "\n" ;

			// std::cout << "sum till " << till << " : " << getSquareSum(till) << "\n" ;

			if(till > from){
				long long toAdd = (getSquareSum(till) - getSquareSum(from) + mod)%mod ;

				toAdd = (toAdd * modInverse(6)%mod)%mod ;

				// std::cout << "adding: " << toAdd << "\n" ;

				ans = (ans + toAdd)%mod ; 
			}
		}

		std::cout << ans << "\n" ;
	}
}

// 357782145
