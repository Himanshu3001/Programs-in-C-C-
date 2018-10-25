#include<stdio.h>
#include<conio.h>
void merge(int arr[],int low, int mid,int high);
void mergesort(int arr[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(arr,i,mid);
		mergesort(arr,mid+1,j);
		merge(arr,i,mid,j);
	}
}
void merge(int arr[],int low, int mid,int high)
{
	int temp[20],i,j,k,m;
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=high)
	{
		temp[k++]=arr[j++];
	}
	for(m=low;m<=high;m++)
	{
		arr[m]=temp[m];
	}
}
void main()
{
	int i,arr[10],n;
	clrscr();
	printf("Enter value of n:");
	scanf("%d",&n);
	printf("Enter value in array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	printf("After Sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
}