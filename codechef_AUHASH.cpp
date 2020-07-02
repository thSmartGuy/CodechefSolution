#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <int> coins ;

void pre(){
	coins.resize(52) ;
	for(int i = 0 ; i < 52 ; i++){
		coins[i] = i + 1 ;
	}
}

long long memo[60][60][1500] ;

long long recur(int idx, int n, int sum){
	if(sum < 0) return 0 ;
	if(idx < 0) return (n == 0 && sum == 0) ;
	if(n < 0) return 0 ;

	if(memo[idx][n][sum] != -1) return memo[idx][n][sum] ;

	long long ways = recur(idx - 1, n - 1, sum - coins[idx]) ;
	ways += recur(idx - 1, n, sum) ;

	return memo[idx][n][sum] = ways ;
}

int main(){
	//fast();
	// freopen("input.txt", "r", s`	tdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	pre() ;

	int n, sum ;
	int k = 1 ;
	while(t--){
		memset(memo, -1, sizeof(memo)) ;
		std::cin >> n >> sum ;
		long long ans = 0 ;
		if(n <= 52 && sum < 1400){
			ans = recur(51, n, sum) ;
		}
		std::cout << "Case " << k++ << ": " << ans << "\n" ;
	}
}