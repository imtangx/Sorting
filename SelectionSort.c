#include <stdio.h>
void swap(int *sum1,int *sum2);

int main()
{
	int i=0,j,k,length;
	scanf("%d",&length);
	int a[length];
	while(i<length)
	scanf("%d",&a[i++]);
	for(i=0;i<length-1;i++) //С�Ż������һ��������� 
	{
		k=i; //��k1��ʼ����������СֵΪ��ǰ�� 
		for(j=i+1;j<length;j++) 
		{
			if(a[j]<a[k])
			k=j; //��¼��Сֵ���±�,a[k]Ϊ��ʱ����Сֵ 
		}
		swap(&a[i],&a[k]);
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

