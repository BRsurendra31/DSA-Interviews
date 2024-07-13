
// o(n)


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        
        int indx = -1;
        int mini = INT_MAX;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i] < mini){
                
                mini = arr[i];
                indx=i;
            }
        }
        
        return indx;
    }
};

// 0(logn)

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        
        int indx = -1;
        int mini = INT_MAX;
        int l=0, h=arr.size()-1;
        
        while(l <=h){
            
            int mid = (l+h)/2;
            if(arr[l] <= arr[h]){
                
                mini = min(mini, arr[l]);
                indx=l;
                
                break;
            }
            
            
            if(arr[l] <=arr[mid]){
                
                mini = min(mini, arr[l]);
                indx= l;
                l= mid +1;
                
            }
            
            else{
                
                mini = min(mini, arr[mid]);
                indx= mid;
                h = mid-1;
            }
            
        }
        
        return indx;
    }
};