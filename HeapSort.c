#include <stdio.h>
void swap(int *a,int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
//����ʼ����ת��Ϊ�� 
void HeapInsert(int a[],int i)
{
	while(a[i]>a[(i-1)/2]) //���ȸ��󣬽���ѭ�� 
	{
		swap(a,i,(i-1)/2);
		i=(i-1)/2; //���Լ���Ϊ�� �������Ƚϣ�ֱ�������ڵ�ǰ�ĸ� 
	}
}
//��Ԫ�ضѻ� 
void Heapify(int a[],int HeapSize)
{
	int i=0;
	int left=2*i+1;
	int max; 
	while(2*i+1<HeapSize) //�������ӣ�������ѭ�� 
	{
		left=2*i+1;
		if(left+1<HeapSize&&a[left+1]>a[left])
		max=(a[left+1]>a[i]?left+1:i);
		else
		max=(a[left]>a[i]?left:i);
		//�ص㣺���������������������� 
		if(max==i)
		{ 
		break; //������ֵΪ�����˳�ѭ��������i���䣬������ѭ�� 
		} 
		swap(a,max,i);
		i=max; //����λ�ò������±� 
	}
}	
//������ 
void HeapSort(int a[],int HeapSize)
{	
	if(HeapSize==0) //�ѱ����Ĵ������������ 
	return;
	swap(a,0,HeapSize-1); //����ǰ������Ƴ��� 
	HeapSize--; //�ѿռ�ѹ��һλ 
	Heapify(a,HeapSize);  //�ѻ��µ�a[0] 
	HeapSort(a,HeapSize); //�ݹ����sort��ѹ���ѿռ� 
}
int main()
{
	int a[]={1,3,8,2,4,10,5,};
	int length=sizeof(a)/sizeof(a[0]);
	int i=0;
	for(i=0;i<length;i++) //��ÿ��������   //O(N) 
	{
		HeapInsert(a,i); //O(logN)	
	}
	HeapSort(a,length);
	
	for(i=0;i<length;i++)
	printf("%-5d",a[i]);
	return 0;
} 
