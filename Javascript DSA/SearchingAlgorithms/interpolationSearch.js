function interpolationSearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low === high) {
            if (arr[low] === target) return low;
            return -1;
        }

        // Estimating the position of the target
        let pos = low + Math.floor(((target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        if (arr[pos] === target) {
            return pos; // Target found
        }
        if (arr[pos] < target) {
            low = pos + 1; // Search in the right half
        } else {
            high = pos - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// Example usage
let arrInterpolation = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
let targetInterpolation = 70;
let indexInterpolation = interpolationSearch(arrInterpolation, targetInterpolation);
console.log(`Element found at index: ${indexInterpolation}`);

//Contributed by Prasad Kandekar