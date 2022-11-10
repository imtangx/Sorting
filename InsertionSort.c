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
		for(j=i-1;a[j]>=0&&a[j]>a[j+1];j--)
		{
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
