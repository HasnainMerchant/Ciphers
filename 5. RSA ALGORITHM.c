#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

long int p,q,n,phi_n,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
char msg[100];
int prime(long int);
void calculate_e();
long int calculate_d(long int);
void encrypt();
void decrypt();

void main() {
    //Enter Value Of 'p'
	printf("\nEnter First Prime Number : \n");
	scanf("%d",&p);
	flag = prime(p);
	if(flag == 0)
    {
        printf("This Is Not A Prime Number !");
        getch();
        exit(1);
    }
    //Enter value of 'q'
	printf("\nEnter Another Prime Number ! \n");
	scanf("%d",&q);
	flag = prime(q);
	if(flag == 0)
    {
        printf("This Is Not A Prime Number !");
        getch();
        exit(1);
    }
	//Enter Plain-Text
	printf("\nEnter Plain-Text Message : \n");
	scanf("%s",msg);
	//Store the message in array
	for (i = 0; msg[i]!= NULL; i++)
        m[i] = msg[i];
    //Calculate value of n = p * q;
	n = p * q;
	//phi(n) = phi(p) * phi(q) = (p-1) * (q-1)
	phi_n = (p-1) * (q-1);
	printf("\nThe Value Of n = %ld\n",n);
	printf("The Value Of Phi(n) = %ld\n",phi_n);
	//Calculating value of e and d
	calculate_e();

	printf("\nPossible Values Of e and d Are : \n");
	for (i = 0; i < j-1; i++)
        printf("\ne = %ld\td = %ld",e[i],d[i]);
	encrypt();
	decrypt();
	getch();
}
//Function to check if number is prime or not
int prime(long int pr) {
	int i;
	j = sqrt(pr);
	for (i=2;i<=j;i++) {
		if(pr%i==0)
		    return 0;
	}
	return 1;
}

void calculate_e() {
	int k;
	k=0;
	//Calculating Possible values Of e
	for (i=2;i<phi_n;i++) //Because 1 < e < phi(n)
    {
		if(phi_n % i == 0)
		    continue;
		flag=prime(i);
		if(flag == 1 && i != p && i != q) {
			e[k] = i;
			flag = calculate_d(e[k]);//Calculating Value of d from e because e*d mod(phi(n)) = 1
			if(flag>0) {
				d[k] = flag;
				k++;
			}
			if(k == 99)
			        break;
		}
	}
}

long int calculate_d(long int x) {
	long int k=1;
	//Calculating value of 'd' wrt to e
	//Because e*d mod(phi(n)) = 1
	while(1) {
		k = k + phi_n;
		if(k % x == 0)
		    return(k/x);
	}
}

void encrypt() {
	long int pt,ct,key=e[0],k,len;
	i=0;
	len=strlen(msg);
	while(i!=len) {
		pt = m[i];
		if(pt >= 'a' && pt <='z')
            pt = pt - 97;
        else
            pt = pt - 65;
		k=1;
		for (j=0;j<key;j++) {
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		if(k + 97 >= 'a' && k + 97 <='z')
            ct = k + 97;
        else
            ct = k + 65;
		en[i] = ct;
		i++;
	}
	en[i]=-1;
	printf("\nThe ENCRYPTED Message Is : \n");
	for (i = 0;en[i] != -1;i++)
        printf("%c",en[i]);
}

void decrypt() {
	long int pt,ct,key=d[0],k;
	i=0;
	while(en[i]!=-1) {
		ct = temp[i];
		k=1;
		for (j=0;j<key;j++) {
			k=k*ct;
			k=k%n;
		}
		if(k + 97 >= 'a' && k + 97 <= 'z')
            pt = k + 97;
        else
            pt = k + 65;
		m[i] = pt;
		i++;
	}
	m[i]=-1;
	printf("\nThe DECRYPTED Message Is : \n");
	for (i=0;m[i]!=-1;i++)
        printf("%c",m[i]);
}
