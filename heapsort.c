void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void adjustheap(int dat[],int h,int len){
	int i=h;int j;
	if(dat==NULL||h<0||len<=0) return;
	while(2*i+1<len){
		j=2*i+1;
		if(j+1<len&&dat[j]<dat[j+1]) ++j;
		if(dat[j]>dat[i]) {swap(&dat[j],&dat[i]);i=j;}
		else break;
	}
	
}
void heapsort(int dat[],int len){
	int i,j;
	if(dat==NULL||len<=0) return;
	for(i=len/2;i>=0;--i){
		adjustheap(dat,i,len);
	}
	for(j=len-1;j>0;--j){
		swap(&dat[0],&dat[j]);
		adjustheap(dat,0,j);
	}
}
