def reArrange(arr,n):
    low,high=0,n-1
    while(low<high):
        if(arr[low]<0):
            low+=1
        elif(arr[high]>0):
            high-=1
        else:
            arr[low],arr[high]=arr[high],arr[low]

def displayArray(arr,n):
    for i in range(n):
        print(arr[i],end=" ")

if __name__=='__main__':
    arr=list(map(int,input().split()))
    n=len(arr)
    reArrange(arr,n)
    displayArray(arr,n)
