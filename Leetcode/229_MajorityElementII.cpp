class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int sz = nums.size();
        int e1=-1, e2=-1;
        int c1=0, c2=0;

        for(int i=0; i<sz; i++){
            if(e1 == nums[i]){
                c1++;
            }
            else if(e2 == nums[i]){
                c2++;
            }
            else if(c1 == 0){
                e1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                e2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;
        for(int i=0; i<sz; i++){
            if(nums[i] == e1)
                c1++;
            else if(nums[i] == e2)
                c2++;
        }
        
        if(c1 > sz/3)
            ans.push_back(e1);
        if(c2 > sz/3)
            ans.push_back(e2);
        return ans;
    }
};
