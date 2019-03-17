/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
  let ans = -Infinity
  const MaxNum = Math.max(...nums)
  // 同号合并
  for (let i = nums.length; i > 0; i--) {
    if ((nums[i] >= 0 && nums[i - 1] >= 0) || (nums[i] <= 0 && nums[i - 1] <= 0)) {
      nums[i - 1] += nums[i]
      nums.splice(i, 1)
    }
  }
  // 去掉左右两边负数
  if (nums.length > 0 && nums[0] <= 0) {
    nums.splice(0, 1)
  }
  if (nums.length > 0 && nums[nums.length - 1] <= 0) {
    nums.splice(nums.length - 1, 1)
  }
  // 结果判断
  switch (nums.length) {
    case 0:
      ans = MaxNum
      break
    case 1:
      ans = nums[0]
      break
    default:
      // check, nPlus 肯定为整数。
      const n = nums.length
      const nPlus = (n + 1) / 2
      if (!Number.isInteger(nPlus)) {
        throw `unexcept: ${nums}`
      }
      let addtionalLen = 0
      const tmp = []
      for (let i = 0; i <= n; i += 2) {
        tmp.push(nums[i])
        ans = nums[i] > ans ? nums[i] : ans
      }
      addtionalLen += 1
      for (; addtionalLen < nPlus; addtionalLen++) {
        for (let j = 0; j < nPlus - addtionalLen; j++) {
          const nextCoupleIndex = 2 * j + (addtionalLen - 1) * 2 + 1
          tmp[j] += nums[nextCoupleIndex] + nums[nextCoupleIndex + 1]
          ans = tmp[j] > ans ? tmp[j] : ans
        }
      }
  }
  return ans
}

console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))