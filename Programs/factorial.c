#include<stdio.h>
#include<conio.h>
int main()
{
    int num, i, fact=1;
    printf("Enter any number: ");
    scanf("%d", &num);
    for(i=num; i>0; i--)
        fact = fact*i;
    printf("\nFactorial of %d = %d", num, fact);
    getch();
    return 0;
}
