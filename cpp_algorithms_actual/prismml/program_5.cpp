#include <iostream>
#include <vector>
using namespace std;

vector<int> computeFailureFunction(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0;

    for (int i = 1; i < m; i++) {
        while (length > 0 && pattern[i] != pattern[length]) {
            length = lps[length - 1];
        }
        if (pattern[i] == pattern[length])
            length++;
        lps[i] = length;
    }

    return lps;
}

int kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeFailureFunction(text, pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j; // Found the pattern
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1; // Pattern not found
}

int main() {
    string text = "ABABABABABABABABAB";
    string pattern = "ABABAB";
    int result = kmpSearch(text, pattern);

    if (result != -1)
        cout << "Pattern found at index: " << result << endl;
    else
        cout << "Pattern not found." << endl;

    return 0;
}
