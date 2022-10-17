import java.util.*;
class symmetric
{
    void main()
    {
      Scanner sc=new Scanner(System.in);
      int r=0,c=0,flag=0,i,j;
      int matrix[][];
      System.out.println("Enter no of rows");
      r=sc.nextInt();
      System.out.println("Enter no of column");
      c=sc.nextInt();
      if(r!=c)
      {
         System.out.println("not symmetric");
        }
else
{
    matrix=new int[r][c];
  System.out.println(" Enter elements for Matrix");
  for( i=0;i<r;i++)
  {
      for(j=0;j<c;j++)
      {
          matrix[i][j]=sc.nextInt();
        }
    }
    for( i=0;i<r;i++)
  {
      for(j=0;j<c;j++)
      {
          if(matrix[i][j]!=matrix[j][i])
          {
              flag=1;
              break;
            }
        }
    }
  System.out.println("Matrix is");
  for( i=0;i<r;i++)
  {
      for(j=0;j<c;j++)
      {
          System.out.print(matrix[i][j]+"\t");
        }
        System.out.println();
    }
    if(flag==0)
    {
        System.out.println(" Symmetric Matrix ");
    }
    else
    {
        System.out.println("not a Symmetric Matrix ");
    }
}
}
}
        
  