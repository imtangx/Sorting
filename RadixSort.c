#include <stdio.h>
#include <math.h>
#include <limits.h>
//ȡ�����λ�� 
int getdigit(int a[],int length)
{
	int i,max=INT_MIN,digit=0;
	for(i=0;i<length;i++)
	{
		max=(a[i]>max?a[i]:max);
	}
	while(max>0)
	{
		max/=10;
		digit++;
	}
	return digit;
}
//ȡ�õ�ǰ�Ƚ�λ 
int getd(int a,int d)
{
	return a/(int)pow(10,d-1)%10; //�ص� 
}
//����������� 
void radixsort(int a[],int length,int digit)
{
	int *help=(int*)malloc(length*sizeof(int));
	int i,j,d;
	for(d=1;d<=digit;d++) //�Ӹ�λ��ʼ�Ƚ� 
	{
		int *count=(int*)malloc(10*sizeof(int));
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
		for(i=0;i<length;i++)
		{
			j=getd(a[i],d); //ͳ�Ƽ������� 
			count[j]++;
		}
		for(j=1;j<10;j++)
		{
			count[j]=count[j]+count[j-1]; //��������ת��Ϊǰ׺�� 
		}
		//�����������ÿ�η��ڶ�Ӧǰ׺�͵��ұ߽�<==>Ͱ����������ұ���ʱ����Ͱ�ķ�����߽��ȳ�Ͱ
		for(i=length-1;i>=0;i--)  
		{
			j=getd(a[i],d);
			help[count[j]-1]=a[i]; //���ڶ�Ӧǰ׺�͵��ұ߽�
			count[j]--; //�ұ߽�����һλ 
		}
		for(i=0;i<length;i++)
		{
			a[i]=help[i]; //��ֵ��ԭ���� 
		}
	}
}
int main()
{
	int i,a[]={5,12,3,11};
	int length=sizeof(a)/sizeof(a[0]);
	radixsort(a,length,getdigit(a,length));
	//����
	for(i=0;i<length;i++)
	printf("%5d",a[i]); 
	return 0;
}
