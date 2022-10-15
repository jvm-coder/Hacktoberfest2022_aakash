
// arr is the array on which binary search is to be performed
// x is the search element
// start is the start index of the search
// end is the ending index of the search

let binarySearch = function (arr, x, start, end) {
      
    // Intialize start as the start point
    // end as the end of an array
    // Mid variable to be search in an array.

    let mid=Math.floor((start + end)/2);
    
    if (start > end) return false;
    else if (arr[mid]===x) return true;
    else if(arr[mid] > x)
        return binarySearch(arr, x, start, mid-1);
    else
         return binarySearch(arr, x, mid+1, end);
}
  
