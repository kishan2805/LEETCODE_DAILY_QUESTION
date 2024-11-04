class Solution {
public:
    string compressedString(string word) {
        // only 1 element
        if(word.length()==1){
            return '1'+word;
        }

        int count =1;
        string comp="";

        for(int i=0;i<word.length();i++){
            if(word[i]==word[i+1] && count<9){
                // in cpp 
// operator[]: No bounds checking; risky and can lead to undefined behavior.
// .at(): Safer; throws an std::out_of_range exception if the index is invalid.
                count++;
            }
            else{

                // used += other wise it will give MLE
                /*
                comp += "something":

This operator appends the string "something" directly to the existing string comp.
The memory allocation can be more efficient since it tries to reuse the existing memory of comp if there's enough space available.
It doesn't create a temporary object, which can reduce the overhead and memory usage.
comp = comp + "something":

This operation first creates a temporary string that is the result of comp + "something".
It then assigns this new string back to comp.
This involves additional memory allocation for the temporary string and might lead to more frequent reallocations and copies if comp grows significantly over time.

                */
                comp+=to_string(count)+word[i];
                count=1;
            }
        }
        
        
        return comp;
    }
};