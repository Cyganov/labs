#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "instr.h"

int main(){
    void *func[12]={enter_int, write_int, sum_int, scal_mul_int, enter_float, write_float, sum_float, scal_mul_float, enter_complex, write_complex, sum_complex, scal_mul_complex,};
    vector v1, v2, v3;
    int size, k, Mi=0;
    float Mf=0;
    complex Mc={0,0};
    printf("Hello, user! What are you want to do? Enter number:\n1-to do tests, 2-to work with vectors:\n");
    scanf("%d", &k);
    if (k==1){
    test1();
    test2();}
    else  {
        printf("The number of what type will contain vectors?\n");
        printf("Enter 0 if the integer. Enter 1 if real. Enter 2 if complex.\n");
        scanf("%d",&k);
        if (k==0)
            size=sizeof(int);
            else
            if ((k==1)||(k==2))
                size=sizeof(float);
        else
            {  printf("ERORR 404! You entered does not exist the type of the variables!");
            exit(0);}
        enter(&v1,func[4*k],size);
        write(&v1,func[4*k+1],size);
        enter(&v2,func[4*k],size);
        write(&v2,func[4*k+1],size);
        sum(&v1,&v2,&v3,size,func[4*k+2]);
        write(&v3,func[4*k+1],size);
        if (k==0)
            {scal_mul(&v1,&v2,scal_mul_int, &Mi);
            printf("%d", Mi);}
        else
            if (k==1)
            {scal_mul(&v1,&v2,scal_mul_float, &Mf);
        printf("%f", Mf);}
            else
                {scal_mul(&v1,&v2,scal_mul_complex, &Mc);
                printf("%f + %f i", Mc);}
            free(v1.data);
            free(v2.data);
            free(v3.data);
}
    return 0;
}
