#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char* plaintxt,int key,char* ciphertxt){
    int i=0;
    for(i=0;plaintxt[i]!='\0' && plaintxt[i]!='\n';i++){
        if (isalpha(plaintxt[i])){
            char base=isupper(plaintxt[i]) ? 'A':'a';
            int index=(plaintxt[i]-base+key)%26;
            ciphertxt[i]=base+index;
        }
        else if (isdigit(plaintxt[i])){
            char base='0';
            int index=(plaintxt[i]-base+key+10)%10;
            ciphertxt[i]=base+index;
        }
        else{
            //printf("Invalid character.");
            ciphertxt[i]=plaintxt[i];
        }
    }
    ciphertxt[i]='\0';
}
void decrypt(char* ciphertxt,int key,char* decodedtxt){
    int i=0;
    for(i=0;ciphertxt[i]!='\0' && ciphertxt[i]!='\n';i++){
        if (isalpha(ciphertxt[i])){
            char base=isupper(ciphertxt[i]) ? 'A':'a';
            int index=(ciphertxt[i]-base-key+26)%26;
            decodedtxt[i]=base+index;
        }
        else if (isdigit(ciphertxt[i])){
            char base='0';
            int index=(ciphertxt[i]-base-key+10)%10;
            decodedtxt[i]=base+index;
        }
        else{
            //printf("Invalid character.");
            decodedtxt[i]=ciphertxt[i];
        }
    }
    decodedtxt[i]='\0';
}
void main(){
    char plaintxt[100],ciphertxt[100],decodedtxt[100];
    int key;
    printf("Enter key:");
    scanf("%d",&key);
    getchar();
    printf("\nEnter plaintext:");
    fgets(plaintxt,sizeof(plaintxt),stdin);
    encrypt(plaintxt,key,ciphertxt);
    printf("\nCiphertext is:%s",ciphertxt);
    decrypt(ciphertxt,key,decodedtxt);
    printf("\nDecoded text is:%s",plaintxt);
}