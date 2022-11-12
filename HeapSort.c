#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
//����ʼ����ת��Ϊ�� 
void heapinsert(int a[],int i)
{
	while(a[i]>a[(i-1)/2]) //�ȸ��󣬽���ѭ�� 
	{
		swap(a,i,(i-1)/2);
		i=(i-1)/2; //����Ϊ�����±꣬�����Ƚϣ�ֱ�������ڵ�ǰ�ĸ� 
	}
}
//�ѻ�
void heapify(int a[],int heapsize)
{
	int i=0;
	int left=2*i+1;
	int max; 
	while(left<heapsize)
	{
		//1)�����Һ�������ֵ�������ӣ�ֻ���ж��Һ��� 
		if(left+1<heapsize&&a[left+1]>a[left])  
			max=(a[left+1]>a[i]?left+1:i);
		//2)�Һ��Ӳ����ڻ���ֵС�����ӣ�ֻ���ж����� 
		else
			max=(a[left]>a[i]?left:i);
		//�ص㣺������Ϊ���ֵ���˳�ѭ�������������޷����£�������ѭ�� 
		if(max==i)
			break;
		//����λ�����±� 
		swap(a,i,max);
		i=max; 
		left=2*i+1; //�������� 
	}
}
//������ 
void heapsort(int a[],int heapsize)
{
	if(heapsize==0) //�����Ĵ������������ 
	return;
	swap(a,0,--heapsize); //�����ֵ�Ƴ��ѣ��ѿռ�ѹ��һλ 
	heapify(a,heapsize); //��a[0]�ѻ� 
	heapsort(a,heapsize); //�ݹ���ã�ѹ���ѿռ� 
}
int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	//��������ת��Ϊ�� 
	for(i=0;i<length;i++) //O(N) 
	{
		heapinsert(a,i); //O(logN)
	}
	heapsort(a,length);
	//����
	for(i=0;i<length;i++)
		printf("%-3d",a[i]); 
	return 0;
} 
