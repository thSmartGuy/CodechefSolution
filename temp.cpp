#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <std::vector <int>> edges ;

int fistsBumps ;

int numberOfNodes(int root){
	if(edges[root].size() == 0) return 1 ;

	int sum = 1 ;
	for(int i = 0 ; i < edges[root].size() ; i++){
		sum += numberOfNodes(edges[root][i]) ;
	}
	return sum ;
}

int dfs(int root, int depth, int &answerHandshakes){
	answerHandshakes += depth ;

	int k = 1 ;

	int p ;
	int nonZero = 0 ;
	for(int i = 0 ; i < edges[root].size() ; i++){
		int p = numberOfNodes(edges[root][i]) ; 
		nonZero = p > 0 ? nonZero + 1 : nonZero ;
		k *= (p > 0) ? p : 1 ;
		dfs(edges[root][i], depth + 1, answerHandshakes) ;
	}

	fistsBumps += nonZero > 1 ? k : 0 ;

	//std::cout << "answerHandshakes: "<< answerHandshakes << "\n" ;
	return 0 ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	while(t--){
		std::cin >> n ;
		fistsBumps = 0 ;

		edges = std::vector <std::vector <int>> (n + 1) ;

		int root = 0 ;

		int u, v ;

		for(int i = 1 ; i <= n ; i++){
			std::cin >> v ;

			edges[v].push_back(i) ;
			if(v == 0) root = i ;
		}

		std::cout << "root: " << root << "\n" ;
		for(int i = 1 ; i <= n ; i++){
			std::cout << i << ": " ;
			for(int j = 0 ; j < edges[i].size() ; j++){
				std::cout << edges[i][j] << " " ;
			}
			std::cout << "\n" ;
		}
		int answerHandshakes = 0 ;
		dfs(root, 0, answerHandshakes) ;

		std::cout << "answerHandshakes: " << answerHandshakes << "\n" ;
		std::cout << "fistsBumps : " << fistsBumps << "\n" ;
	}
}