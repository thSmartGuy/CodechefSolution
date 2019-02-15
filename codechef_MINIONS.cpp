#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct bucket{
    int a,b;
    bool operator < (bucket const &c)
    {
        if(a!=c.a)
            return a<c.a;
        else
            return b<c.b;
    }
};

//Node stores value of B1+B2...etc and answer for that range.
struct node{
    long long bVal;
    int ans;

    void clear()//Function to reset values :)
    {
        bVal=0;
        ans=0;
    }

    node operator +(node const & b){
        return {bVal+b.bVal,ans+b.ans};
    }
};

const int N=400005;
node tree[4*N+10];
bucket arr[N+10],indexes[N+10];

node query(int v,int a,long long b,int num,int l,int r)
{
    if(tree[v].bVal==0)
        return{-1,0};//Why not {-1.-1}? Hint: Refer to query at odd nodes :)
    else if(l>r)
        return{};
    else if(tree[v].bVal+b<=1LL*a*(num+tree[v].ans))//Can the full range be included?
    {
        return tree[v];
    }
    else if(l==r)
    {
        return {};
    }
    else
    {
        //If full range cannot be included, can the "half-ranges" of its sons have to be included.
        int mid=(l+r)>>1;
        node a1;
        a1.clear();
        a1=query(2*v,a,b,num,l,mid);
        if(a1.bVal==0)//Removing this will give TLE. Why? Analyze complexity.
            return a1;
        else if(a1.bVal==-1)
            a1.clear();
        if(a1.bVal+b<=(a1.ans+num)*1LL*a)
        {
             a1=a1+query(2*v+1,a,a1.bVal+b,a1.ans+num,mid+1,r);
        }
        return a1;
    }
}
void update(int i,int l,int r,int value,int n)
{
    if(l>i or r<i)
        return; //Out of range
    else if(l==r and l==i)
    {
        tree[n].ans++;//Ans = If condition satisfied, these many pairs are there in the range
        tree[n].bVal+=value;
        return;
    }
    else
    {
        int mid=(l+r)>>1;
        update(i,l,mid,value,2*n);
        update(i,mid+1,r,value,2*n+1);//Refer to editorial for relation.
        tree[n]=tree[2*n]+tree[2*n+1];
        return;
    }
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
	    cnt++;
	    int n;
	    cin>>n;
	    int ans=0;
	    int i,j,k;
	    //Input
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i].a>>arr[i].b;
	        //If at least one of the pair as Ai>=Bi, answer is not 0. Else its 0.
	        if(arr[i].a>=arr[i].b)
	            ans=1;
	    }
	    if(!ans)
	    {
	        cout<<ans<<endl;
	        continue;
	    }

	    for(i=0;i<=4*n+10;i++)
	    {
	        tree[i].clear();
	    }
	    sort(arr,arr+n);
	    for(i=0;i<n;i++)
	    {
	        indexes[i].a=arr[i].b;
	        indexes[i].b=i;
	    }
	    sort(indexes,indexes+n);
	    long long sum=0;
	    //Start from max Ai. See if it can be a possible candidate for range [i,n].
	    //Do for all Ai and store the maxima.
	    bucket temp;
	    for(int i=n-1;i>=0;--i)
	    {
	        //First query the tree for b values inserted till now + B value of curr pair
	        node anss=query(1, arr[i].a, arr[i].b, 1, 0, n-1);
	        anss.ans++;
	        //cout<<"i="<<i<<endl;
	        ans=max(ans,anss.ans);
	        //Then update the tree with this b value. Initially our tree was empty, which is filled slowly
	        //per iteration
	        //Very important to update tree as if "Initial array of b values was sorted."
	        temp.a=arr[i].b;
	        temp.b=i;
	        int position=lower_bound(indexes,indexes+n,temp)-indexes;
	        update(position,0,n-1,arr[i].b,1);
	    }
	    cout<<ans<<endl;
	}

	return 0;
}
