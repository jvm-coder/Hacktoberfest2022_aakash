// Basic Patterns in Java

public class pattern {

	public static void main(String[] args) 
	{
		// Pattern 1
		int count=0;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=i;j++)
			{
				count++;
				System.out.format("%02d ",count);
			}
		    System.out.println("");
		}
		
		// Pattern 2
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=i;j++)
			{
				
				System.out.format("* ");
			}
		    System.out.println("");
		}
		
		// Pattern 3
		for(int i=5;i>=1;i--)
		{
			for(int j=1;j<=i;j++)
			{
				System.out.format(j+" ");
			}
		    System.out.println("");
		}
		
		
		
	    // Pattern 4
		for(int i=5;i>=1;i--)
		{
			for(int j=1;j<=i;j++)
			{
				System.out.print("* ");
			}
		    System.out.println("");
		}
		
	}

}
