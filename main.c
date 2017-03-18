#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 3

void write(float a[][col]);
void read (float a[][col]);
void sum_matrix (float a[][col],float b[][col]);
void man_matrix (float a[][col],float b[][col]);
void mul_matrix(float a[][col],float b[][col]);
void sowp (float *a,float *b);
void Trans_matrix (float a[][col]);
int det_matrix(float a[][col]);
void Inv_matrix (float a[][col]);
void solution();
int main()
{
    printf("============================================================\n");
    printf("||Press 1-> for the collection of two matrix :)           ||\n");
    printf("||Press 2-> for mince of two Matrix :)                    ||\n");
    printf("||Press 3-> for hitting two Matrices :)                   ||\n");
    printf("||Press 4-> for finding Transpose Matrix :)               ||\n");
    printf("||press 5-> for finding Determinant of Matrix :)          ||\n");
    printf("||press 6-> for finding INVERSE matrix  :)                ||\n");
    printf("||press 7-> to solution of 3 equations with 3 unknowns :) ||\n");
    printf("************************************************************\n");
    int ch;
    while(ch)
    {
        printf("please->enter your choice:)\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            float a[3][3],b[3][3];
            printf("please->Enter the first matrix:)\n");
            write(a);
            printf("please->Enter the second matrix:)\n");
            write(b);
            printf("\\nThe matrix resulting from the collection of matrices\n");
            sum_matrix(a,b);
        }
        break;
        case 2:
        {
            float c[3][3],d[3][3];
            printf("please->Enter the first matrix:)\n");
            write(c);
            printf("please->Enter the second matrix:)\n");
            write(d);
            printf("\nThe matrix resulting from the mince of matrices\n");
            man_matrix(c,d);
        }
        break;
        case 3:
        {
            float E[3][3],F[3][3];
            printf("please->Enter the first matrix:)\n");
            write(E);
            printf("please->Enter the second matrix:)\n");
            write(F);
            printf("\nThe matrix resulting from the hitting of matrices\n");
            mul_matrix(E,F);
        }
        break;
        case 4:
        {
            float arr[3][3];
            printf("please->enter the matrix\n");
            write(arr);
            printf("\nthe matrix is\n");
            read(arr);
            printf("\nthe transpose of matrix is\n");
            Trans_matrix(arr);
            read(arr);
        }
        break;
        case 5:
        {
            float arr1[3][3];
            printf("Please->Enter The MATRIX\n");
            write(arr1);
            printf("\nThe MATRIX is\n");
            read(arr1);
            int d=0;
            d=det_matrix(arr1);
            printf("The Determinant of matrix ==(%d)\n",d);
        }
        break;
        case 6:
        {
            float arr2[3][3];
            printf("Please->Enter The Matrix\n");
            write(arr2);
            printf("\nTHE MATRIX IS :\n");
            read(arr2);
            Inv_matrix(arr2);
        }
        break;
        case 7:
        {
            solution();
        }
        break;
        case 0:
            break;
        default :
            printf("Error\n");
        }
    }
    return 0;
}
void write(float a[][col])
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    return;
}
void read (float a[][col])
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }
    return;
}
void sum_matrix (float a[][col],float b[][col])
{
    int i,j;
    float c[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    read(c);
}
void man_matrix (float a[][col],float b[][col])
{
    int i,j;
    float c[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    read(c);
}
void mul_matrix(float a[][col],float b[][col])
{
    int i,j,k;
    float c[row][col]={0.0};
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            for(k=0; k<3; k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
    }
    read(c);
}
void sowp (float *a,float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}
void Trans_matrix (float a[][col])
{
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=i+1; j<3; j++)
        {
            sowp(&a[i][j],&a[j][i]);
        }
    }
}
int det_matrix(float a[][col])
{
    int i;
    int d=0;
    for(i=0; i<3; i++)
    {

        d=d+(a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]));
    }
    return d;
}
void Inv_matrix (float a[][col])
{
    float A[3][3];
    int i,j;
    int g=det_matrix(a);
    printf("The Determinant of matrix ==(%d)\n",g);
    if (g==0)
    {
        printf("\nCould not find an Inverse\n");
        return;
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            A[i][j]=((a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3])-(a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]));
        }
    }
    Trans_matrix(A);
    printf("\nthe adj Matrix is\n");
    read(A);
    printf("\nA^-1= 1/det(A) * adj(A)\n");
    printf("\nA^-1=\n\n");
    printf("1/(%d)* ",g);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("|%.2f\t",A[i][j]);
        }
        printf("|\n\t");
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            A[i][j]=A[i][j]/g;
    }
    printf("\nThe INVERSE OF MATRIX IS: \n\n");
    read(A);
}
void solution()
{
    int i,j;
    float a[3][3],c[3],A[3][3],INV[3][3],X[3],det=0.0;
    for(i=0; i<3; i++)
    {
        printf("Enter The X,Y,Z,C-> Efficients and constants of the equation(%d)\n",i+1);
        scanf("%f%f%f%f",&a[i][0],&a[i][1],&a[i][2],&c[i]);
    }
    printf("\nThe Equations Are:\n");
    for(i=0; i<3; i++)
    {
        printf("(%.2f)X + (%.2f)Y + (%.2f)Z = %.2f\n",a[i][0],a[i][1],a[i][2],c[i]);
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            A[i][j]=(a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3])-
                    (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]);
        }
    }
    for(i=0; i<3; i++)
    {
        det+=a[i][0]*A[i][0];
    }
    printf("\n\n");
    if (det==0)
    {
        printf("Equations entered an impossible solution\n");
        return;
    }
    for(i=0; i<2; i++)
    {
        for(j=i+1; j<3; j++)
        {
            sowp(&A[i][j],&A[j][i]);
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            INV[i][j]=A[i][j]/det;
    }
    for(i=0; i<3; i++)
    {
        X[i]=0.0;
        for(j=0; j<3; j++)
        {
            X[i]+=INV[i][j]*c[j];
        }
    }
    printf("Solution of The Equations");
    printf("\n\tX=%.2f\n\tY=%.2f\n\tZ=%.2f\n",X[0],X[1],X[2]);
    return;
}
