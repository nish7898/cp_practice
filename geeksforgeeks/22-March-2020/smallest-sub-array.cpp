#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
void build(int tree[],int arr[], int node, int start, int end)
{
    if(start==end)
    tree[node]=arr[start];
    else
    {
        int mid=(start+end)/2;
        build(tree,arr,2*node,start,mid);
        build(tree,arr,2*node+1,mid+1,end);
        
        tree[node]=gcd(max(tree[2*node],tree[2*node+1]),min(tree[2*node],tree[2*node+1]));
    }
}

int query(int tree[],int node, int start, int end, int l, int r,int ans)
{
    if(l<=start && end<=r)
    return tree[node];
    if(r<start || end<l)
    return 0;
    
    int mid=(start+end)/2;
    int p1=query(tree,2*node,start,mid,l,r,ans);
    int p2=query(tree,2*node+1,mid+1,end,l,r,ans);
    
    
    return gcd(max(p1,p2),min(p1,p2));
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i,g,j,ans=INT_MAX;
	    cin >> g >> n;
	    int arr[n+1],tree[4*n+7];
	    for(i=1;i<=n;i++)
	    cin >> arr[i];
	    
	    build(tree,arr,1,1,n);
	    
	    for(i=1;i<n;i++)
	    {
	        for(j=i+1;j<=n;j++)
	        {
	            int p=query(tree,1,1,n,i,j,g);
	            if(p==g)
	            {
	                ans=min((j-i)+1,ans);
	                break;
	            }
	        }
	    }
	    if(ans==INT_MAX)
	    cout << "-1" << endl;
	    else
	    cout << ans << endl;
	}
	return 0;
}