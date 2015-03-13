#include<stdio.h>
int main()
{

	int p,r,i,j,flag,wh=1,state=0,cnt=0;

	printf("Enter number of processes:\n");
	scanf("%d",&p);
	printf("Enter number of resources:\n");
	scanf("%d",&r);

	int res[r],c[p][r],a[p][r],v[1][r],n[p][r],x[p];

	for(i=0;i<p;i++)
	{

		x[i]=0;

	}

	printf("Enter the available matrix:\n");
	for(i=0;i<r;i++)
	{

		scanf("%d",&v[1][i]);

	}

	printf("Enter the current allocation matrix:");
	for(i=0;i<p;i++)
	{

		printf("\n");
		for(j=0;j<r;j++)
		{

			scanf("%d",&a[i][j]);

		}

	}

	printf("Enter the maximum demand matrix:");
	for(i=0;i<p;i++)
	{

		printf("\n");
		for(j=0;j<r;j++)
		{

			scanf("%d",&c[i][j]);

		}

	}

	printf("Enter the resource matrix:\n");
	for(i=0;i<r;i++)
	{

		scanf("%d",&res[i]);

	}
	
	for(i=0;i<p;i++)
	{

		for(j=0;j<r;j++)
		{

			n[i][j]=c[i][j]-a[i][j];

		}

	}

	while(wh==1)
	{

		for(i=0;i<p;i++)
		{

			if(x[i]==1)
			{

				continue;

			}	
			flag=0;
			for(j=0;j<r;j++)
			{

				if(n[i][j]<=v[1][j])
				{

					flag++;

				}

			}
			if(flag==r)
			{

				printf("%d",state);
				state=1;
				for(j=0;j<r;j++)
				{

					x[i]=1;
					v[1][j]+=a[i][j];
					a[i][j]=0;
					c[i][j]=0;
					n[i][j]=0;

				}
				cnt++;
				break;

			}
	

		}

		if(state==0)
		{

			printf("This is an unsafe state\n");
			break;

		}
		else
		{

			printf("\n\nAvailable matrix\n");
			for(i=0;i<r;i++)
			{

				printf("%d\t",v[1][i]);

			}

		}

		if(cnt==p)
		{

			wh=0;
			break;
		
		}

	}












/*

	printf("\nA\n");
	for(i=0;i<p;i++)
	{

		printf("\n");
		for(j=0;j<r;j++)
		{

			printf("%d\t",a[i][j]);

		}

	}

	printf("\n\nC\n");
	for(i=0;i<p;i++)
	{

		printf("\n");
		for(j=0;j<r;j++)
		{

			printf("%d\t",c[i][j]);

		}

	}

	printf("\n\nN\n");
	for(i=0;i<p;i++)
	{

		printf("\n");
		for(j=0;j<r;j++)
		{

			printf("%d\t",n[i][j]);

		}

	}

*/

}
