#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "Enter brackets: ";
    string input;
    if (!getline(cin, input))
        return 0;

    int n = input.size();
    vector<bool> used(n, false);
    string result;

    
    for (int i = 0; i < n; i++) {
        char ch = input[i];
        char closing;
        if (ch == '(')       closing = ')';
        else if (ch == '[')  closing = ']';
        else if (ch == '{')  closing = '}';
        else
            continue;  

        
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && input[j] == closing) {
                
                result += ch;
                result += closing;
                used[j] = true;  
                break;
            }
        }
    }

    cout << "Correct bracket pairing: " << result << endl;
    return 0;
}
