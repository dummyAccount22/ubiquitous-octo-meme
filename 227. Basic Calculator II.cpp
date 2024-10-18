class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if (len == 0) return 0;
        
        int currentNumber = 0;
        int previousNumber = 0, result = 0;
        char operation = '+';
        
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = currentNumber*10 + (currentChar - '0');
            }
            
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    previousNumber = -currentNumber;
                    result += previousNumber;
                } else if (operation == '+') {
                    previousNumber = currentNumber;
                    result += previousNumber;
                } else if (operation == '*') {
                    result -= previousNumber;
                    previousNumber *= currentNumber;
                    result += previousNumber;
                } else if (operation == '/') {
                    result -= previousNumber;
                    previousNumber /= currentNumber;
                    result += previousNumber;
                }
                
                operation = currentChar;
                currentNumber = 0;
            }
        }
        
            return result;
    }
};
