//插入排序
void insertsort(int dat[],int len){
	int i,j,temp;
	if(dat==NULL||len<=1) return ;
	for(i=1;i<len;++i)
	{
		j=i;
		temp=dat[j];
		while (j>0&&dat[j-1]>temp){
			dat[j]=dat[j-1];
			--j;
		}
		dat[j]=temp;
	}
}
