Question: Sherlock and valid string
Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. If so, return YES, otherwise return NO.

Solution:

#include <stdio.h>
#include <string.h>

char* isValid(char* s) {
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) freq[s[i] - 'a']++;

    int counts[100] = {0}, unique = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            int found = 0;
            for (int j = 0; j < unique; j++) {
                if (counts[j] == freq[i]) { found = 1; break; }
            }
            if (!found) counts[unique++] = freq[i];
        }
    }

    if (unique == 1) return "YES";
    if (unique > 2) return "NO";

    int c1 = counts[0], c2 = counts[1];
    int f1 = 0, f2 = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == c1) f1++;
        else if (freq[i] == c2) f2++;
    }

    if ((f1 == 1 && (c1 - 1 == c2 || c1 - 1 == 0)) || (f2 == 1 && (c2 - 1 == c1 || c2 - 1 == 0)))
        return "YES";
    return "NO";
}

int main() {
    char str[100001];
    scanf("%s", str);
    printf("%s\n", isValid(str));
    return 0;
}
