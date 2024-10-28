/*
removing duplicates from array in O(n) time and O(1) space complexity using a Map data structure
for eg : arr = [2,2,3,3,4,5,5,6]
output : [2,3,4,5,6]
*/

class Solution {
  removeDuplicates(arr) {
    let narr = [];
    let map = new Map();
    for (let it of arr) {
      if (!map.get(it)) map.set(it, 1);
      else {
        let val = map.get(it);
        map.set(it, val+1);
      }
    }
    for (let it of map.keys()) {
      narr.push(it);
    }
    return narr;
  }
}
