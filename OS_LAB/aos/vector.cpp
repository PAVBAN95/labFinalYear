#include<stdio.h>
struct clock{
    int a[3];
};

int max1(int a, int b)    //to find the maximum timestamp between two events
{
	if (a>b)
	return a;
else
return b;
}

int main()
{
int i,j,k,e1,e2,dep[20][20];
clock p1[20], p2[20];
printf("enter the events : ");
scanf("%d %d",&e1,&e2);
for(i=0;i<e1;i++){

p1[i].a[1]=i+1;
p1[i].a[2]=0;
}
for(i=0;i<e2;i++){
p2[i].a[2]=i+1;
p2[i].a[1]=0;
}
for(int i=0;i<e1;i++)
{
    printf("\n%d %d", p1[i].a[1], p1[i].a[2]);
}
for(int i=0;i<e2;i++)
{
    printf("\n%d %d", p2[i].a[1], p2[i].a[2]);
}

printf("enter the dependency matrix:\n");
printf("\t enter 1 if e1->e2 \n\t enter -1, if e2->e1 \n\t else enter 0 \n\n");
for(i=0;i<e2;i++)
printf("e2%d ",i+1);
for(i=0;i<e1;i++)
{
printf("\ne1%d ",i+1);
for(j=0;j<e2;j++)
scanf("%d",&dep[i][j]);
}


for(i=0;i<e1;i++)
{
	for(j=0;j<e2;j++)
	{
		if(dep[i][j]==1)     //change the timestamp if dependency exist
		{	p2[j].a[1]=max1(p2[j].a[1],p1[i].a[1]);
			for(k=j;k<e2-1;k++)
			p2[k+1].a[1]=p2[k].a[1];
		}
		if(dep[i][j]==-1)    //change the timestamp if dependency exist
		{
			p1[i].a[2]=max1(p1[i].a[2],p2[j].a[2]);
			for(k=i;k<e1-1;k++)
			p1[k+1].a[2]=p1[k].a[2];
		}

	}
}

printf("P1 : ");     //to print the outcome of Lamport Logical Clock
for(i=0;i<e1;i++)
{
    

    printf("[%d %d] ",p1[i].a[1], p1[i].a[2]);
    

}
printf("\n P2 : ");
for(j=0;j<e2;j++){
    printf("[%d %d] ",p2[j].a[1], p2[j].a[2]);
}


return 0 ;
}