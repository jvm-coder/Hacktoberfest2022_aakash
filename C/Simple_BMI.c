#include <stdio.h>

int main(){


    float a,b,c,d;
    printf("Enter your weight in Kg\n>>");
    scanf("%f",&a);


    if(a < 0){
        printf("Negative weight is not possible\nExiting program....\n");
    }

    else if(a == 0){
        printf("Weight cannot be zero.\nExiting the program.....\n");
    }

    else if(a > 0){

        printf("Enter your height in meters\n>>");
        scanf("%f",&b);

        if(b < 0) {
            printf(" Height cannot be negative.\nExiting the program\n");
        }
        else if(b == 0){
            printf("Height cannot be zero.\nExiting the program.....\n");
        }

        else if(b > 0){

            c = b*b;
            d = a / c;
            printf("Your BMI is %.3f\n",d);

            if(d <= 15){
                printf("You are underweight!\n");
            }
            else if(d > 15 && d <= 25 ){
                printf("You must in good shape.\n");
            }
            else if(d > 25 && d <= 30){
                printf("You are overweight!\n");
            }
            else if(d > 30){
                printf("You are obese!!\n");
            }

        }


    }


    return 0;
}

