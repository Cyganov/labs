#ifndef instr_h
#define instr_h

typedef struct{
    void *data;
    int n, size;
}vector;
typedef struct{
    float re;
    float im;
}complex;
void enter(vector *v, void *f(vector*,int), int mass){
    int i;
    v->size=mass;
    printf("Enter the number of coordinates of the vector\n");
    scanf("%d", &(v->n));
    v->data=malloc(v->size * v->n);
    printf("Enter the coordinates of the vector\n");
    for(i=0; i<(*v).n; i++)
        f(v,i);//
    printf("\n%d\n",v->n);
}
void enter_int(vector *v, int i){
        scanf("%d",(int*)v->data+i);
}
void enter_float(vector *v, int i){
        scanf("%f",(float*)v->data+i);
}
void enter_complex(vector *v, int i){
        scanf("%f %f",&(((complex*)v->data+i)->re), &(((complex*)v->data+i)->im));
}
void write(vector *v,void *f(vector*,int),int mass){
    int i;//
    v->size=mass;
    for(i=0; i < v->n; i++)
        f(v,i);
}
void write_int(vector *v, int i){
        printf("%d \n\n", *((int*)v->data + i));
}
void write_float(vector *v, int i){
        printf("%f \n\n",  *((float*)v->data + i));
}
void write_complex(vector *v, int i){
    printf("%f + %f i \n\n",(((complex*)v->data+i)->re) , (((complex*)v->data+i)->im));
}

void sum(vector* v1, vector* v2, vector* v3,int size, void *f(vector*, vector*, vector*,int))
{
     int i;
     if (v1->n != v2->n){
       printf("ERROR!\n");
       exit(0);}
       printf("the sum of vectors is equal to  ");
       v3->n=v1->n;
       v3->data=malloc(size * v3->n);
       for (i = 0;i<v1->n;i++)
               f(v1,v2,v3,i);
}
void sum_int(vector* v1, vector* v2, vector* v3, int i)
{
     *(((int*)v3->data)+i)=*(((int*)v1->data)+i) + *(((int*)v2->data)+i);
}

void sum_float(vector* v1, vector* v2, vector* v3, int i)
{
     *(((float*)v3->data)+i)=*(((float*)v1->data)+i) + *(((float*)v2->data)+i);
}
void sum_complex(vector* v1, vector* v2, vector* v3, int i)
{
    ((complex*)v3->data+i)->re=((complex*)v1->data+i)->re+((complex*)v2->data+i)->re;
    ((complex*)v3->data+i)->im=((complex*)v1->data+i)->im+((complex*)v2->data+i)->im;}

void scal_mul(vector* v1, vector* v2, void *f(vector*, vector*, void*, int), void* M){

 if (v1->n != v2->n){
       printf("ERROR!");
 }else{

       int i;
        printf("the scalar multiplication of vectors is equal to  ");
        for(i=0; i< v1->n; ++i)
          f(v1,v2,M,i);
 }

}
void scal_mul_int(vector* v1, vector* v2, int *M, int i){
    *M += (*((int*)v1->data + i)) * (*((int*)v2->data + i));
}
void scal_mul_float(vector* v1, vector* v2, float *M, int i){
    *M += (*((float*)v1->data + i)) * (*((float*)v2->data + i));
}
void scal_mul_complex(vector* v1, vector* v2, complex *M, int i)
{
    float re1=(((complex*)v1->data+i)->re);
    float im1=(((complex*)v1->data+i)->im);
    float re2=(((complex*)v2->data+i)->re);
    float im2=(((complex*)v2->data+i)->im);
    M->re+=re1*re2 - im1*im2;
    M->im+=re1*im2 + re2*im1;
}


#endif // instr_h
