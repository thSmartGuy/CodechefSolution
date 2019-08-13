#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <int> ans ;

int solve(int n, int lengthOfWire){
	if(ans[n - 1] != -1) return ans[n - 1] ;

	int min = lengthOfWire ;
	for(int i = 0 ; i < n ; i++){
		min = std::min(min, 
			(lengthOfWire - (n + 1) + 
			 solve(n - (i + 1), lengthOfWire - (n + 1)) + 
			 solve(i + 1))
			) ;
	}
}

int main(){
	int t = 1 ;
	std::cin >> t ;
	int n, m ;
	while(t--){
		std::cin >> n >> m ;
		vis.assign(n, -1) ;
		vis[0] = 1 ;

		solve(1, n, m, 0)
	}
}