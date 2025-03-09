class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();

        int l=0,r=1;
        int prev=colors[0];

        int cnt=0;
        while(l<n){
            if(colors[r%n]==prev){
                l=r;
            }

            if((r-l+1)>k){
                l++;
            }
            if((r-l+1)==k && l<n){
                cnt++;
            }
            prev=colors[r%n];
            r++;
            
        }
        return cnt;
    }
};
