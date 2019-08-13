#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void fast(){	 
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

const long long mod = 1e9 + 7 ;

long long solve(std::string str){
	long long n = str.size() ;

	long long pow = std::pow(10, n - 1) ;

	long long ans = 0 ;
	for(long long i = 0 ; i < n ; i++){
		if(i == 0 || (i && str[i] != str[i - 1])){
			long long no = (long long)(str[i] - '0') ;
			ans = (ans + (no*(pow%mod))%mod)%mod ;
		}
		pow /= 10 ; 
	}
	return ans%mod ;
}

int main(){
	long long t = 1 ;
	std::cin >> t ;

	long long l, r, nl, nr ;
	while(t--){
		std::cin >> l >> r ;

		long long ans = 0 ;
		for(long long i = l ; i <= r ; i++){
			ans = (ans + solve(std::to_string(i)))%mod ;
		}
		std::cout << ans << "\n" ;
	}
}
