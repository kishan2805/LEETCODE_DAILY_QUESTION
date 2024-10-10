// 1st oct 

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         vector<int> rem(k, 0);  

        
//         for (int num =0;num< arr.size();num++) {
//             int remainder = ((arr[num] % k) + k) % k;  //positive remainder
//             rem[remainder]++;
//         }

        
//         for (int i = 0; i <= k / 2; i++) {
//             if (i == 0) {  
//                 // remainder 0, there must be an even number of such elements
//                 if (rem[i] % 2 != 0) {
//                     return false;
//                 }
//             } 
//             else {
//                 // General case: check if remainder `i` can pair with `k - i`
//                 if (rem[i] != rem[k - i]) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };


// 2nd oct 

// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {

//         map<int,int>mp;
//         int count=1;
//         vector<int>a=arr;

//         sort(a.begin(),a.end());

//         for (int i = 0; i < a.size(); i++) {
//             // int ele = a[i];
//             if (mp.find(a[i]) == mp.end()) { 
//                 // Only assign a rank to the 
//                 // element if it hasn't been ranked yet
//                 mp[a[i]] = count++;
//             }
//         }

//     // Replace elements in the original array 'arr' with their ranks
//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = mp[arr[i]];
//         }

//         return arr;

            
        
//     }
// };



// 3rd oct 

// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
// /*The problem lies in how you approach finding the smallest subarray whose sum, when removed, leaves the total sum divisible by p. There are two main issues in the code:

// Brute-force prefix sum check: You are using a nested loop approach to check for all possible subarrays, which is inefficient for large arrays and leads to incorrect results in some cases. You need to reduce the number of checks and optimize the search process.*/


//     //     long long int sum=0;
//     //     for (int i=0;i<nums.size();i++){
//     //         sum+=nums[i];
//     //     }
//     //     int rem=sum%p;
//     //     // no need to reduce
//     //     if(rem==0)    return 0;
//     //     // remove 1 ele
//     //     for(int i=0;i<nums.size();i++){
//     //         if(nums[i]==rem)    return 1;
//     //     }

//     //     // prefix sum 
//     //     vector<long long int>pre;
//     //     long long int sum1=0;
//     //     for(int i=0;i<nums.size();i++){
//     //         sum1+=nums[i];
//     //         pre.push_back(sum1);
//     //     }


//     //     int count=2;
//     //     // int x=0;
//     //     // int y=count-1;
//     //     while(count<nums.size()){
//     //         // long long int s=0;
//     //         for(int i=0,k=count-1;k<nums.size();i++,k++){
//     //             if(i==0){
//     //                 // s=pre[k];
//     //                 if(pre[k]==rem) return count;
//     //             }
//     //             else{
//     //                 if(pre[k]-pre[i-1]==rem)    return count;
//     //             }
                
                
//     //         }
//     //         count++;
//     //     }
//     //     return -1;
//     // }  
//         long long sum = 0;
//         for (int num : nums) {
//             sum += num;
//         }
        
//         int rem = sum % p;
//         if (rem == 0) {
//             return 0;  // No need to remove any subarray if already divisible by p
//         }

//         unordered_map<int, int> prefixMap;
//         prefixMap[0] = -1;  // To handle the case where the prefix sum itself is the solution
        
//         int minLength = nums.size();
//         long long prefixSum = 0;
        
//         for (int i = 0; i < nums.size(); i++) {
//             prefixSum += nums[i];
//             int currentRem = prefixSum % p;
            
//             // We want to find if there's a previous prefix that makes (prefixSum - some previous prefix) % p == rem
//             int target = (currentRem - rem + p) % p;
            
//             if (prefixMap.find(target) != prefixMap.end()) {
//                 minLength = min(minLength, i - prefixMap[target]);
//             }
            
//             // Store the current prefix sum modulo and its index
//             prefixMap[currentRem] = i;
//         }
        
//         return minLength == nums.size() ? -1 : minLength;
//     }
// };


// 4th oct

// class Solution {
// public:

//     long long dividePlayers(vector<int>& skill) {
//         sort(skill.begin(),skill.end());
//         int i=0;
//         int j=skill.size()-1;
//         long long  sum=0;
//         while(i<=j){
//             if((skill[0]+skill[skill.size()-1])==(skill[i]+skill[j])){
//                 sum+=(skill[i]*skill[j]);
//             }
//             else{
//                 return -1;
//             }
//             i++;
//             j--;
//         }
//         return sum;
//     }
// };


// 5th oct 

// class Solution {
// public:
//     // Optimized solution
//     bool checkInclusion(string s1, string s2) {
//         // If s2 is smaller than s1, return false
//         if (s2.length() < s1.length()) return false;

//         // Create frequency maps for s1 and the initial window of s2
//         vector<int> s1Freq(26, 0), s2Freq(26, 0);
        
//         // Fill the frequency map for s1 and the first window of size s1 in s2
//         for (int i = 0; i < s1.length(); ++i) {
//             s1Freq[s1[i] - 'a']++;
//             s2Freq[s2[i] - 'a']++;
//         }

//         // Slide the window over s2
//         for (int i = s1.length(); i < s2.length(); ++i) {
//             // Check if the frequency maps are equal
//             if (s1Freq == s2Freq) return true;

//             // Update the window: add the new character and remove the old one
//             s2Freq[s2[i] - 'a']++;             // Add new character to window
//             s2Freq[s2[i - s1.length()] - 'a']--; // Remove old character from window
//         }

//         // Final check for the last window
//         return s1Freq == s2Freq;
//     }
    
// };



// 7th oct 

// #include<iostream>
// #include<string.h>
// #include<stack>
// using namespace std;

// int minLength(string s) {
//     stack<char>st;
//     // int n=s.length();
//     int top=-1;

//     for(int i=0;i<s.length();i++){
        
//         if(top==-1 ){
//             st.push(s[i]);
//             top++;
//         }
//         else{
//             // if b comes check the top is not a 
//             char a=st.top();
//             char b=s[i];
//             if(b=='B'&& a=='A'){
//                 st.pop();
//                 top--;
//             }
//             else if(b=='D'&&a=='C'){
//                 st.pop();
//                 top--;
//             }
//             else{
//                 st.push(b);
//                 top++;
//             }
//         }
        
//         // if d comes check top is not c
//     }
//     return top+1;
// }

// int main(){
//     string s="ABFCACDB";
//     cout<<"ans is : "<<minLength(s)<<endl;
// }


// 8th oct 

// class Solution {
// public:
//     int minSwaps(string s) {
//         int count=0;
//         int i=0;
//         int j=s.length()-1;

//         stack<char>st;

//         // for the first index 
//         if(s[0]==']'){
//             i++;
//             while(s[j]!='['){
//                 j--;
//             }
//             count++;
            
//             // swap(s[0],s[j]);
//             j--;
//             st.push('[');
//         }

//         while(i<=j){
            
//             if(s[i]=='['){
//                 i++;
//                 st.push('[');
//             }
//             // case 2. s[i]=']'
//             else{
//                 if(!st.empty() && st.top()=='['){
//                     // complete thing no swap 
//                     st.pop();
//                     i++;
//                 }
//                 else if( st.empty()){
//                     while(s[j]!='['){
//                         j--;
//                     }
//                     // swap(s[i],s[j]);
//                     count++;
//                     st.push('[');
//                     i++;
//                     j--;
//                 }
//             }
//         }
//         return count;
//     } 
    
// };


// 9th oct 

// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         // stack<char>st;
//         // for (int i=0;i<s.length();i++){
//         //     if(s[i]=='('){
//         //         st.push('(');
//         //     }
//         //     else if(s[i]==')'&& !st.empty()){
//         //         if(st.top()=='('){
//         //             st.pop();
//         //         }
//         //         else{
//         //             st.push(')');
//         //         }

//         //     }
//         //     else if(s[i]==')'){
//         //         st.push(')');
//         //     }
//         // }
//         // return st.size();

//         int open=0;
//         int clo=0;

//         for(int i=0;i<s.length();i++){
//             if(s[i]=='('){
//                 open++;
//             }
//             else{
//                 if(open>0)  open--;
//                 else{
//                     clo++;
//                 }
//             }
//         }
//         return open+clo;
        
//     }
// };



// 10th oct

