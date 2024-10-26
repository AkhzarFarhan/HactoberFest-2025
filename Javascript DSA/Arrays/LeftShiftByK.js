// Author: [Hridyanshu054](https://github.com/HRIDYANSHU054)
// Takes Theta(n) Time and Theta(1) Aux Space
// Examples
// I/P: leftRotateByK( [10, 5, 30, 15] , 3)
// O/P: 
// {
//     arr: [15, 10, 5, 30]
//     swap: 3
// }
// I/P: leftRotateByK( [10, 5, 30, 35] , 5)
// O/P: 
// {
//     arr: [5, 30, 35, 10]
//     swap: 3
// }
// I/P: leftRotateByK( [1, 2, 3, 4, 5] , 1)
// O/P: 
// {
//     arr: [2, 3, 4, 5, 1]
//     swap: 4
// }

function leftRotateByK ( arr, k ) {
    const size = arr.length;
    if( size <=1 ) return {arr, swap: 0};
    if( k > size ) k %= size;
    let i = 0;
    let cnt = 1;
    let swap = 0;
    while ( cnt < size ) {
        i = ( size + i - k ) % size;
        let value = arr[0];
        arr[0] = arr [ i ];
        arr[i] = value;
        ++cnt;
        ++swap;
    }
    return { arr, swap };      
}