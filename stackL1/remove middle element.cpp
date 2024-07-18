class Solution
{
    
    void solve(stack<int>&s,int cnt, int size){
        
        // base case 
        
        if(cnt == size/2){
            
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        
        // resursice call
        solve(s,cnt+1, size);
        s.push(num);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        
        int cnt=0;
        solve(s, cnt,sizeOfStack );
    }
};


