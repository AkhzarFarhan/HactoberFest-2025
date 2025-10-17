function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (arr[mid] === target) {
            return mid; // Return the index if found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if not found
}

// Example usage
let sortedArr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let targetBinary = 5;
let indexBinary = binarySearch(sortedArr, targetBinary);
console.log(`Element found at index: ${indexBinary}`);

//Contributed by Prasad Kandekar