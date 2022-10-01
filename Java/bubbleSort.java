public class bubbleSort {

    public static void main(String args[]){

        int arr[]= {7,2,1,23,18,9}; // example of an unsorted array

        //bubble sort code

        for(int i=0; i<arr.length-1; i++)
		{
			for(int j=0; j<arr.length-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
    }
    
}
