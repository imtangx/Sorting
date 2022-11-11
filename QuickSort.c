#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
void quicksort(int a[],int left,int right)
{
	if(left>=right) //�ݹ�����еģ�i-1������Խ�磬����Ϊ>=���� 
	return;
	int target=a[right]; //ÿ��ѡ���һ��Ԫ����Ŀ��ֵ
	//����ָ�� 
	int i=left;
	int j=left-1; //++j�Ĵ��� 
	int k=right; //--k�Ĵ��ڣ������һ�����Ȳ����� 
	while(i<k)
	{
		if(a[i]==target)
		{
			i++;
		}
		else if(a[i]<target)
		{
			swap(a,i++,++j); //ע�� 
		}
		else if(a[i]>target)
		{
			swap(a,i,--k); //ע�� 
		}
	}
	swap(a,k,right); //�������ĵ�һ��Ԫ����Ŀ��ֵ���� 
	quicksort(a,left,i-1); 
	quicksort(a,i,right);  
}
int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,length-1);
	//����
	for(i=0;i<length;i++)
	printf("%-3d",a[i]); 
	return 0;
}
