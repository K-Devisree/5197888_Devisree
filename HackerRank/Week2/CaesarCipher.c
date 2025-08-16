Question: Caesar Cipher
Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts each letter by a number of letters. If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc


Solution:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int n,k;
    scanf("%d",&n);
    getchar();
    char b[n+1];
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';
    scanf("%d",&k);
    k = k % 26;
    for(int i=0; b[i]!='\0'; i++){
        if(isupper(b[i])){
            b[i] = 'A' + (b[i]-'A' + k) % 26;
        } else if(islower(b[i])){
            b[i] = 'a' + (b[i]-'a' + k) % 26;
        }
    }
    printf("%s\n",b);
    return 0;
}
