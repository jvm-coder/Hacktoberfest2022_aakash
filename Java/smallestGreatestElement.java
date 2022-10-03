public class smallestGreatestElement {

    public static void main(String[] args) {

        char []arr={'c','f','j'};
        char target='g';
        int start=0;
        int end=arr.length-1;

        System.out.println(arr[binarySearch(arr,start,end,target)]); 
        
    }

    public static int binarySearch(char[] arr,int start,int end,char target)
    {
        while(start<=end)
        {
            //c,f,j // j
            int mid=start+(end-start)/2;
            if(target==arr[mid])
                {if(mid+1<arr.length-1)
                {return mid+1;}
            else{return 0;} }
            if(target>arr[mid]){start=mid+1;}
            if(target<arr[mid]){end=mid-1;}
        }
        if(start<arr.length)
                {return start;}
        else{return 0;}
        

    }
    
}
