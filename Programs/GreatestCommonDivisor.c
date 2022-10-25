 #include<stdio.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int x, y =- 1;
    printf("Enter numbers. To exit enter 0\n");
    while(1)    // infinite loop to take input
    {
        scanf("%d", &x);
        if(x < 1)
            break;
        else if(y ==- 1)    // only 1 number entered, its GCD is itself
            y = x;
        else if(x < y)
            y = gcd(x, y);
        else
            y = gcd(y, x);
    }
    printf("\n\n\nGCD of all the entered number is: %d", y);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

// GCD of 2 numbers is calculated at a time
int gcd(int a, int b) 
{
    int i;
    /*
        a is the smallest of the two numbers 
        of which GCD is to be calculated
    */
    for(i = a; i >= 1; i--) 
    {
        // Greatest number that divides both the numbers
        if(a%i == 0 && b%i == 0) 
            break;  // exits the loop
    }
    return i;
}
