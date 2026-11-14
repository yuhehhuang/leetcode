class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen ={} #{key,value}
        for i,num in enumerate(nums):
            check = target - num
            if check in seen :
                return [seen[check],i]

            seen[num]=i
        