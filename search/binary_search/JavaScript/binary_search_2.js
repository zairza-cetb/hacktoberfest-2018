const arr = [1,5,6,7,0]
const toFind = 11

const binarySearch = (arr, nToFind) => {
    console.dir(arr)
    var medio = Math.floor(arr.length/2)
    console.dir(medio)
    if (arr.length > 1)
        return binarySearch(arr.slice(0, medio), nToFind) || binarySearch(arr.slice(medio, arr.length), nToFind)
    return arr[0] === nToFind
}

console.dir(linearSearch(arr, toFind))