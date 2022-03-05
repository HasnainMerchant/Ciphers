#include<stdio.h>
#include<conio.h>
#include<string.h>

char message[100];

void decrypt(){
    char ch;
    int i, key;
    printf("Enter Key To Decrypt : ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
}
 printf("Decrypted message: %s", message);
}

void encrypt()
{
    char ch;
    int i, key;
    printf("Enter A Message To Encrypt: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
            }
        message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
        message[i] = ch;
    }
}
 printf("Encrypted message: %s\n", message);
}

int main()
{
    encrypt();
    decrypt();
    return 0;
}

