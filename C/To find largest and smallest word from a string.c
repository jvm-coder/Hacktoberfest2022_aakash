#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[100],s1[100][100];
    int i,j=0,k=0,m=0,n=0,max,min;
    printf("Enter a string: ");
    gets(s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' ')  {
            s1[k][j]='\0';
            k++;
            j=0;
        }
        else{
            s1[k][j]=s[i];
            j++;
        }
    }
    s1[k][j]='\0';
    max=strlen(s1[0]);
    min=strlen(s1[0]);
    
    for(i=0;i<=k;i++){
        if(max<strlen(s1[i])){
            m=i;
            max=strlen(s1[m]);
        }
        if(min>strlen(s1[i])){
            n=i;
            min=strlen(s1[n]);
        }
    }
    printf("Largest word is: %s",s1[m]);
    printf("\nSmallest word is: %s",s1[n]);
    return 0;
}
