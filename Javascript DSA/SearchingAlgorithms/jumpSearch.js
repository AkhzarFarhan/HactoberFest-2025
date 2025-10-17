function jumpSearch(arr, target) {
    let n = arr.length;
    let step = Math.floor(Math.sqrt(n)); // Optimal jump size
    let prev = 0;

    while (arr[Math.min(step, n) - 1] < target) {
        prev = step;
        step += Math.floor(Math.sqrt(n));
        if (prev >= n) {
            return -1; // If we've gone past the end of the array
        }
    }

    // Linear search within the block
    while (arr[prev] < target) {
        prev++;
        if (prev === Math.min(step, n)) {
            return -1; // If we've reached the end
        }
    }

    return arr[prev] === target ? prev : -1; // Return index or -1
}

// Example usage
let arrJump = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
let targetJump = 7;
let indexJump = jumpSearch(arrJump, targetJump);
console.log(`Element found at index: ${indexJump}`);

//Contributed by Prasad Kandekar