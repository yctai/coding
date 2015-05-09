/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    var mod = 0,
        new_sum = n,
        sqr = [ 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 ],
	    route = new Array(1000);

    while ( new_sum > 1 ) {
        n = new_sum;
        new_sum = 0;
        while ( n > 0 ) {
            mod = n % 10;
            new_sum += sqr[mod];
            n = (n - mod) / 10;        
        }
        if ( route[new_sum] ) {
            return false;
        } else {
            route[new_sum] = 1;
        }
    }
    if ( new_sum == 1 ) {
        return true;
    }
    return false;
};

for ( var i = 0; i < 30; i++ ) {
    console.log(isHappy(i));
}

for ( var i = 999500; i < 999999 ; i++ ) {
    console.log(isHappy(i));
}
