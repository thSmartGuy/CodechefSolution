#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[11111] ;
std::vector <int> prime ;
std::vector <int> primeArray ;

void sieve(){
	prime.assign(11111, 0) ;

	for(int i = 0 ; i < 11111 ; i++){
		prime[i] = i ;
	}

	prime[0] = prime[1] = 0 ;
	for(int i = 2 ; i < 11111 ; i++){
		if(prime[i] == i){
			for(int j = i ; j < 11111 ; j+=i){
				if(prime[j] == j)
					prime[j] = i ;
			}
		}
	}

	// for(int i = 0 ; i < 100 ; i++){
	// 	std::cout << prime[i] << " " ;
	// }
	// std::cout << "\n" ;

	for(int i = 2 ; i < 11111 ; i++){
		if(prime[i] == i){
			primeArray.push_back(i) ;
		}
	}
// 	for(int i = 0 ; i < 100 ; i++){
// 		std::cout << primeArray[i] << " " ;
// 	}
// 	std::cout << "\n" ;
}

std::vector <int> count ;

void markAllPrimeFactors(int k, int m){
	if(k < 2) return ;

	// std::cout << "factors of " << k << " : " ;
	while(k != 1){
		int factor = prime[k] ;
		
		// std::cout << factor << " " ;

		if(factor <= m) 
			count[factor]++ ;

		k = k/prime[k] ;
	}
	// std::cout << "\n" ;
}

std::map <int, int> mp ;
void getAllFactors(int k, int m){
	if(k < 2) return ;

	// std::cout << "factors of " << k << " : " ;
	while(k != 1){
		int factor = prime[k] ;
		
		// std::cout << factor << " " ;

		if(factor <= m) 
			mp[factor]++ ;

		k = k/prime[k] ;
	}
}

int main(){
	//fast();
	int t = 1 ;
	std::cin >> t ;
	sieve() ;

	int n, m ;
	while(t--){
		std::cin >> n >> m ;

		count.assign(m+1, 0) ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
			markAllPrimeFactors(arr[i], m);
		}

		long long ans = 1 ;

		for(int i = 1 ; i <= m ; i++){
			int num = i ;

			mp.clear() ;
			getAllFactors(num, m) ;

			long long tmp = 1;
			for(auto it : mp){
				int number = it.first ;
				int countNumber = it.second ;

				if(countNumber > count[number]){
					tmp *= std::pow(number, countNumber - count[number]) ;
				}
			}

			ans = std::max(ans, tmp) ;
		}

		// for(int a: primeArray){
		// 	if(a <= m){
		// 		if(!count[a]){
		// 			if(ans * a <= m){
		// 				ans = std::max(ans, ans*1ll*a) ;
		// 			}
		// 			else{
		// 				ans = std::max(ans, 1ll*a) ;
		// 			}
		// 		}
		// 	}
		// 	else break ;
		// }

		// for(int i = primeArray.size() - 1 ; i >= 0 ; i--){
		// 	int a = primeArray[i] ;
		// 	if(a <= m){
		// 		if(!count[a]){
		// 			if(ans * a <= m){
		// 				ans = std::max(ans, ans*1ll*a) ;
		// 			}
		// 			else{
		// 				ans = std::max(ans, 1ll*a) ;
		// 			}
		// 		}
		// 	}
		// 	else break ;
		// }

		std::cout << ans << "\n" ;
	}
}