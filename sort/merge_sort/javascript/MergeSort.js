
let merge = function(left, right) {
  let arr = [];

  while (left.length && right.length) {
    if (left[0] < right[0]) {
      arr.push(left.shift());
    } else {
      arr.push(right.shift());
    }
  }
  return arr.concat(left.slice().concat(right.slice()));
};



let mergeSort = function(arr) {
  if (arr.length < 2) {  // don't divide the array 
    return arr;
  }

  const middle = Math.floor(arr.length / 2);
  const left = arr.slice(0, middle); // left part of array
  const right = arr.slice(middle);

  return merge(mergeSort(left), mergeSort(right)); //sort left and right part of array and merge
};

const array = [5, 3, 7, 1, 0, 8, 5];
let result = mergeSort(array.slice()); 
console.log(result)

