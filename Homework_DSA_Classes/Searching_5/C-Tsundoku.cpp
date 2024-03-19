#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll>a(n);
  vector<ll>b(m);
  for(int i =0;i<n;i++){
    cin>>a[i];
  }
  for(int i =0;i<m;i++){
    cin>>b[i];
  }
  vector<ll>c(n+1,0);
  vector<ll>d(m+1,0);
  for(int i =0;i<n;i++){
    c[i+1]=c[i]+a[i];
  }
  for(int i =0;i<m;i++){
    d[i+1]=d[i]+b[i];
  }
  int total =0;
  for(int i =0;i<n+1;i++){
      ll o = k-c[i];
      if(o<0) continue;
      int l = lower_bound(d.begin(),d.end(),o)-d.begin();
      if(l>m||d[l]>o){
        l--;
      }
      total = max(total,i+l);
  }
  cout<<total;
  return 0;
}