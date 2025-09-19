#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,k =0;
    char num1[100],num2[100];
    printf("Cuantos digitos tendran los numero?: ");
    scanf("%d",&n);

    int *arr1=(int*)malloc(n*sizeof(int));
    int *arr2=(int*)malloc(n*sizeof(int));
    int *res=(int*)calloc(2*n,sizeof(int));

    if (arr1==NULL||arr2==NULL||res==NULL) {
        printf("No hay memoria");
        return 0;
    }

    printf("Ingrese el primer numero: ");
    scanf("%s",&num1);
    printf("Ingrese el segundo numero: ");
    scanf("%s",&num2);

    for(int i=0;i<n;i++)
    {
        arr1[i]=num1[i]-'0';
        arr2[i]=num2[i]-'0';
    }

    for(int i=n-1;i>=0;i--)
        {
        for(int j=n-1;j>=0;j--)
        {
            int mul=arr1[i]*arr2[j];
            int pos1=i+j;
            int pos2=i+j+1;

            int suma=mul+res[pos2];

            res[pos1]+=suma/10;
            res[pos2]=suma%10;
        }
    }

    while ((k<2*n) && (res[k]==0))
    {
        k++;
    }

    if (k==2*n)
    {
        printf("0");
    }else{
        for(;k<2*n;k++)
        {
            printf("%d", res[k]);
        }
    }
    free(arr1);
    free(arr2);
    free(res);

    return 0;
}
