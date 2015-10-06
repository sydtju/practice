//二分查找  upper_bound lower_bound 
#include<iostream>
#include<cstdio>
#include <list>
using namespace std;
int find(int dat[],int len){
	int res=INT_MIN;int temp=0;
	for(int i=0;i<len;++i){
		temp=(temp+dat[i]>dat[i])?temp+dat[i]:dat[i];
		if(temp>res) res=temp;
	}
	return res;
}
int my_lower_bound(int *array, int size, int key)
{
	int first = 0, last = size-1;
	int middle, pos=0;       //需要用pos记录第一个大于等于key的元素位置

	while(first < last)
	{
		middle = (first+last)/2;
		if(array[middle] < key){      //若中位数的值小于key的值，我们要在右边子序列中查找，这时候pos可能是右边子序列的第一个
			first = middle + 1;
			pos = first;
		}
		else{
			last = middle;           //若中位数的值大于等于key，我们要在左边子序列查找，但有可能middle处就是最终位置，所以我们不移动last,
			pos = last;              //而是让first不断逼近last。
		}
	}
	return pos;
}
int my_upper_bound(int *array, int size, int key)
{
	int first = 0, last = size-1;
	int middle, pos = 0;

	while(first < last)
	{
		middle = (first+last)/2;
		if(array[middle] > key){     //当中位数大于key时，last不动，让first不断逼近last
			last = middle;
			pos = last;
		}
		else{
			first = middle + 1;     //当中位数小于等于key时，将first递增，并记录新的位置
			pos = first;
		}
	}
	return pos;
}
int lower_bound(int dat[],int len,int x){
	int s=0;int e=len-1;int mid=0;int pos;
	while(s<e){
		mid=(s+e)/2;
		if(dat[mid]<x){
			s=mid+1;
			pos=s;
		}
		else{
			e=mid;
			pos=e;
		}
	}
	return pos;
}
int upper_bound(int dat[],int len,int x){
	int s=0;int e=len-1;int mid=0;int pos;
	if(dat[e]<=x) return e+1;
	while(s<e){
		mid=(s+e)/2;
		if(dat[mid]<=x){
			s=mid+1;
			pos=s;
		}
		else{
			e=mid;
			pos=e;
		}
	}
	return pos;
}
int main()
{
	int dat[]={0,1,2,3,4,5,6,7,8,9};
	cout<<"lower_bound(dat,10,0)="<<lower_bound(dat,10,0)<<endl;
	cout<<"lower_bound(dat,10,1)="<<lower_bound(dat,10,1)<<endl;
	cout<<"lower_bound(dat,10,5)="<<lower_bound(dat,10,5)<<endl;
	cout<<"lower_bound(dat,10,8)="<<lower_bound(dat,10,8)<<endl;
	cout<<"lower_bound(dat,10,9)="<<lower_bound(dat,10,9)<<endl;

	cout<<"upper_bound(dat,10,0)="<<upper_bound(dat,10,0)<<endl;
	cout<<"upper_bound(dat,10,1)="<<upper_bound(dat,10,1)<<endl;
	cout<<"upper_bound(dat,10,5)="<<upper_bound(dat,10,5)<<endl;
	cout<<"upper_bound(dat,10,8)="<<upper_bound(dat,10,8)<<endl;
	cout<<"upper_bound(dat,10,9)="<<upper_bound(dat,10,9)<<endl;
	return 0;
}
