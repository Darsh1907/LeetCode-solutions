// time complexity is O(n). 

var canPlaceFlowers = function(flowerbed, n) {
    for(let i=0; i<flowerbed.length; i++) {
        if(flowerbed[i] === 0) {
            if((flowerbed[i-1]===0 && flowerbed[i+1]===0) || 
               (flowerbed[i-1]===undefined && flowerbed[i+1]===0) || 
                (flowerbed[i+1]===undefined && flowerbed[i-1]===0) || 
                (flowerbed[i-1]===undefined && flowerbed[i+1]===undefined)) {
                n--;
                i++;
            } 
        }
    }
    return n > 0 ? false : true;
};

// Example usage
var flowerbed = [1, 0, 0, 0, 1];
var n = 1;
var canPlace = canPlaceFlowers(flowerbed, n);
console.log("Can place flowers:", canPlace);