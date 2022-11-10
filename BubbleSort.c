#include <stdio.h>
void swap(int *sum1,int *sum2);

int main()
{
	int i=0,j,length;
	scanf("%d",&length);
	int a[length];
	while(i<length)
	scanf("%d",&a[i++]);
	for(i=0;i<length;i++)
	{
		for(j=0;j<length-i-1;j++) //注意：大的数慢慢沉到右边去，所以边界是往左缩减，进入条件会变化 
		{
			if(a[j]>a[j+1])
			swap(&a[j],&a[j+1]);
		}
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
