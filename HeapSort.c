#include <stdio.h>
void swap(int *a,int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
//将初始数组转换为堆 
void HeapInsert(int a[],int i)
{
	while(a[i]>a[(i-1)/2]) //若比父大，进入循环 
	{
		swap(a,i,(i-1)/2);
		i=(i-1)/2; //将自己变为父 ，继续比较，直至不大于当前的父 
	}
}
//将元素堆化 
void Heapify(int a[],int HeapSize)
{
	int i=0;
	int left=2*i+1;
	int max; 
	while(2*i+1<HeapSize) //还有左孩子，即进入循环 
	{
		left=2*i+1;
		if(left+1<HeapSize&&a[left+1]>a[left])
		max=(a[left+1]>a[i]?left+1:i);
		else
		max=(a[left]>a[i]?left:i);
		//重点：！！！！！！！！！！！ 
		if(max==i)
		{ 
		break; //如果最大值为本身，退出循环，否则i不变，陷入死循环 
		} 
		swap(a,max,i);
		i=max; //交换位置并交换下标 
	}
}	
//堆排序 
void HeapSort(int a[],int HeapSize)
{	
	if(HeapSize==0) //堆被消耗殆尽，排序结束 
	return;
	swap(a,0,HeapSize-1); //将当前最大数移出堆 
	HeapSize--; //堆空间压缩一位 
	Heapify(a,HeapSize);  //堆化新的a[0] 
	HeapSort(a,HeapSize); //递归调用sort，压缩堆空间 
}
int main()
{
	int a[]={1,3,8,2,4,10,5,};
	int length=sizeof(a)/sizeof(a[0]);
	int i=0;
	for(i=0;i<length;i++) //对每个数遍历   //O(N) 
	{
		HeapInsert(a,i); //O(logN)	
	}
	HeapSort(a,length);
	
	for(i=0;i<length;i++)
	printf("%-5d",a[i]);
	return 0;
} 
