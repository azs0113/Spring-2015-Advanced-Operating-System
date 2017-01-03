#include<stdio.h>
#include<stdlib.h>
void fifo()
{
int p[20],i,j=0,k,l=0,n,m,q[5],fault=0,z=0;
printf("enter no. of pages:");
scanf("%d",&n);
printf("enter the reference string:\n");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
printf("enter no. of frames:");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("\t\t%d",i);
}
for(j=0;j<m;j++)
{
q[j]=-1;
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(p[i]==q[j])
{
z++;
}
}
if(z==0)
{
fault++;
l=l%m;
q[l]=p[i];
l++;
printf("\n");
for(k=0;k<m;k++)
printf("\t\t%d",q[k]);
printf("\n");
}
z=0;
}
printf("\t no. of page faults=%d",fault);
}
int lru()
{
int p[20],i,j=0,k,l=0,n,m,q[5];
int fault=0,z=0,x[3],max=0;
int a,b,c;
printf("enter the number of pages:");
scanf("%d",&n);
printf("enter the reference string:\n ");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("enter the number of frames");
scanf("%d",&m);
for(i=0;i<m;i++)
q[i]=-1;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
if(p[i]==q[j])
z++;
if(z==0)
{
fault++;
if(i>m-1)
{
for(a=0;a<m;a++)
x[a]=0;
for(c=0;c<m;c++)
for(b=i;b>=0;b--)
{
if(q[c]!=p[b])
x[c]++;
else
break;
}
max=x[0];
l=0;
if(x[1]>max)
{
max=x[1];
l=1;
}
if(x[2]>max)
{
max=x[2];
l=2;
}
}
q[l]=p[i];
l++;
z=0;
for(k=0;k<m;k++)
printf("%d\t",q[k]);
printf("\n");
}
z=0;
}
printf("no of page faults %d\t",fault);
}
void main()
{
int choice;
printf("Select the algorithm to use\nFIFO Algorithm Enter 1 \nLRU Algorithm Enter 2\n ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("FIFO Algorithm\n" );
fifo();
break;
case 2 :
printf("LRU Algorithm\n" );
lru();
break;
default :
printf("Invalid choice\n" );
}
}