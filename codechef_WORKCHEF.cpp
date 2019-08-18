#include <iostream>
#include <vector>
#include <algorithm>
typedef long long lld ;

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int noDiv(long long n){
	int k = 0 ;
	long long rem = n%(2520) ;  // n % (LCM(1...9))
	long long tmp = n ;
	int vis[10] = {} ;
	while(tmp){
		int div = tmp%10;
		tmp /= 10 ;
		if(div && !vis[div] && rem%div == 0){ 
			k++ ;
			vis[div] = 1 ;
		}
	}
	return k ;
}

long long solveBrute(lld l, lld r, lld k){
	int ans = 0 ;
	for(lld i = l ; i <= r ; i++){
		if(noDiv(i) >= k){
			ans++ ;
		}
	}
	return ans ;
}

int main(){
	fast() ;
	int q ;
	lld l, r, k ;
	std::cin >> q ;

	while(q--){
		std::cin >> l >> r >> k ;

		std::cout << solveBrute(l, r, k) << "\n" ;
	}
}