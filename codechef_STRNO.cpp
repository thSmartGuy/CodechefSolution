#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

// std::vector <long> primeFactors ;
std::vector <long> factors ;

// int isPrime(long long num){
// 	if(num == 2) return 1 ;
// 	for(long long i = 2 ; i <= std::sqrt(num) ; i++){
// 		if(num%i == 0){
// 			return 0 ;
// 		}
// 	}
// 	return 1 ;
// }

long long solve(long long num){
	int primeFact = 0 ;
	for(long long i = 2 ; i <= std::sqrt(num) ; i++){
		while(num%i == 0){
			primeFact++ ;
			num /= i ;
		}
	}

	if(num > 2) primeFact++ ;

	// std::cout << primeFact << "\n" ;

	return primeFact ;
}

// void recur(int cur, long long mul, int n){
// 	if(cur == n){
// 		factors.insert(mul) ;
// 		return ;
// 	}

// 	recur(cur + 1, mul*primeFactors[cur], n) ;
// 	recur(cur + 1, mul, n) ;
// }

int main(){
	// fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	long long x, k ;
	while(t--){
		std::cin >> x >> k ;
	
		// std::cout << "solve(" << x << "): " << solve(x) << "\n" ;

		if(solve(x) >= k){
			std::cout << "1\n" ;
		}
		else{
			std::cout << "0\n" ;
		}

		// std::cout << "c: " << c  << " == " << " k : " << k << "\n" ;


		// primeFactors.clear() ; factors.clear() ;
		// std::cin >> k ;

		// while(k--){
		// 	int num ; std::cin >> num ;
		// 	primeFactors.push_back(num) ;
		// }

		// recur(0, 1, primeFactors.size()) ;

		// //for(auto it:factors) std::cout << it << " " ; 
		// std::cout << "size : " << factors.size() << "\n" ;
	}
}