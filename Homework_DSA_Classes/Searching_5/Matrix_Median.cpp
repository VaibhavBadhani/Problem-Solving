#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int up(vector<vector<int>> A,int val,int m){
//     int low =0;
//     int high = m-1;
//     int ans = m;
//     while(low<=high){
//         int mid = low+(high-low)/2;
//         if(A[mid]>val){
//             ans= mid;
//             high = mid-1;
//         }   
//         else  low = mid+1;
        
//     }
//     return ans;
// }

int bb(vector<vector<int>> A,int n,int m , int mid){
    int count =0;
    for(int i =0;i<n;i++){
        count+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
    }
    return count;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MAX;
    int high = INT_MIN;
    int n = A.size();
    int m = A[0].size();
    for(int i =0;i<n;i++){
        low = min(low,A[i][0]);
        high = max(high,A[i][m-1]);
    }
    int k = (n*m+1)/2;
    while(low<high){
        int mid = low+(high-low)/2;
        int count = bb(A,n,m,mid);
        if(count<k) low= mid+1;
        else high = mid;
    }
    return low;
}
