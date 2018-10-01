// takes sorted array and key
// returns index of key elemnt, -Infinity otherwise
function binarySearch(array, key) {
    first = 0;
    last = array.length;
    middle = (first + last) / 2;
    while (first <= last) {
        // the middle value is smaller than wanted key
        // search upper part insted.
        if (array[middle] < key) {
            first = middle + 1;
        }
        // the middle value is equal to wanted value
        else if (array[middle] == key) {
            return middle;
        }
        // the middle value is bigger than wanted key
        // search lower part insted.
        else {
            last = middle - 1;
        }

        middle = (first + last) / 2;
    }

    // didn't find key
    return Number.NEGATIVE_INFINITY;
}

sampleArray = [1, 2, 3, 4, 5, 6];

sampleKey = 2;

console.log(binarySearch(sampleArray, sampleKey));