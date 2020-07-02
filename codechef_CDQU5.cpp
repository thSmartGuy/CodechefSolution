#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long ans[1111111] ;


const int mod = 1e9 + 9 ;
void pre() {
	ans[0] = ans[1] = 0 ;
	ans[2] = ans[3] = 1 ;
	
	for(int i = 4 ; i <= 1000000 ; i++){
		ans[i] = (ans[i - 2] + ans[i - 3])%mod ;
	}
}

int main(){
	//fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	int x ;

	pre() ;
	while(t--){
		std::cin >> x ;

		std::cout << ans[x] << "\n" ;
	}
}