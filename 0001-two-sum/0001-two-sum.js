/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let obj = {};
    let n = nums.length;
    let ans = [];
    for(let i=0; i< n; i++) {
        let first = nums[i];
        let second = target - nums[i];
        if(obj.hasOwnProperty(second)) {
            ans.push(i);
            ans.push(obj[second]);
            return ans;
        }
        else {
            obj[first] = i;
        }
    }
    return ans;
};