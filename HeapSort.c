#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
//将初始数组转换为堆 
void heapinsert(int a[],int i)
{
	while(a[i]>a[(i-1)/2]) //比父大，进入循环 
	{
		swap(a,i,(i-1)/2);
		i=(i-1)/2; //更新为父的下标，继续比较，直至不大于当前的父 
	}
}
//堆化
void heapify(int a[],int heapsize)
{
	int i=0;
	int left=2*i+1;
	int max; 
	while(left<heapsize)
	{
		//1)存在右孩子且其值大于左孩子，只需判断右孩子 
		if(left+1<heapsize&&a[left+1]>a[left])  
			max=(a[left+1]>a[i]?left+1:i);
		//2)右孩子不存在或其值小于左孩子，只需判断左孩子 
		else
			max=(a[left]>a[i]?left:i);
		//重点：若本身为最大值，退出循环，否则左孩子无法更新，陷入死循环 
		if(max==i)
			break;
		//交换位置与下标 
		swap(a,i,max);
		i=max; 
		left=2*i+1; //更新左孩子 
	}
}
//堆排序 
void heapsort(int a[],int heapsize)
{
	while(heapsize>0) //堆消耗殆尽，排序完成
	{
	swap(a,0,--heapsize); //将最大值移出堆，堆空间压缩一位 
	heapify(a,heapsize); //将a[0]堆化
	}
}
int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	//遍历数组转换为堆 
	for(i=0;i<length;i++) //O(N) 
	{
		heapinsert(a,i); //O(logN)
	}
	heapsort(a,length);
	//检验
	for(i=0;i<length;i++)
		printf("%-3d",a[i]); 
	return 0;
} 
