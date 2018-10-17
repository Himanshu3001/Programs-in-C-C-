//knapsack using greedy.
#include<stdio.h>
#include<conio.h>
void main()
{
	int it[10],pr[10],we[10],i,j,n,W,t2,t3,t4,cap;
	float pw[10],t1,s[10],sum,sum1;
	clrscr();
	printf("Enter value of n:");
	scanf("%d",&n);
	printf("Enter Total Weight:");
	scanf("%d",&W);
	printf("Enter value of items:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&it[i]);
	}
	printf("Enter value of Profit:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pr[i]);
	}
	printf("Enter value of Weight:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&we[i]);
	}
	printf("Value of Profit by Weight:");
	for(i=0;i<n;i++)
	{
		pw[i]=(float) pr[i]/we[i];
		printf("%.2f\t",pw[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(pw[j+1]>pw[j])
			{
				t1=pw[j];
				pw[j]=pw[j+1];
				pw[j+1]=t1;

				t2=it[j];
				it[j]=it[j+1];
				it[j+1]=t2;

				t3=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=t3;

				t4=we[j];
				we[j]=we[j+1];
				we[j+1]=t4;
			}
		}
	}
	printf("\n value of Item in Descending order \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",it[i]);
	}
	printf("\n value of Profit in Descending order \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",pr[i]);
	}
	printf("\n value of Weight in Descending order \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",we[i]);
	}
	printf("\n value of Profit by Weight in Descending order \n");
	for(i=0;i<n;i++)
	{
		printf("%.2f\t",pw[i]);
		s[i]=0;
	}
	cap=W;
	for(i=0;i<n && cap>0;i++)
	{
		if(we[i]<cap)
		{
			s[i]=1;
			cap=cap-we[i];
			printf("\n %d item is selected  W=%d", it[i],we[i]);
		}
		else
		{
			s[i]=(float)cap/we[i];
			cap=0;
			printf("\n %d item is selected  W=%d",it[i],we[i]);
		}
	}
	printf("\n For Selected items \n");
	for(i=0;i<n;i++)
	{
		printf("%.2f\t",s[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+s[i]*we[i];
	}
	printf("\n Total Weight=%.2f",sum);
	for(i=0;i<n;i++)
	{
		sum1=sum1+s[i]*pr[i];
	}
	printf("\n Maximum Profit=%.2f",sum1);
	getch();
}