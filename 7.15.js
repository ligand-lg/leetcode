/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const MIN = -1 * Math.pow(2, 31)
    const MAX = Math.pow(2, 31) -1
    const sigal = x > 0 ? 1 : -1
    x = Math.abs(x)
    let x_s = x.toString()
    let new_str = []
    for (c of x_s) {
        new_str.unshift(c)
    }
    new_str = new_str.join('')
    let result = parseInt(new_str) * sigal
    if (result < MIN || result > MAX) {
        result = 0
    }
    return result
};


