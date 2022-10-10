var arr =[8,3,1,2,5,4,7,6]
let n=arr.length

function selectionSort(arr,n){
   for(let i=0;i<n-1;i++){
       let min=i
       for(let j=i+1;j<n;j++){
             if(arr[j]<arr[min]) {
                min =j;
             }
            }
            let temp=arr[min] 
           arr[min]=arr[i]
           arr[i]=temp  
        // swap(arr,min,i)
   }
   return arr
}
console.log(selectionSort(arr,n));