#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
int main()
{
	int a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	int i,j;
	for(i=0;i<length-1;i++) //С�Ż������һ��Ԫ���Զ������������ 
	{
		int k=i; //��ʼ������ǰֵΪ��Сֵ 
		for(j=i+1;j<length;j++)
		{
			if(a[j]<a[k])
			k=j; //��¼��Сֵ�±� 
		}
		if(k!=i)
		swap(a,k,i);
	}
	//���� 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
}


