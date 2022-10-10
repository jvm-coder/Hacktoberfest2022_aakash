function quickSort(arr, low, high) {
    if (low < high) {
      let pivot = partition(arr, low, high);
  
      quickSort(arr, low, pivot - 1);
      quickSort(arr, pivot + 1, high);
  
  }
  return arr;
  }
  
  function partition(arr, low, high) {
    let pivot = arr[high];
    let i = low - 1;
  
    for (let j = low; j < high; j++) {
      if (arr[j] < pivot) {
          i++;
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    i++;
    let temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
  }
  
  let arr = [5, 6, 2, 1, 3];
  let n=arr.length
  console.log(quickSort(arr, 0, n-1));
  