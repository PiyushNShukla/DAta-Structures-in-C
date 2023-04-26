#include <stdio.h>
#include <stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s){
    printf("Enter the dimensions ");
    scanf("%d%d",&s->m, &s->n );
    printf("Number of non-zero elements");
    scanf("%d",&s->num);
    s-> ele= (struct Element*) malloc(s->num * sizeof(struct Element));
    printf("Enter all non-zero elements\n");
    for (int i = 0; i< s->num; i++)
    {
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}
void display(struct Sparse s){
    int i,j,k=0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            for (k = 0; k < s.num; k++) {
        if (i == s.ele[k].i && j == s.ele[k].j) {
             printf("%d ", s.ele[k].x);
             break;
        }
    }

    // not found among the sparse elements
    if (k == s.num) {
        printf("0 ");
    }
        }
        printf(" \n");
    }
}
void createTranspose(struct Sparse *t, struct Sparse s){
    t->m = s.n;
    t->n = s.m;
    t->num = s.num;
    t-> ele= (struct Element*) malloc(t->num * sizeof(struct Element));
    printf("Enter all non-zero elements\n");
    for (int i = 0; i< t->num; i++)
    {
        t->ele[i].i= s.ele[i].j;
        t->ele[i].j= s.ele[i].i;
        t->ele[i].x= s.ele[i].x;
    }
}

int main(){
    struct Sparse s, t;
    create(&s);
    display(s);
    createTranspose(&t,s);
    printf("Transpose of the matrix is \n");
    display(t);
    return 0;
}