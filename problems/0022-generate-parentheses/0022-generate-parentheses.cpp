class Solution {
public:
    public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current_string = "";
        
        // Start the backtracking process
        backtrack(result, current_string, 0, 0, n);
        
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current_string, int open_count, int close_count, int n) {
        // Base case: If the string length reaches 2 * n, a valid combination is formed
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }
        
        // Rule 1: We can always add an opening parenthesis if we haven't reached 'n'
        if (open_count < n) {
            backtrack(result, current_string + "(", open_count + 1, close_count, n);
        }
        
        // Rule 2: We can only add a closing parenthesis if it matches an open one
        if (close_count < open_count) {
            backtrack(result, current_string + ")", open_count, close_count + 1, n);
        }
    }
};