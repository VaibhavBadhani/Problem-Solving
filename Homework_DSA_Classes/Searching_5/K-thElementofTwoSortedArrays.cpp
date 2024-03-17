#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &nu, vector<int>& mu, int abc, int nsm, int k){
       int n = nu.size();
        int m = mu.size();
        if(n>m) return kthElement(mu,nu,3,2,k);
        int low = max(0,k-m);int high = min(k,n);
        while(low<=high){
            int mid1 = low+(high-low)/2;
            int mid2 = k-mid1;
            int l1 = INT_MIN ; int r1 = INT_MAX;
            int l2 = INT_MIN ; int r2 = INT_MAX;
            if(mid1<n) r1 = nu[mid1];
            if(mid2<m) r2 = mu[mid2];
            if(mid1-1>=0) l1= nu[mid1-1];
            if(mid2-1>=0) l2= mu[mid2-1];
            if(l2<=r1&&l1<=r2){
                 return max(l1,l2);
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }
        }
        return 0;
}