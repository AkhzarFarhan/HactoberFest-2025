function binarySearchInRange(arr, left, right, target) {
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

function exponentialSearch(arr, target) {
    if (arr[0] === target) return 0; // If the first element is the target

    let i = 1;
    while (i < arr.length && arr[i] <= target) {
        i *= 2; // Exponentially increasing index
    }

    return binarySearchInRange(arr, i / 2, Math.min(i, arr.length - 1), target);
}

// Example usage
let arrExponential = [2, 3, 4, 10, 40, 50, 60];
let targetExponential = 10;
let indexExponential = exponentialSearch(arrExponential, targetExponential);
console.log(`Element found at index: ${indexExponential}`);

//Contributed by Prasad Kandekar