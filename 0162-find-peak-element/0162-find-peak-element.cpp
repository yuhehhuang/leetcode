class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        {
            return 0;
        }

        if(nums[0] > nums[1])
        {
            return 0;
        }

        if(nums[n-1] > nums[n-2])
        {
            return n-1;
        }
        int low = 1;
        int high = n-2;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            //下面都是mid鄰居是遞增或遞減

            else if(nums[mid] > nums[mid - 1])
            {//遞增
                low = mid + 1;
            }

            else
            {//遞減
                high = mid -1;
            }
        }
        return -1;
    }
};