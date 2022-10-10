function divide(arr, start, end) {
    if (start >= end) {
      return;
    }
    let mid = start + Math.floor((end - start) / 2);
  
    divide(arr, start, mid);
    divide(arr, mid + 1, end);
  
    mergeArr(arr, start, mid, end);
    return arr;
  }
  
  function mergeArr(arr, start, mid, end) {
    let merge = [];
  
    let i = start;
    let j = mid + 1;
  
    let k = 0;
  
    while (i <= mid && j <= end) {
      if (arr[i] <= arr[j]) {
        merge[k] = arr[i];
        i++;
        k++;
      } else {
        merge[k] = arr[j];
        j++;
        k++;
      }
    }
    while (i <= mid) {
      merge[k] = arr[i];
      k++;
      i++;
    }
    while (j <= end) {
      merge[k] = arr[j];
      j++;
      k++;
    }
    for (m = 0, n = start; m < merge.length; m++, n++) {
      arr[n] = merge[m];
    }
  }
  
  let arr = [5, 2, 6, 3, 9, 1, 7];
  let n = arr.length;
  console.log(divide(arr, 0, n - 1));