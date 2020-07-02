std::string toBinary(int k, std::string &str){
    str = "" ;
    int size = 10 ;
    while(k){
        str = (k%2 ? '1' : '0') + str ;
        k >>= 1 ;
        size-- ;
    }
    
    while(size > 0){
        str = '0' + str ;
        size-- ;
    }
    
    return str ;
}

long long toDecimal(std::string str){
    long long k = 0 ;
    
    for(int c : str){
        k *= 2ll ; 
        if(c == '1'){
            k += 1ll ;
        }
    }
    
    return k ;
}

struct TrieNode{
    TrieNode *zero, *one ;
    
    TrieNode(){
        zero = one = NULL ;
    }
    
    ~TrieNode(){
        delete zero, one ;
    }
};

void findMinimun(TrieNode *root, std::string &ele, std::string str){
    for(char c : str){
        if(c == '1'){
            if(root->one){
                ele += '1' ;
                root = root->one ;
            }
            else if(root->zero){
                ele += '0' ;
                root = root->zero ;
            }
            else break ;
        }
        else{
            if(root->zero){
                ele += '0' ;
                root = root->zero ;
            }
            else if(root->one){
                ele += '1' ;
                root = root->one ;
            }
            else break ;
        }
    }
}

void insert(TrieNode *root, std::string str){
    for(char c : str){
        if(c == '1'){
            if(!root->one)
                root -> one = new TrieNode() ;
            root = root -> one ;
        }
        else{
            if(!root->zero)
                root -> zero = new TrieNode() ;
            root = root -> zero ;
        }
    }
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    TrieNode *root = new TrieNode() ;
    
    std::string str = "", str2 ;
    for(int a : A){
        insert(root, toBinary(a, str2)) ;
    }
    
    str = "" ;
    for(int i = 0 ; i < B.size() ; i++){
        str = "" ;
        (findMinimun(root, str, toBinary(B[i], str2))) ;
        
        B[i] = toDecimal(str) ;
    }
    
    delete root ;
    
    return B ;
}
