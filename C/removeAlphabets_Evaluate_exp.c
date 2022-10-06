#include <stdio.h>
#include <stdlib.h>

int removeAlphabetsEvaluateExp(char *expression)
{
    int r=0;
    int a=0;
    int j=0;
    int b=0;
    char c;
    for(int i=0;i<strlen(expression);i++){
        if(isalpha(expression[i])) continue;
        expression[j++]=expression[i] ;
    }
    expression[j]='\0';
    sscanf(expression,"%d%n",&r,&j);
    expression+=j;
    while(sscanf(expression,"%c%d%n",&c,&b,&j)==2){
        expression+=j;
        switch(c){
    case '+' : r+=b;break;
    case '-' : r-=b;break;
    case '*' : r*=b;break;
    case '/' : r/=b;break;} }
    printf("%s",expression);
    return r;
}

int main()
{
    char expression[101];
    scanf("%s", expression);
    printf("%d", removeAlphabetsEvaluateExp(expression));
    return 0;
}
