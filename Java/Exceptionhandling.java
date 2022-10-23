class Exceptionhandling
{
     public static void main(String args[])
     {
          try{
               int num1,num2;
               num1 = 5;
               num2 = num1/0;
               System.out.print("A");
          }
          catch(ArithmeticException e)
          {
               System.out.print("0");
          
          }
          finally
          {
               System.out.print("B");
          }
          
     }
}