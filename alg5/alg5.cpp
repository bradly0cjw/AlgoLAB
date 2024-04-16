//
// Created by LINBEI on 4/13/2024.
//
#include "bits/stdc++.h"
using namespace std;

int f(vector<int> a){

}
int g(){

}

int h(vector<int> a){
    int len=a.size();
    //binary search
    int l=0;
    int r=len-1;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]>a[mid+1]){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    vector<int> a;
    a={1,2,3,5,4,3,6,7,2,1};
    cout<<h(a);
    return 0;
}
