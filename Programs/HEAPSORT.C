#include<stdio.h>
#include<conio.h>
int temp;
void heapify(int arr[],int n,int i);
void heapsort(int arr[],int n);
void main()
{
	int arr[10],n,i;
	clrscr();
	printf("Enter Number of Elements:");
	scanf("%d",&n);
	printf("Enter values for Array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapsort(arr,n);
	getch();
}
void heapsort(int arr[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);
	}
	printf("After Applying HeapSort \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void heapify(int arr[],int n,int i)
{
	int la=i,l=2*i+1,r=2*i+2;
	if(l<n && arr[l]>arr[la])
	{
		la=l;
	}
	if(r<n && arr[r]>arr[la])
	{
		la=r;
	}
	if(la!=i)
	{
		temp=arr[i];
		arr[i]=arr[la];
		arr[la]=temp;
		heapify(arr,n,la);
	}
}
