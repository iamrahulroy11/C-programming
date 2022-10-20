// accept a sentence and print those words that begins with vowel
//nice day
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],w[50],r[50];
    int l,i,k=0,len;
    
    printf("Enter the sentence ");
    gets(s);
    strcat(s," ");//concatinate 
    l=strlen(s);
    
    for(i=0;i<l;i++)
    {
        if(s[i]!=' ')
         w[k++]=s[i];
        else
        {
            w[k]='\0';
            strcpy(r,w); //copy the word in variable r
            strupr(r); // convert into uppercase
            len=strlen(w);
            if(r[0]==r[len-1])
             printf("\n %s",w);
             
            k=0;
        }
         
    }
    
}
