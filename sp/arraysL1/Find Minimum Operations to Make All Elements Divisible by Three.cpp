#include <iostream>
#include <vector> 

using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();
        int opr=0;

        for(int i=0; i<n; i++){

            if(nums[i] % 3 != 0){

                if((nums[i]+ 1) % 3 == 0){
                    opr++;
                }
                else if((nums[i] - 1 ) % 3 == 0){
                    opr++;
                }


            }

        }

        return opr;
        
    }
};


/* 

// other
class Solution {
    public int minimumOperations(int[] nums ) {
        int n=nums.length;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int mod=nums[i]%3;
            if(mod==1||mod==2)
            {
                count++;
            }

        }
        return count;
    }
}
*/