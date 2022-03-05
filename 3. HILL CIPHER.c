#include<stdio.h>
#include<math.h>
#include<string.h>

float encrypt[2][1], decrypt[2][1], a[2][2], b[2][2], mes[2][1], c[2][2];
int len;

void encryption();
void decryption();
void getKeyMessage();
void inverse();

int main() {
	getKeyMessage();
	encryption();
	decryption();
	return 0;
}

void encryption() {
	int i, j, k;

	for(i = 0; i < 2; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 2; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

	printf("\nEncrypted string is: ");
	for(i = 0; i < 2; i++){
        if(encrypt[i][0] >= 'a' && encrypt[i][0] <= 'z')
            printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
        else
            printf("%c", (char)(fmod(encrypt[i][0], 26) + 65));
	}

}

void decryption() {
	int i, j, k;

	inverse();

	for(i = 0; i < 2; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 2; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

	printf("\nDecrypted string is: ");
	for(i = 0; i < 2; i++){
        if(decrypt[i][0] >= 'a' && decrypt[i][0] <= 'z')
            printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));
        else
            printf("%c", (char)(fmod(decrypt[i][0], 26) + 65));
	}

	printf("\n");
}

void getKeyMessage() {
	int i, j;
	char msg[2];

	printf("Enter 2x2 matrix for the key :\n");

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++) {
			scanf("%f", &a[i][j]);
			c[i][j] = a[i][j];
		}

	printf("\nEnter a 2 Letter string : ");
	scanf("%s", msg);
    len = strlen(msg);
	for(i = 0; i < 2; i++){
        if(msg[i] >= 'a' && msg[i] <='z')
            mes[i][0] = msg[i] - 97;
        else
            mes[i][0] = msg[i] - 65;
	}
}

void inverse() {
	int i, j, k;
	float p, q;

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++) {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}

	for(k = 0; k < 2; k++) {
		for(i = 0; i < 2; i++) {
			p = c[i][k];
			q = c[k][k];

			for(j = 0; j < 2; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			b[i][j] = b[i][j] / c[i][i];
    printf("\n\nOriginal Matrix is:\n");
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++)
			printf("%f ", a[i][j]);

		printf("\n");
	}
    printf("\t\t");

	printf("\n\nInverse Matrix is:\n");
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++)
			printf("%f ", b[i][j]);

		printf("\n");
	}
}
