#include<iostream>
#include<vector>
using namespace std;
#define vecvec vector<vector<ll>>
#define ll long long int

vecvec add(vecvec a,vecvec b,ll n)
{
    vecvec c;
    ll i,j;
    for(i=0;i<n;i++)
    {
        vector<ll>v1;
        for(j=0;j<n;j++)
        {
            ll num=a[i][j]+b[i][j];
            v1.push_back(num);
        }
        c.push_back(v1);
    }
    return c;
}

vecvec sub(vecvec a,vecvec b,ll n)
{
    vecvec c;
    ll i,j;
    for(i=0;i<n;i++)
    {
        vector<ll>v1;
        for(j=0;j<n;j++)
        {
            ll num=a[i][j]-b[i][j];
            v1.push_back(num);
        }
        c.push_back(v1);
    }
    return c;
}

vecvec strassenMultiply(vecvec a, vecvec b,ll n)
{
    vecvec c;
    if(n==1)
    {
        vector<ll> vec;
        ll num=a[0][0]*b[0][0];
        vec.push_back(num);
        c.push_back(vec);
        return c;
    }
    else
    {
        ll i,j,k;
        vecvec a11,a12,a21,a22,b11,b12,b21,b22;
        ll n1=n/2;
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(a[i][j]);
            }
            a11.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(b[i][j]);
            }
            b11.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(a[i][n1+j]);
            }
            a12.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(b[i][n1+j]);
            }
            b12.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(a[n1+i][j]);
            }
            a21.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(b[n1+i][j]);
            }
            b21.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(a[n1+i][n1+j]);
            }
            a22.push_back(v1);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll>v1;
            for(j=0;j<n1;j++)
            {
                v1.push_back(b[n1+i][n1+j]);
            }
            b22.push_back(v1);
        }
        
        
        vecvec p1=strassenMultiply(add(a11,a22,n1),add(b11,b22,n1),n1);
        vecvec p2=strassenMultiply(add(a21,a22,n1),b11,n1);
        vecvec p3=strassenMultiply(a11,sub(b12,b22,n1),n1);
        vecvec p4=strassenMultiply(a22,sub(b21,b11,n1),n1);
        vecvec p5=strassenMultiply(add(a11,a12,n1),b22,n1);
        vecvec p6=strassenMultiply(sub(a21,a11,n1),add(b11,b12,n1),n1);
        vecvec p7=strassenMultiply(sub(a12,a22,n1),add(b21,b22,n1),n1);
        
        vecvec c11=add(add(p1,p4,n1),sub(p7,p5,n1),n1);
        vecvec c12=add(p3,p5,n1);
        vecvec c21=add(p2,p4,n1);
        vecvec c22=add(add(p1,p3,n1),sub(p6,p2,n1),n1);
        
        for(i=0;i<n1;i++)
        {
            vector<ll> v2;
            for(j=0;j<n1;j++)
            {
                ll num=c11[i][j];
                v2.push_back(num);
            }
            for(j=0;j<n1;j++)
            {
                ll num=c12[i][j];
                v2.push_back(num);
            }
            c.push_back(v2);
        }
        for(i=0;i<n1;i++)
        {
            vector<ll> v2;
            for(j=0;j<n1;j++)
            {
                ll num=c21[i][j];
                v2.push_back(num);
            }
            for(j=0;j<n1;j++)
            {
                ll num=c22[i][j];
                v2.push_back(num);
            }
            c.push_back(v2);
        }
        
        return c;
    }
}

int main()
{
    ll n;
    cin>>n;
    vecvec a,b;
    ll i,j,k;
    
    for(i=0;i<n;i++)
    {
        vector<ll> vec;
        for(j=0;j<n;j++)
        {
            ll num;
            cin>>num;
            vec.push_back(num);
        }
        a.push_back(vec);
    }
    for(i=0;i<n;i++)
    {
        vector<ll> vec;
        for(j=0;j<n;j++)
        {
            ll num;
            cin>>num;
            vec.push_back(num);
        }
        b.push_back(vec);
    }
    vecvec c;
    c=strassenMultiply(a,b,n);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}