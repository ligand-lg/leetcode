/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var reverse = x => {
        let result = 0
        div = Math.floor(x/10)
        mod = x % 10
        while (div !== 0) {
            result = result * 10 + mod
            x = div
            div = Math.floor(x/10)
            mod = x % 10
        }
        return result * 10 + mod
    }
    let result = false
    if (x >= 0 && reverse(x) === x) {
        result = true
    }
    return result
};
console.log(isPalindrome(-123))
