#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

const long long mod = 998244353 ;

long long modInverse(long long a, long long b = mod - 2){
	long long res = 1 ;

	while(b){
		if((b&1ll)){
			res = (res*a)%mod ;
		}
		a = (a*a)%mod ;
		b >>= 1ll ;
	}
	return res ;
}

// 0 1 a A
std::pair <char, std::vector<long long>> solveEqArray(std::vector <std::pair <char, std::vector<long long>>> & eq){
	std::reverse(eq.begin(), eq.end()) ;
	std::vector <long long> arr = {} ;

	long long zeroProb, oneProb, aProb, aBarProb ;

	char sign = '/' ;
	for(auto it : eq){

		if(it.first == '#'){ // contains probability
			
			auto prob = it.second ;
			if(!arr.size()){ // if arr is empty then that means first prob

				arr = prob ;

			}
			else{ // else arr already contains something

				zeroProb = arr[0] ;
				oneProb = arr[1] ;
				aProb = arr[2] ;
				aBarProb = arr[3] ;

				long long newZeroProb, newOneProb, newAProb, newABarProb ;

				if(sign == '&'){                       // 0         1         a         A
					newZeroProb = ((((zeroProb*((prob[0] + prob[1] + prob[2] + prob[3])%mod))%mod + 
											 (oneProb*(prob[0]))%mod)%mod + 
											  (aProb*((prob[0] + prob[3])%mod))%mod)%mod + 
											   (aBarProb*((prob[0] + prob[2])%mod))%mod)%mod ;
					newOneProb = (oneProb*(prob[1]))%mod ;
					newAProb = ((oneProb*(prob[2]))%mod + (aProb*((prob[1] + prob[2])%mod))%mod)%mod ;
					newABarProb = ((oneProb*(prob[3]))%mod + (aBarProb*((prob[1] + prob[3])%mod))%mod)%mod ;
				}
				else if(sign == '|'){
					newOneProb = ((zeroProb*(prob[1]))%mod + 
								   ((oneProb*((prob[0] + prob[1] + prob[2] + prob[3])%mod))%mod + 
									((aProb*((prob[1] + prob[3])%mod)%mod) + 
									 (aBarProb*((prob[1] + prob[2])%mod)%mod)%mod)%mod)%mod)%mod ;

					newZeroProb = (zeroProb*(prob[0]))%mod ;
					newAProb = ((zeroProb*(prob[2]))%mod + (aProb*((prob[0] + prob[2])%mod))%mod)%mod ;
					newABarProb = ((zeroProb*(prob[3]))%mod + (aBarProb*((prob[0] + prob[3])%mod))%mod)%mod ;
				}
				else if(sign == '^'){
					newZeroProb = ((zeroProb*(prob[0]))%mod + ((oneProb*(prob[1]))%mod + ((aProb*(prob[2]))%mod + (aBarProb*(prob[3]))%mod)%mod)%mod)%mod ;
					newOneProb = ((((zeroProb*(prob[1]))%mod + (oneProb*(prob[0]))%mod)%mod + (aProb*(prob[3]))%mod)%mod + (aBarProb*(prob[2]))%mod)%mod ;
					newAProb = ((((zeroProb*(prob[2]))%mod + (oneProb*(prob[3]))%mod)%mod + (aProb*(prob[0]))%mod)%mod + (aBarProb*(prob[1]))%mod)%mod ;
					newABarProb = ((((zeroProb*(prob[3]))%mod + (oneProb*(prob[2]))%mod)%mod + (aProb*(prob[1]))%mod)%mod + (aBarProb*(prob[0]))%mod)%mod ;
				}
				else{ // contains no sign

				}

				sign = '/' ;

				zeroProb = newZeroProb ;
				oneProb = newOneProb ;
				aProb = newAProb ;
				aBarProb = newABarProb ;
			}

		}
		else{ // contains signs
			
			sign = it.first ;

		}	

	}

	// std::cout << zeroProb << " " << oneProb << " " << aProb << " " << aBarProb << " " << "\n" ;
	return {'#', {zeroProb, oneProb, aProb, aBarProb}} ;
}

void solveBrute(std::string &str){

	long long totalHashCount = 0 ;
	for(char c:str){
		if(c == '#') totalHashCount++ ;
	}

	// 0 1 a A
	std::stack <std::pair <char, std::vector <long long>>> st ;

	for(char c : str){
		if(c == '('){
			st.push({'(', {}}) ;
		}
		else if(c == '^' || c == '&' || c == '|'){
			st.push({c, {}}) ;
		}
		else if(c == ')'){
			std::vector <std::pair <char, std::vector<long long>>> arr ;
			while(!st.empty() && st.top().first != '('){
				arr.push_back(st.top()) ; st.pop() ;
			}
			
			if(!st.empty() && st.top().first == '('){
				st.pop() ;
			}

			st.push(solveEqArray(arr)) ;
		}
		else if(c == '#'){
			st.push({'#', {1,1,1,1}}) ; // all having equal prob of 1/4
		}
	}

	auto it = st.top().second ;

	// calculate actual tot 
	long long totalPossible = 1 ; 
	for(long long i = 0 ; i < totalHashCount ; i++){
		totalPossible = (totalPossible*4ll)%mod ;
	}

	// for(auto a: it){ 
	// 	std::cout << a << "/" << totalPossible ; std::cout << " " ;
	// }
	// std::cout << "\n" ;

	for(auto num : it){
		std::cout << ((num%mod)*(modInverse(totalPossible)%mod)%mod) << " " ;
	}
	std::cout << "\n" ;
}

int main(){
	//fast();
	//freopen("input.txt", "r", stdin) ;
	//freopen("output.txt", "w", stdout) ;

	long long t = 1 ;
	std::cin >> t ;

	std::string str ;
	while(t--){
		std::cin >> str ;
		solveBrute(str) ;
	}
}


/*
(#&(#|(#&(#^(#&(#&#))))))
(#|(#^(#&(#^(#&#)))))
(#&(#|(#&(#&#))))
(#^(#|(#^(#^(#^(#&(#&#)))))))
(#^(#|#))
(#^(#&(#&(#&(#&(#|(#|#)))))))
#
(#&(#^(#^(#|(#^(#&#))))))
(#^(#|(#^(#^#))))
(#&#)
//*/