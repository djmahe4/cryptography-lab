#include<stdio.h>
#include<math.h>
void printMat(float mat[3][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.0f",mat[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}
float detSub(float mat[3][3],int mi, int mj){
    int indi=0, indj=0;
    float new[2][2];
    for(int i=0;i<3;i++){
        if (i==mi) continue;
        indj=0;
        for(int j=0;j<3;j++){
            if (j==mj) continue;
            new[indi][indj]=mat[i][j];
            indj++;
        }
        indi++;
    }
    return new[0][0]*new[1][1]-new[1][0]*new[0][1];
}
int main(){
    int n;
    printf("Enter order of the matrix:");
    scanf("%d",&n);
    if(n!=2 && n!=3){
        printf("Invalid order.");
        return 1;
    }
    printf("\nEnter matrix:");
    float mat[3][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%f",&mat[i][j]);
    }
    if (n==2){
        float det=mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
        float cofact[3][3];
        cofact[0][0]=mat[1][1];
        cofact[1][1]=mat[0][0];
        cofact[1][0]=-mat[0][1];
        cofact[0][1]=-mat[1][0];
        printf("\nCofactor matrix is\n");
        printMat(cofact,n);
        if (det==0) return 1;
        float adj[3][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) adj[i][j]=cofact[j][i];
        }
        printf("\nAdjoint matrix is\n");
        printMat(adj,n);
        float inv[3][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) inv[i][j]=adj[i][j]/det;
        }
        printf("\nInverse Matrix is:\n");
        printMat(inv,n);
        return 0;
    }
    else{
        float det=mat[0][0]*(mat[2][2]*mat[1][1]-mat[1][2]*mat[2][1])-      
                mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])+
                mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
        float cofact[3][3];
        // Correct calculation for the 3x3 Cofactor matrix (C[i][j])
        // Note: This assumes the detSub function correctly computes the 2x2 minor determinant.

        cofact[0][0] = +detSub(mat, 0, 0); // i=0, j=0, sign is +
        cofact[0][1] = -detSub(mat, 0, 1); // i=0, j=1, sign is -
        cofact[0][2] = +detSub(mat, 0, 2); // i=0, j=2, sign is +

        cofact[1][0] = -detSub(mat, 1, 0); // i=1, j=0, sign is -
        cofact[1][1] = +detSub(mat, 1, 1); // i=1, j=1, sign is +
        cofact[1][2] = -detSub(mat, 1, 2); // i=1, j=2, sign is -

        cofact[2][0] = +detSub(mat, 2, 0); // i=2, j=0, sign is +
        cofact[2][1] = -detSub(mat, 2, 1); // i=2, j=1, sign is -
        cofact[2][2] = +detSub(mat, 2, 2); // i=2, j=2, sign is +
        printf("\nCofactor matrix is\n");
        printMat(cofact,n);
        if (det==0) return 1;
        float adj[3][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) adj[i][j]=cofact[j][i];
        }
        printf("\nAdjoint matrix is\n");
        printMat(adj,n);
        float inv[3][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) inv[i][j]=adj[i][j]/det;
        }
        printf("\nInverse Matrix is:\n");
        printMat(inv,n);
        return 0;
    }
}
