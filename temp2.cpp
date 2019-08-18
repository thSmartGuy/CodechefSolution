    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int t,n;
        string s;
        cin>>t;
        while(t--){
            cin>>n;
            cin>>s;
            int ans=0;
            vector<int> array[26] ;
            for(int i=0;i<n;i++){
                //to store the index of every occurance of each character
                array[s[i]-'a'].push_back(i) ;
            }

            for(int i = 0 ; i < 26 ; i++){
                if(array[i].size()){
                    std::cout << (char)('a' + i) << " : " ;
                    for(int a: array[i]){
                        std::cout << a << " " ;
                    }
                    std::cout << "\n" ;
                }   
            }

            //to find the maximum frequency of character which satisfies the constraint
            for(int i=0;i<26;i++){
                for(int j=0;j<array[i].size();j++){
                    for(int k=ans+j;k<array[i].size();k++){
                        //std::cout << 
                        if(array[i][k]-array[i][j]<=(2*(k-j+1))){
                            ans=max(ans,k-j+1);
                        }
                    }
                }
            }
            cout<<min((2*ans+1),n)<<endl;
        }
    }