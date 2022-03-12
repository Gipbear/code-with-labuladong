#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        def nSumTarget(nums, n, start, target):
            sz = len(nums)
            res = []
            if n < 2 or sz < n:
                return res
            if n == 2:
                l, r = start, sz - 1
                while l < r:
                    tmp = nums[l] + nums[r]
                    left, right = nums[l], nums[r]
                    if tmp < target:
                        while l < r and nums[l] == left:
                            l += 1
                    elif tmp > target:
                        while l < r and nums[r] == right:
                            r -= 1
                    else:
                        res.append([left, right])
                        while l < r and nums[l] == left:
                            l += 1
                        while l < r and nums[r] == right:
                            r -= 1
            else:
                for i in range(start, sz):
                    if start < i and i < sz - 1 and nums[i] == nums[i-1]:
                        continue
                    sub = nSumTarget(nums, n-1, i+1, target-nums[i])
                    for arr in sub:
                        arr.append(nums[i])
                        res.append(arr)
            return res
        
        nums.sort()
        return nSumTarget(nums, 4, 0, target)
# @lc code=end

