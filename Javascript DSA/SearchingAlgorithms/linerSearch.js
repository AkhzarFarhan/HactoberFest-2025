function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Example usage
let arr = [5, 3, 8, 4, 2];
let target = 4;
let index = linearSearch(arr, target);
console.log(`Element found at index: ${index}`);

//Contributed by Prasad Kandekar