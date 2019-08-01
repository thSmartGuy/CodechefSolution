#include <iostream>
#include <map>
#include <vector>

std::map <int, std::vector <int>> mp ;

int main(){
	int t, n ;
	std::cin >> t ;

	std::string str ;
	while(t--){
		std::cin >> str ;
		n = str.size() ;

		mp.clear() ;

		for(int i = 0 ; i < n ; i++){
			if(!mp.count(str[i] - 'a')){
				mp[str[i] - 'a'] = {i} ;
			}
			else mp[str[i] - 'a'].push_back(i) ;
		}

		int odds = 0 ;
		for(int i = 0 ; i < 26 ; i++){
			if(mp.count(i) && mp[i].size()&1){
				odds++ ;
			}
		}

		std::vector <int> ans ;
		if(n&1){ // only one odd are allowed 
			if(odds > 1){ // not possible
				ans = {-1} ;
			}
			else{
				ans.resize(n) ;

				int st = 0, en = n - 1 ;
				for(int i = 0 ; i < 26 ; i++){
					if(mp.count(i) && mp[i].size()&1){
						ans[n/2] = mp[i][mp[i].size() - 1] + 1 ;
						mp[i].pop_back() ;
					}
					while(mp.count(i) && mp[i].size()){
						int idx1 = mp[i][mp[i].size() - 1] ;
						mp[i].pop_back() ;

						int idx2 = mp[i][mp[i].size() - 1] ;
						mp[i].pop_back() ;

						ans[st++] = idx1 + 1 ;
						ans[en--] = idx2 + 1 ;
					}
				}
			}
		}
		else{ // no odds are allowed
			//std::cout << "even area\n" ;
			//std::cout << "odss: " << odds << "\n" ;
			if(!odds){
				ans.resize(n) ;

				int st = 0, en = n - 1 ;
				for(int i = 0 ; i < 26 ; i++){
					while(mp.count(i) && mp[i].size()){
						int idx1 = mp[i][mp[i].size() - 1] ;
						mp[i].pop_back() ;

						int idx2 = mp[i][mp[i].size() - 1] ;
						mp[i].pop_back() ;

						ans[st++] = idx1 + 1 ;
						ans[en--] = idx2 + 1 ;
					}
				}
			}
			else{ // not possible
				ans = {-1} ;
			}
		}

		for(int a:ans){
			std::cout << a << " " ;
		}
		std::cout << "\n" ;
	}
}