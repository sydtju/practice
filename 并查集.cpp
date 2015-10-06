//并查集
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
void print(int dat[],int len){
	for(int i=0;i<len;++i)
		cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<len;++i)
		cout<<dat[i]<<" ";
	cout<<endl;
	cout<<endl;
}
int findset(int dat[],int x){
	int res=x;
	while (dat[res]!=res) res=dat[res];
	return res;
}
void add(int dat[],int a,int b){
	int root=0;
	int a_t=findset(dat,a);int b_t=findset(dat,b);
	if(a_t<=b_t) root=a_t;
	else 
		root=b_t;
	while (dat[a_t]!=root){int temp=dat[a_t];dat[a_t]=root;a_t=temp;}
	while (dat[b_t]!=root){int temp=dat[b_t];dat[b_t]=root;b_t=temp;}
}
int main(){
	int  n,m;
	cin>>n>>m;
	if(n<=0||m<=0) {cout<<"error!\n"<<endl;return 0;}
	int *tree=new int[n];
	for(int i=0;i<n;++i){
		tree[i]=i;
	}
	while (m>0)
	{
		m--;
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		add(tree,a,b);
		print(tree,n);
	}
	return 0;
}
