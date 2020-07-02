#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[100] ;
// const int mod = 1e9 + 7 ;

long long gcd(long long a, long long b){
	if(!a) return b ;
	return gcd(b%a, a) ;
}

std::map <std::pair<int, int>, long long> memo ;
long long solve(long long gcdTillNow, int idx){
	if(idx < 0){
		if(gcdTillNow == 1) return 1 ;
		return 0 ;
	}

	if(memo.count({gcdTillNow, idx})) return memo[{gcdTillNow, idx}] ;

	long long ans = 0 ;
	// take current element into consideration
	ans = solve(gcd(gcdTillNow == -1 ? arr[idx] : gcdTillNow, arr[idx]), idx - 1) ;

	// do not take the current element into consideration
	ans = (ans + solve(gcdTillNow, idx - 1)) ;

	return memo[{gcdTillNow, idx}] = ans ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	int n ;
	while(t--){
		memo.clear() ;
		std::cin >> n ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
		}

		std::cout << solve(-1, n - 1) << "\n" ;
	}
}