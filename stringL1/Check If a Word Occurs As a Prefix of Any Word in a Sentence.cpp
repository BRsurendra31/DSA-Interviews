class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.size();
        if(sentence.size()<n)return -1;
        if(sentence.substr(0,n)==searchWord)return 1;
        int c=1;
        for(int i=0;i<sentence.size()-n;i++){
            if(sentence[i]==' '){
                string re=sentence.substr(i+1,n);
                if(re==searchWord)return c+1;
                c+=1;
            }
        }
        return -1;
    }
};