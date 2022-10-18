#include<stdio.h>
#include<math.h>
int main()
{
	int x,temp,c=0,r,sum=0;
		printf("Enter the x:");
		scanf("%d",&x);		
	temp=x;
	while(temp>0)
	{
		temp=temp/10;
		c++;
	}
	  temp=x;
	  while(temp>0){
	  	r=temp%10;
	  	temp=temp/10;
	  	sum+=pow(r,c);
	  }
	  if(sum==x)
	  printf("It is an armstrong number!");
	  else
	  printf("It is not an armstrong number!");
		return 0;
		
}
