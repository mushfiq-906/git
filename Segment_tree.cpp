#include<bits/stdc++.h>
#define segment_tree l=n*2,r=n*2+1,mid=(b+e)/2
#define mx 100001
using namespace std;

int ara[mx];
struct data
{
    int max1;
    int max2;
}tree[4*mx],c,zero;

void update(int n,int b,int e,int i,int value)
{
    int l,r,mid;
    if(b>i || e<i)
        return;
    if(b==e && b==i)
    {
        tree[n].max1=value;
        return;
    }
    segment_tree;
    update(l,b,mid,i,value);
    update(r,mid+1,e,i,value);
    int mn=min(tree[l].max1,tree[r].max1);
    tree[n].max1=max(tree[l].max1,tree[r].max1);
    tree[n].max2=max(mn,max(tree[l].max2,tree[r].max2));
    if(tree[n].max2==0)
        tree[n].max2=mn;
}

data query(int n,int b,int e,int i,int j)
{
    int l,r,mid;
    data x,y;
    if(b>j || e<i)
        return zero;
    if(b>=i && e<=j)
    {
        return tree[n];
    }
    segment_tree;
    x=query(l,b,mid,i,j);
    y=query(r,mid+1,e,i,j);
    int mn=min(x.max1,y.max1);
    c.max1=max(x.max1,y.max1);
    c.max2=max(mn,max(x.max2,y.max2));
    return c;
}

int main(){
    int m,t,l,n;
    char ch;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>ara[i];
        update(1,1,m,i,ara[i]);
    }
    cin>>t;
    while(t--)
    {
        cin>>ch>>l>>n;
        if(ch=='U')
        {
            update(1,1,m,l,n);
        }
        else
        {
            c=query(1,1,m,l,n);
            cout<<c.max1+c.max2<<endl;
        }
    }
}

