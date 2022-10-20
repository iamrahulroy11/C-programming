//wap to accept a sentence and print the word that is maximum in length
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],w[50],m[50];
    int l,i,k=0,len;
    
    printf("Enter the sentence ");
    gets(s);
    strcat(s," ");//concatinate 
    l=strlen(s);
    strcpy(m,"");//Assign NULL
    for(i=0;i<l;i++)
    {
        if(s[i]!=' ')
         w[k++]=s[i];
        else
        {
            w[k]='\0';
            if(strlen(w)>strlen(m))
             strcpy(m,w);
             
            k=0;
        }
         
    }
    printf("\n Maximum word %s",m);
}
