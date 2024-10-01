class Solution:
    def twoSum(self, nums, target):
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] == target:
                return [l, r]
            elif nums[l] + numr[r] > target:
                r -= 1
            else:
                l += 1

if __name__ == '__main__':
    testcases = [
        {
                'input': {
                    nums = [2,7,11,15], 
                    target = 9
                },
                'output': [0,1]
        }
    ]
    print(testcases)
    s = Solution()
    nums = [2,7,11,15]
    target = 9
    s.twoSum(nums, targe)
