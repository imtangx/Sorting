#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int left,int mid,int right)
{
	int *help=(int*)malloc((right-left+1)*sizeof(int)); //申请临时数组 
	int i=0;
	//双指针滑动 
	int p1=left;
	int p2=mid+1;
	while(p1<=mid&&p2<=right)
	{
		help[i++]=(a[p1]<a[p2]?a[p1++]:a[p2++]);
	}
	while(p1<=mid)
	{
		help[i++]=a[p1++];
	}	
	while(p2<=right)
	{
		help[i++]=a[p2++];
	}
	for(i=0;i<right-left+1;i++)
	{
		a[left+i]=help[i]; //重点：a[left+i]而并非a[i],每次归并a的左边界不一定为0 
	}
	free(help);
}

void process(int a[],int left,int right)
{
	if(left==right) //只有一个元素，开始向上归并 
	return;
	int mid=left+(right-left)/2;
	process(a,left,mid); //左区递归划分 
	process(a,mid+1,right); //右区递归划分 
	merge(a,left,mid,right);
}

int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	process(a,0,length-1);
	//检验 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
} 
