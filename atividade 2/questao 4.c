#include   <stdio.h>
#include  <stdlib.h>

#define   MAX_SIZE 100

typedef struct  {
    float  dados[MAX_SIZE];
    int  topo;
} Pilha;

void  inicializarPilha ( Pilha * p )  {
    p->topo  =  - 1;
}

int  pilhaVazia ( Pilha * p )   {
    return  p->topo  ==  -1;
}

int pilhaCheia( Pilha *p) {
    return p->topo  ==  MAX_SIZE - 1 ;
}

void empurrar ( Pilha *p ,  float valor )  {
    if ( pilhaCheia (p ) )  {
        printf( "a pilha esta cheia !!\n" ) ;
        return ;
    }
    p -> dados [ ++ p->topo ] = valor ;
}

float remover( Pilha * p )  {
    if ( pilhaVazia(p ) )  {
        printf ( "a pila esta vazia\n" ) ;
        return  - 1;
    }
    return  p -> dados [ p -> topo -- ] ;
}

void copiarPilha( Pilha *origem ,  Pilha *destino ) {
    Pilha  aux;
    inicializarPilha(&aux ) ;
    
    while (! pilhaVazia( origem ) )  {
        empurrar ( & aux , remover( origem ) );
    }
    
    while ( ! pilhaVazia ( &aux ) )  {
        empurrar ( destino ,  remover ( & aux ) );
    }
}

void imprimirPilha (Pilha * p )  {
    if ( pilhaVazia ( p) )   {
        printf ( "a pilha esta vazia \n" ) ;
        return;
    }
    
    printf ( "os elementos da pilha P2 sao:\n" );
    for  ( int i = p -> topo ; i >= 0 ;  i-- )  {
        printf ( "%.2f \n", p->dados[i] ) ;
    }
}

void lerPilha(Pilha *p, int quantidade) {
    float valor;
    for (int i = 0; i < quantidade; i++) {
        printf("digite o valor para a pilha: ");
        scanf("%f", &valor);
        empurrar(p, valor);
    }
}

int  main( )   {
    Pilha  P1 , P2 ;
    int quantidadeP1, quantidadeP2;
    
    inicializarPilha(&P1) ;
    inicializarPilha(&P2 ) ;
    
    printf("digite o numeros para adicionar na pilha P1? ");
    scanf("%d", &quantidadeP1);
    lerPilha(&P1, quantidadeP1);
    
    printf("qdigite o numeros para adicionar na pilha P2? ");
    scanf("%d", &quantidadeP2);
    lerPilha(&P2, quantidadeP2);
    
    printf( "pilha P1 antes de adicionar P2:\n" ) ;
    imprimirPilha ( &P1) ;
    
    printf ( "\npilha P2:\n" ) ;
    imprimirPilha ( &P2) ;
    
    copiarPilha( & P2 , & P1 ) ;
    
    printf ( "\npilha P1 após adicionar P2:\n") ;
    imprimirPilha(&P1) ;
    
    return 0 ;
}