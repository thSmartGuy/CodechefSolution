#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    int t, n, third, forth ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::vector <int> arr(n) ;

        FOR(i, 0, n){
            arr[i] = i + 1 ;
        }

        while(arr.size() > 6){
            std::cout << "? " ;
            FOR(i, 0, 5){
                std::cout << arr[i] << " " ;
            }
            std::cout << "\n" ;

            std::cin >> third >> forth ;

            if(arr.size() != 6){
                auto pos = arr.begin() ;
                for(auto itr = arr.begin() ; itr != arr.end() ; itr++){
                    if(*itr == third){
                        pos = itr ;
                        break ;
                    }
                }
                arr.erase(pos) ;
            }

            if(arr.size() != 6){
                auto pos = arr.begin() ;
                for(auto itr = arr.begin() ; itr != arr.end() ; itr++){
                    if(*itr == forth){
                        pos = itr ;
                        break ;
                    }
                }
                arr.erase(pos) ;
            }
        }

//        std::cout << "array : : \n" ;
//        FOR(i, 0, arr.size()){
//            std::cout << arr[i] << " " ;
//        }
//        std::cout << "\n" ;

        // ARRAY CONTAINS SIX ELEM ONLY NOW

        std::vector <std::pair <int, std::pair <int, int>>> hidden ; // contains third and forth largest if  i+1 the is hidden

        std::map <int, int> mp ;

        FOR(i, 0, 6){ // hide ith element
            std::cout << "? " ;
            FOR(j, 0, arr.size()){
                if(j != i){
                    std::cout << arr[j] << " " ;
                }
            }
            std::cout << "\n" ;
            std::cin >> third >> forth ;
            mp[third]++ ; mp[forth]++ ;
            hidden.push_back(std::make_pair(arr[i], std::make_pair(third, forth))) ;
        }

        int Bfreq, temp = 0 ;
        for(auto itr : mp){
            if(itr.second > temp){
                Bfreq = itr.first ;
                temp = itr.second ;
            }
        }

        int Lfreq ; temp = 20 ;
        for(auto itr : mp){
            if(itr.second < temp){
                Lfreq = itr.first ;
                temp = itr.second ;
            }
        }

//        std::cout << "hidden:: \n\n" ;

        std::vector <int> ans ;
        for(auto itr : hidden){
            if(itr.second.first == Lfreq && itr.second.second == Bfreq || itr.second.second == Lfreq && itr.second.first == Bfreq){
                ans.push_back(itr.first) ;
            }
        }

//        std::cout << "freq:: \n\n" ;
        for(auto itr : mp){
            if(itr.first == ans[0]){
                std::cout << "! " << ans[1] << "\n" ;
                break ;
            }
            else if(itr.first == ans[1]){
                std::cout << "! " << ans[0] << "\n" ;
                break ;
            }
        }

//        std::cout << "least most\n" ;
//        std::cout << Lfreq << " " << Bfreq << "\n" ;
    }
}

