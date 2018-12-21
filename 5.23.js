/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var palindrome = (start, end) => {
        for (;start < end; start++, end--) {
            if (s[start] !== s[end]) {
                return false
            }
        }
        return true
    }
    const s_len = s.length
    for (let len = s.length; len > 0; len--) {
        const end_index = s_len - len
        for (let start = 0; start <= end_index; start++) {
            if (palindrome(start, start+len-1)) {
                return s.substring(start, start+len)
            }
        }
    }
};

console.log(longestPalindrome(''))