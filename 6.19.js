/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1) {
        return s
    }
    const martix = []
    for (let i = 0; i < numRows; i++){
        martix.push([])
    }
    // 通过 s 来构建矩阵
    const TOP = numRows - 1, BOTTOM = 0, s_len = s.length
    let x = 0, y = 0, isMainBar = true
    for (let s_index = 0; s_index < s_len; s_index++) {
        console.log(`${x}${y}`)
        martix[y][x] = s[s_index]
        // 更新 x，y
        if (isMainBar) {
            if (y === TOP) {
                x += 1
                y -= 1
                isMainBar = false
            } else {
                y++
            }
        } else {
            if (y === BOTTOM) {
                y ++
                isMainBar = true
            }else {
                x += 1
                y -= 1
            }
        }
    }
    for (let i = 0; i < numRows; i++) {
        martix[i] = martix[i].join('')
    }
    return martix.join('')
};
console.log(convert('PAYPALISHIRING', 2))