#include<bits/stdc++.h>
using namespace std;


const int Nax = 1e5 + 10;

int tree[4*Nax];

void build(int node,vector<int> a,int start,int end){
     
     if(start == end){
     	 tree[node] = a[start];
       return;
     }
       
       int mid = (start + end) / 2;

     build(2*node,a,start,mid);
     build(2*node+1,a,mid + 1,end);

    // tree[node] = operation between tree[2*node] and tree[2*node + 1]

}

int query(int node,vector<int> a,int l,int r,int start,int end){
  if( start >= l && end <= r) 
  	  return tree[node];
  
  if(start > r || l > end) 
    return 0;// return according to the operation in case of no overlap...

  int mid = (start + end)/2;

   int from_left = query(2*node,a,l,r,start,mid);
   int from_right = query(2*node+1,a,l,r,mid+1,end);

  //return result of operation between from_left ans from_right

   return 0;// <-remove this return  when operation is decided

}

void update(int node, vector<int> &a,int start,int end,int pos,int val){
   if(start == end) {
   	   a[pos] = val;;
   	   tree[node] = val;
   	   return;
   }
 int mid = (start + end)/2;
 
 if(pos <= mid) update(2*node,a,start,mid,pos,val);
 
 else update(2*node + 1,a,mid+1,end,pos,val);

 // tree[node] = operation between tree[2*node] and tree[2*node + 1]

}

int main(){

  
}
