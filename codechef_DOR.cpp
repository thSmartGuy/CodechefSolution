#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <int> ll, rr ;

std::vector <int> printBinary(long long a){
	std::vector <int> kk ;
	while(a){
		kk.push_back(a&1) ;
		a >>= 1ll ;
	}
	while(kk.size() < 100)
		kk.push_back(0) ;
	return kk ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	long long l, r ;

	while(t--){
		std::cin >> l >> r ;

		ll = printBinary(l) ;
		rr = printBinary(r) ;

		std::vector <int> ans(100, 0) ;

		bool differentBits = 0 ;

		for(int i = ll.size() - 1 ; i >= 0 ; i--){
			differentBits = (differentBits | (ll[i] ^ rr[i])) ;

			ans[i] = (differentBits | rr[i]) ;
		}

		long long anss = 0 ;
		for(int i = ans.size() - 1 ; i >= 0 ; i--){
			anss = (anss*2ll + ans[i]) ;
		}
		std::cout << anss << "\n" ;
	}
}