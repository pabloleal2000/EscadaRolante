//Pablo Borba Leal, Tia:42145333.
#include <stdio.h>

#define N 10000

//estados da escada
#define PARADA 0
//andando pra esquerda
#define ESQ 1
//andando pra direita
#define DIR 2

//l eh o primeiro da fila
//r eh o ultimo da fila
typedef struct fila {
    int l, r;
    int f[N+1];
} fila;

int tam(fila *f) {
    return f->r - f->l;
}

//insere no fim
void push(fila *f, int a) {
    f->f[f->r] = a;
    f->r++;
}

//retira do inicio
int pop(fila *f) {
    int a = f->f[f->l];
    f->l++;
    return a;
}

//retorna primeiro da fila
int front(fila *f) {
    if (tam(f) == 0) return 0x3f3f3f3f;
    return f->f[f->l];
}

int main (){
    int n;
    scanf("%d", &n);
    fila f_esq, f_dir;
    //iniciando fila vazia
    f_esq.l = f_esq.r = f_dir.l = f_dir.r = 0;
    for (int i = 0; i < n; ++i) {
        int t, d;
        scanf("%d%d", &t, &d);
        //se d == 0 a fila eh da esquerda
        if (d == 0) {
            push(&f_esq, t);
        }
        else 
            push(&f_dir, t);
    }
    //inicialmente a escada esta parada
    int i = 0, estado = PARADA, t = 0, previsao_parada = 0;
    //enquanto nao processamos todos os eventos
    while (i < n) {
        int e = front(&f_esq), d = front(&f_dir);
        //se estamos no tempo previsto de parada e nao tem ninguem na fila
        //neste momento, a escada para
        if (t == previsao_parada) {
            if (e != t && d != t) estado = PARADA;
        }
        if (estado == PARADA) {
            //se a escada ta parada e quem chegou primeiro eh o da esquerda
            //vamos inserir todo mundo que chegou ate agora na escada
            //e a escada vai pra direita
            if (front(&f_esq) < front(&f_dir) && t >= front(&f_esq)) {
                while (front(&f_esq) <= t) {
                    i++;
                    previsao_parada = t + 10;
                    pop(&f_esq);
                }
                estado = DIR;
            }
            //mesmo caso anterior soh que no sentido contrario
            else if (front(&f_esq) > front(&f_dir) && t >= front(&f_dir)) {
                while (front(&f_dir) <= t) {
                    i++;
                    previsao_parada = t + 10;
                    pop(&f_dir);
                }
                estado = ESQ;
            }
        }
        //se a escada ta indo pra esquerda
        //e alguem chegou na fila da direita, poe na escada e 
        //atualiza a previsao de parada
        else if (estado == ESQ) {
            if (front(&f_dir) == t){
                i++;
                previsao_parada = t + 10;
                pop(&f_dir);
            }
        }
        else {
            if (front(&f_esq) == t){
                i++;
                previsao_parada = t + 10;
                pop(&f_esq);
            }
        }
        t++;
    }
    printf("%d\n", previsao_parada);
    return 0;
}