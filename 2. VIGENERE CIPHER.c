#include<stdio.h>
#include<string.h>
int main(){
 char plaintext[100], key[100];
 printf("Enter Plain text : ");
 gets(plaintext);
 printf("Enter Keyword : ");
 gets(key);
 int msgLen = strlen(plaintext), keyLen = strlen(key), i, j;
 char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 for(i = 0, j = 0; i < msgLen; ++i, ++j)
{
    if(j == keyLen){
            j = 0;
    }
 newKey[i] = key[j];
}
 newKey[i] = '\0';
 for(i = 0; i < msgLen; ++i)
 {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
            encryptedMsg[i] = ((plaintext[i] - 97 + newKey[i] - 97) % 26) + 'a';
        else
            encryptedMsg[i] = ((plaintext[i] + newKey[i]) % 26) + 'A';
 }
 encryptedMsg[i] = '\0';
 for(i = 0; i < msgLen; ++i)
 {
        if(encryptedMsg[i] >= 'a' && encryptedMsg[i] <= 'z')
        {
            decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'a';
        }
        else
            decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 }
 decryptedMsg[i] = '\0';
 printf("Original Message: %s", plaintext);
 printf("\nKey: %s", key);
 printf("\nNew Generated Key: %s", newKey);
 printf("\nEncrypted Message: %s", encryptedMsg);
 printf("\nDecrypted Message: %s", decryptedMsg);
return 0;
}

