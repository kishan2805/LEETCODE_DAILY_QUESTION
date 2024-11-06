class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        vector<int>arr=nums;
        sort(arr.begin(), arr.end());
        int cur;
        int next;

        int a =0;int b=0;
        for(int i=0;i<nums.size()-1;i++){
            // checking for change 
            bitset<16> binary2(nums[i]);
            cur=binary2.count();

            bitset<16> binary1(nums[i+1]);
            next=binary1.count();

            // agar same bits ho to b ko aage karo 
            if(cur==next){
                b++;
            }
            // agar same bit na ho to a to b to sort karo 
            // aur a aur b ko set karo to next index
            else{
                // sort
                sort(nums.begin() + a, nums.begin() + b + 1);
                a=i+1;
                b=a;
            }    
        }
        // for last iteration of a and b 
        sort(nums.begin() + a, nums.begin() + b + 1);

        if(arr==nums)    return true;

        return false;
        
    }
};