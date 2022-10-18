import java.util.Scanner;  

public class SumOfNaturalNumber3  

{  

public static void main(String[] args)   

{     

int num, i, sum = 0;  

//object of Scanner class  

Scanner sc = new Scanner(System.in);  

System.out.print("Sum from: ");  

//takes an integer as input  

i = sc.nextInt();  

System.out.print("Sum up to: ");  

//takes an integer as input  

num = sc.nextInt();  

while(i <= num)  

{  

//adding the value of i into sum variable  

sum = sum + i;  

//increments the value of i by 1  

i++;  

}  

//prints the sum  

System.out.println("Sum of Natural Numbers = " + sum);  

}  

}  
