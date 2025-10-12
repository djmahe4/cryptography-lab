#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(char* plain,int mat[2][2],char* cipher){
    int i=0;
    int len = strlen(plain);

    if (len % 2 != 0) {  // pad odd length
        plain[len++] = 'X';
        plain[len] = '\0';
    }
    for(i=0;i<len-2;i+=2){
        char a=isupper(plain[i]) ? 'A':'a';
        char b=isupper(plain[i+1]) ? 'A':'a';
        int aind=plain[i]-a;
        int bind=plain[i+1]-b;
        cipher[i]=((int)(mat[0][0]*aind+mat[0][1]*bind)%26) + a;
        cipher[i+1]=((int)(mat[1][0]*aind+mat[1][1]*bind)%26) + b;
    }
    cipher[i]='\0';
}
void decrypt(char* cipher, int key_mat[2][2], char* decoded){ 
    int i=0;

    for(i=0; i < strlen(cipher); i+=2){ 
        char a = isupper(cipher[i]) ? 'A':'a';
        char b = isupper(cipher[i+1]) ? 'A':'a';
        int aind = cipher[i] - a;
        int bind = cipher[i+1] - b;
        decoded[i] = ((int)(key_mat[0][0] * aind + key_mat[0][1] * bind) % 26) + a;
        decoded[i+1] = ((int)(key_mat[1][0] * aind + key_mat[1][1] * bind) % 26) + b;
    }
    decoded[i]='\0';
}
void main(){
    int inv[2][2]={{15,17},{20,9}};
    int key[2][2]={{3,3},{2,5}};
    char plain[100],cipher[100],decoded[100];
    printf("Enter plaintext:");
    fgets(plain,sizeof(plain),stdin);
    encrypt(plain,key,cipher);
    printf("Encrypted text is:%s",cipher);
    decrypt(cipher,inv,decoded);
    printf("\nDecrypted text is:%s",decoded);

}