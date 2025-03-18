class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();

        int l=0,r=0;
        int maxi=-1;
        int curr=0;

        while(r<n){
        
          while((curr&nums[r])!=0){
              curr=(curr^nums[l]);
              l++;
          }
          curr=(curr|nums[r]);
          
          if((r-l+1)>maxi){
            maxi=(r-l+1);
          }
          r++;
        }
        return maxi;
    }
};
