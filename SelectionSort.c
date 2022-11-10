#include <stdio.h>
void swap(int *sum1,int *sum2);

int main()
{
	int i=0,j,k,length;
	scanf("%d",&length);
	int a[length];
	while(i<length)
	scanf("%d",&a[i++]);
	for(i=0;i<length-1;i++) //小优化：最后一项无需遍历 
	{
		k=i; //对k1初始化，假设最小值为当前项 
		for(j=i+1;j<length;j++) 
		{
			if(a[j]<a[k])
			k=j; //记录最小值的下标,a[k]为此时的最小值 
		}
		swap(&a[i],&a[k]);
	}
	
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
}
void swap(int *sum1,int *sum2)
{
	int k=*sum1;
	*sum1=*sum2;
	*sum2=k;
}

