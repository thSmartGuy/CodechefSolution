#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void fast(){	 
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

const long long mod = 1e9 + 7 ;

long long getSum(long long n){
	long long res ;
	res = n*(n + 1)/2 ;
	return res ;
}

int main(){
	long long t = 1 ;
	std::cin >> t ;

	long long l, r, nl, nr ;
	while(t--){
		std::cin >> l >> r ;

		long long ans = r*(r + 1ll)/2ll - l*(l + 1ll)/2ll ;

		long long mul = 1 ;
		for(long long div = 100 ; div <= r ; div*=10){
			ans -= (r/div)*45*mul ;
			std::cout << r/div << "\n" ;
			std::cout << "subtracting : " << (r/div)*45*mul << "\n" ;
			mul *= 100 ;
			std::cout << "getSum : " << getSum(r/div - 1)*mul << "\n" ;
			ans -= getSum(r/div - 1)*mul ;
		}
		
		std::cout << ans << "\n" ;
	}
}
