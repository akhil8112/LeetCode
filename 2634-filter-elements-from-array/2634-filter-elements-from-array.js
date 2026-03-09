/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */


var filter = function(arr, fn) {
    let arrn=[];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            arrn.push(arr[i]);
        }
    }
    return arrn;
};