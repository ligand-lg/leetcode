/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    const INT_MAX = Math.pow(2, 31) - 1
    const INT_MIN = Math.pow(-2, 31)
    let result =  parseInt(str)
    if (!result) {
        result = 0
    }else if (result > INT_MAX) {
        result = INT_MAX
    }else if (result < INT_MIN) {
        result = INT_MIN
    }
    return result
};
console.log(myAtoi('asdfni'))