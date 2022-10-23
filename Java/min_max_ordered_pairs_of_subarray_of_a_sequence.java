int[] findMinMax(int A[], int n)
{
    int max, min
    int i
    if ( n is odd )
    {
        max = A[0]
        min = A[0]
        i = 1
    }
    else
    {
        if ( A[0] < A[1] )
        {
            max = A[1]
            min = A[0]
        }
        else
        {
            max = A[0]
            min = A[1]
        }
        i = 2
    }
    while ( i < n )
    {
        if ( A[i] < A[i+1] )
        {
            if ( A[i] < min )
                min = A[i]
            if ( A[i+1] > max )
                max = A[i+1]
        }
        else
        {
            if ( A[i] > max )
                max = A[i]
            if ( A[i+1] < min )
                min = A[i+1] 
        }
        i = i + 2
    }
    // By convention, we assume ans[0] as max and ans[1] as min
    int ans[2] = {max, min}
   return ans
}
