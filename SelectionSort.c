#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
int main()
{
	int a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	int i,j;
	for(i=0;i<length-1;i++) //小优化：最后一个元素自动有序，无需遍历 
	{
		int k=i; //初始化：当前值为最小值 
		for(j=i+1;j<length;j++)
		{
			if(a[j]<a[k])
			k=j; //记录最小值下标 
		}
		if(k!=i)
		swap(a,k,i);
	}
	//检验 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
}


