#include<stdio.h>
void Merge(int arr[], int low, int mid, int high){
	int temp1, temp2, i, j, k=low;
	temp1=mid-low+1;
	temp2=high-mid;
	int arr1[temp1], arr2[temp2];
	for(i=0;i<temp1;i++)
		arr1[i]=arr[i+low];
	for(j=0;j<temp2;j++)
		arr2[j]=arr[mid+j+1];
	i=0;
	j=0;
	while(i<temp1 && j<temp2){
		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
		}
		else{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
	for(;i<temp1;i++)
		arr[k++]=arr1[i];
	for(;j<temp2;j++)
		arr[k++]=arr2[j];
}
void MergeSort(int arr[], int low, int high){
    if(low>=high)
    	return;
    int mid=(low+high)/2;
	MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
 	Merge(arr,low,mid,high);
}
void main(){
	int size, i;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter array elements in unsorted order:");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	MergeSort(arr,0,size-1);
	printf("Sorted array: ");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
