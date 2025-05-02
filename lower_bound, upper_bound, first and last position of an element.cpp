//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
int Upper(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;

    int lower=nums.size();
    while(low<=high)
    {
        mid = low+(high-low)/2;

        if(nums[mid]>target)
        {
            lower = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    return lower;
}
int Lower(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;

    int lower=nums.size();
    while(low<=high)
    {
        mid = low+(high-low)/2;

        if(nums[mid]>=target)
        {
            lower = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    return lower;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lower = Lower(nums,target);
        if(lower==nums.size() || nums[lower]!=target)
            return {-1,-1};
        return {lower,Upper(nums,target)-1};
    }
};
