int partion(int dat[],int s,int e){
	int temp=0;
	int i=s;
	int j=e;
	if(dat==NULL||s<0||e<0) return -1;
	temp=dat[i];
	while (i<j)
	{
		while (i<j&&dat[j]>=temp) --j;
		if (i<j) dat[i++]=dat[j];
		while (i<j&&dat[i]<temp) ++i;
		if (i<j) dat[j--]=dat[i];
	}
	dat[i]=temp;
	return i;
}
void  sort(int dat[],int s,int e){
	if(s<e){
		int std=partion(dat,s,e);
		if(std==-1) return ;
		sort(dat,s,std-1);
		sort(dat,std+1,e);
	}
}
