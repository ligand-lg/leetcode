var lengthOfLongestSubstring = function (s) {
    const s_len = s.length
    let end_index, sub_set
    for (let window_size = (new Set(s)).size; window_size > 0; window_size--) {
        end_index = s_len - window_size
        for (let i = 0; i <= end_index; i++){
            sub_set = new Set(s.slice(i, i+window_size))
            if (sub_set.size === window_size){
                return window_size
            }
        }
    }
    return 0
};
console.log(lengthOfLongestSubstring('avc'))