class Solution {
public:
    
    string removeKdigits(string num, int k) {
        if(k >= num.size()) // if the characters to delete is greater than or equal to the initial string
            return "0";
        
        stack<char> st;
        int size = int(num.size()); // for ease use

        for(int i = 0; i < size; i++){
            while(not st.empty() and num[i] < st.top() and k){
                // while the current number is less than the previous number pop the previous number to delete the most significant digits from the answer and check the number of pops you made not to exceed them, also, check if the stack is empty to avoid runtime errors
                st.pop(), k--;
            }
            // after ensuring that the current digit is in its right place, push it to the answer stack
            st.push(num[i]);
        }
        
        num.clear(); // clear the string to assign the final answer
        while(not st.empty()){ // push the remaining characters in the stack to the ans
            num.push_back(st.top()), st.pop();
        }
        while(num.back() == '0' and num.size() > 1)
            // remove the leading zeros before reversing the string to provide the final answer
            num.pop_back();
        
        reverse(num.begin(), num.end()); // change the number back to its initial order after the stack reversed it
        
        if(k >= num.size()) // if the remaining deletion operations is greater than or equal to the remaining digits return a zero digit
            return "0";
        
        while(k--){ // if there are more deletion operations or the digits are sorted descendingly, remove them from the back of the number
            num.pop_back();
        }
        
        return num; // finally, return the final answer to the problem
    }
};