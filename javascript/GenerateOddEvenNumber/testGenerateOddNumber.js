function generateNumber(l, r) {
    const arr = [];
    if (l === "ganjil") {
        for(let x=r; x<=r; x++){
            for (let i = 0; i <= r+x; i++) {
                if (i % 2 !== 0) {
                    arr.push(i);
                }
            }
        }
        
    } else {
        for(let x=r; x<=r; x++){
            for (let i = 1; i <= r+x; i++) {
                if (i % 2 === 0) {
                    arr.push(i);
                }
            }
        }
    }


    console.log(arr);
}

generateNumber("genap", 6);
