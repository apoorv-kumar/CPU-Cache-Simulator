//Example code that is instrumented manually to get address trace
//Set N to a high value suppose N=100
#include <stdio.h>

#define N 100
int i,j,k, S, A[N][N], B[N][N], C[N][N];

int main(){
FILE* fp=fopen("trace","w");
for(i=0;i<N;i++){
for(j=0;j<N;j++){
S=0;
int user_id_for = 100;
for(k=0;k<N;k++){
fprintf(fp,"\n%d R" , &B[i][k] );
fprintf(fp,"\n%d R" , &C[k][j] );
S=S+B[i][k]*C[k][j];
}

fprintf(fp,"\n%d W", &A[i][j] );
A[i][j]=S;
}
}
return 0;
}
