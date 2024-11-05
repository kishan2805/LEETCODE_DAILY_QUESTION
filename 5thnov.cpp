class Solution {
public:
    int minChanges(string s) {
        int count=1 ;
        int change=0;

        // we will traverse in loop and if the change is in odd counter 
        // we will change it 

        // for(int i=0;i<s.length();i++){
        //     if(s[i]!=s[i+1]){
        //         // even ;- no change 
        //         if(count%2==0){
        //             count=1;
        //         }
        //         // odd :-chnage 
        //         else{
        //             change++;
        //             i++;
        //             count=1;
        //         }
        //     }
        //     else{
        //         count++;
        //     }
        // }
        // return change;

// Approach 2 

        int i=0;
        int n=1;
        int m=s.length()/2;
        while(n<=m){
            // j=i;
            if(s[i]!=s[i+1]){
                change++;
            }
            i+=2;
            n++;
        }
        return change ;

    }
};