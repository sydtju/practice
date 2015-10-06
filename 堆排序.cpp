//堆排序
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
void print(int dat[],int len){
	for(int i=0;i<len;++i){
		cout<<dat[i]<<" ";
	}
	cout<<endl;
}
void adjustheap(int dat[],int len,int loc){
	while (2*loc+1<len)
	{
		int temp=2*loc+1;
		if((temp+1<len)&&(dat[temp]<dat[temp+1])) temp++;
		if(dat[temp]>dat[loc]) {swap(dat[temp],dat[loc]);loc=temp;}
		else
			return;
	}
}
void sort(int dat[],int len){
	for(int i=len/2;i>=0;--i)
		adjustheap(dat,len,i);
	print(dat,len);
	for(int i=len-1;i>0;--i){
		swap(dat[0],dat[i]);
		print(dat,len);
		adjustheap(dat,i,0);
		print(dat,len);
	}
}

int main(){
	int dat[]={4,9,3,2,1,5,6,0,7,8};
	sort(dat,sizeof(dat)/sizeof(int));
	print(dat,sizeof(dat)/sizeof(int));
	return 0;
}
