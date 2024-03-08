
#include<bits/stdc++.h>
#include<vector>
   
#include <algorithm> 
#include <iostream> 
  
using namespace std;
int main(){
  int n =0;
  int q =0;
  
  cin>>n;
  cin>>q;
  vector<int>v(n);
  for(int i =0;i<n;i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for(int i =0;i<q;i++){
    int val;
    cin>>val;
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
      int mid = low+(high-low)/2;
      if(v[mid]<val){
        low = mid+1;
      }
      else{
        ans = mid;
        high = mid-1;
      }
     
    }
    cout<<n-ans<<endl;
  }
}