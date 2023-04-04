/// Nahi chalega yeh
// Skill issue 
// bohot hi jyadda
#include <stdio.h>
void print_array(int l[],int n)
{
for (int t=0;t<n;t++)
{
    printf("%d\n",l[t]);
}
}
void merge(int a[],int l,int m,int r)
{
    // printf("merge\n");
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[100000],R[1000000];
    // printf("n1 %d\n",n1);
    // printf("n2 %d\n",n2);
    for (int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for (int i=0;i<n2;i++)
    {
        R[i]=a[m+1+i];
    }
    // printf("Left\n");
    // print_array(L,n1);
    // printf("right\n");
    // print_array(R,n2);
    i=0;
    j=0;
    k=l;
    while((i<n1)&&(j<n2))
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
            k++;
        }
        else
        {
            a[k]=R[j];
            j++;
            k++;
        }
        
        
    }
    while(i<n1)
        {
            a[k]=L[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            a[k]=R[j];
            j++;
            k++;
        
        }
}
void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        // printf("merge sort\n");
        int mid=(l+r)/2;
		
        // printf("l1 %d\n",l);
        // printf("h1 %d\n",r);
        // printf("m1 %d\n",mid);
        merge_sort(a,l,mid);

        // printf("l2 %d\n",l);
        // printf("h2 %d\n",r);
        // printf("m2 %d\n",mid);
        merge_sort(a,mid+1,r);

        // printf("l3 %d\n",l);
        // printf("h3 %d\n",r);
        // printf("m3 %d\n",mid);
        merge(a,l,mid,r);

        // printf("l4 %d\n",l);
        // printf("h4 %d\n",r);
        // printf("m4 %d\n",mid);
    }
    else
    {
        return;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[100000],b[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
		b[i]=a[i];
    }
    merge_sort(a,0,n-1);
    // print_array(a,n);
	int c=0;
	for (int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			// int index=linear_search(b,a[i],i,n);
			int x=a[i],index;
			for(int j=i+1;j<n;j++)
			{
				if(b[j]==x)
				{
					index=j;
					break;
				}
			}
			// swap(b,i,index);
			int temp=b[i];
			b[i]=b[index];
			b[index]=temp;
			c++;
		}
	}
	printf("%d\n",c);
    return 0;
}