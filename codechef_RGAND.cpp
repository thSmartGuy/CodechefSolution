#include <iostream>
#include <vector>
#include <algorithm>
const long long mod = 1000000007 ;

long long solve(long long l, long long r){
	long long act = 0, req = 0, val, ans = 0 ;
	for(long long i = 0 ; i < 60 ; i++){
		val = std::min(r - l + 1, req - act + 1) ;
		val %= mod ;
		if((1LL << i)&l){
			ans += (val*((1LL << i)%mod))%mod ;
			ans %= mod ;
			act += (1LL << i) ;
		}
		req += (1LL << i) ;
	}
	return ans ;
}

int main(){
	long long t = 1 ;
	std::cin >> t ;

	long long l, r ;

	while(t--){
		std::cin >> l >> r ;

		std::cout << solve(l, r) << "\n" ;
	}
}