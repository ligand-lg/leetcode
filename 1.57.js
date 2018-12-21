/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const len = nums.length
    for (let i = 0; i<len; i++) {
        const aim = target - nums[i]
        for (let j = i+1; j < len; j++) {
            if (nums[j] == aim) {
                return [i,j]
            }
        }
    }
};