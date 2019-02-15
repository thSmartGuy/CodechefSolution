#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, k, n) for(int i = k ; i < n ; i++)

template <typename K, typename V>
bool comparePairs(std::pair <K, V> left, std::pair <K, V> right){
    return left.second < right.second ;
}

int s[100000], ns[100000] ;

int main(){
    int p, sub ;
    std::cin >> p >> sub ;

    std::vector <std::pair<int, int>> problem(p) ;

    rep(pr, 0, p){
        int hardness = 0 ;
        rep(i, 0, sub){
            std::cin >> s[i] ;
        }

        rep(i, 0, sub){
            std::cin >> ns[i] ;
        }
        std::vector <std::pair<int, int>> hard(sub) ;

        rep(i, 0, sub){
            hard[i].first = s[i] ;
            hard[i].second = ns[i] ;
        }

        std::sort(hard.begin(), hard.end()) ;

        rep(i, 0, sub - 1){
            if(hard[i].second > hard[i + 1].second){
                hardness++ ;
            }
        }

        problem[pr].first = hardness ;
        problem[pr].second = pr ;
    }

    std::sort(problem.begin(), problem.end()) ;

    std::vector <std::pair <int, int>> :: iterator j ;

    for(auto it = problem.begin() ; it!= problem.end() ; it++){
        j = it ;
        while(j -> first == it -> first) j++ ;
        std::sort(it, j, comparePairs <int, int> ) ;
        it = --j ;
    }

    rep(i, 0, p){
            std::cout << problem[i].second + 1 << "\n" ;
    }
}
