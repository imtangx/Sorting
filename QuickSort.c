#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
void quicksort(int a[],int left,int right)
{
	if(left>=right) //递归调用中的（i-1）可能越界，所以为>=条件 
	return;
	int target=a[right]; //每次选最后一个元素作目标值
	//快慢指针 
	int i=left;
	int j=left-1; //++j的存在 
	int k=right; //--k的存在，且最后一个数先不排序 
	while(i<k)
	{
		if(a[i]==target)
		{
			i++;
		}
		else if(a[i]<target)
		{
			swap(a,i++,++j); //注意 
		}
		else if(a[i]>target)
		{
			swap(a,i,--k); //注意 
		}
	}
	swap(a,k,right); //将右区的第一个元素与目标值交换 
	quicksort(a,left,i-1); 
	quicksort(a,i,right);  
}
int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,length-1);
	//检验
	for(i=0;i<length;i++)
	printf("%-3d",a[i]); 
	return 0;
}
