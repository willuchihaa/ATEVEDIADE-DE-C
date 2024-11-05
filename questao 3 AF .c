#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 40
#define MAX_CELULAR 15

typedef struct Contato {
    char nome[MAX_NOME] ; 
    char celular[MAX_CELULAR] ;
    struct Contato *proximo ; 
} Contato ;

Contato* criar_contato( char nome[], char celular[]) ; 

void inserir_contato ( Contato **agenda , char nome[] , char celular[] ) {
    Contato *novo_contato = criar_contato( nome , celular );

    if ( *agenda == NULL ) {
        *agenda = novo_contato ;
    } else {
        Contato *temp = *agenda ;
        while ( temp->proximo != NULL ) {
            temp = temp->proximo ;
        }
        temp->proximo = novo_contato ;
    }
    printf("O contato %s foi adicionado\n" , nome );
}


Contato* criar_contato( char nome[], char celular[]) { 
    Contato *novo_contato = (Contato*)malloc( sizeof(Contato) ); 
    strcpy( novo_contato->nome , nome );
    strcpy( novo_contato->celular , celular );
    novo_contato->proximo = NULL ;
    return novo_contato ;
}

void listar_contatos ( Contato *agenda ) {
    if ( agenda == NULL ) {
        printf("Agenda esta vazia!\n") ;
        return ;
    }

    Contato *temp = agenda ;
    printf("\n-----Contatos na agenda-----\n");
    while ( temp != NULL ) {
        printf( "Nome: %s, Celular: %s\n" , temp->nome , temp->celular ) ;
        temp = temp->proximo ;
    }
}

void buscar_contato(Contato *agenda, char nome[]) {
    Contato *temp = agenda ;
    while (temp != NULL) {
        if ( strcmp(temp->nome , nome) == 0 ) {
            printf( "Contato encontrado: Nome: %s, Celular: %s\n" , temp->nome , temp->celular );
            return ;
        }
        temp = temp->proximo ;
    }
    printf("O contato %s nao foi encontrado.\n", nome);
}

void remover_contato(Contato **agenda , char nome[] ) {
    Contato *temp = *agenda ;
    Contato *anterior = NULL ;

    while ( temp != NULL && strcmp( temp->nome , nome) != 0 ) {
        anterior = temp ;
        temp = temp->proximo ;
    }

    if ( temp == NULL ) {
        printf("IMpossivel remover, O contato %s nao exite.\n", nome);
        return ;
    }

    if ( anterior == NULL ) {
        *agenda = temp->proximo ;
    } else {
        anterior->proximo = temp->proximo ;
    }

    free( temp ) ;
    printf("Contato %s removido!\n", nome );
}

int main () {
    Contato *agenda = NULL ;
    int opcao ;
    char nome[ MAX_NOME ], celular[ MAX_CELULAR ] ;

    do {
        printf("\n--- Menu ---\n") ;
        printf("1. Inserir Contato\n") ;
        printf("2. Listar Contatos\n") ;
        printf("3. Buscar Contato\n") ;
        printf("4. Remover Contato\n") ;
        printf("5. Sair\n") ;
        printf("Escolha uma opcao: ") ;
        scanf("%d" , &opcao );
        getchar( ) ; 

        switch ( opcao ) {
            case 1:
                printf("digite o nome do contato: ") ;
                fgets(nome, MAX_NOME , stdin );
                nome[strcspn( nome , "\n" )] = '\0' ;
                printf("digite o numero de celular: ") ;
                fgets(celular, MAX_CELULAR , stdin );
                celular[strcspn( celular , "\n" )] = '\0' ;
                inserir_contato( &agenda , nome , celular );
                break ;
            case 2:
                listar_contatos( agenda );
                break ;
            case 3:
                printf("digite o nome do contato para a inciar a busca: ") ;
                fgets(nome, MAX_NOME , stdin );
                nome[strcspn( nome , "\n" )] = '\0' ;
                buscar_contato( agenda , nome );
                break ;
            case 4:
                printf("digite o nome do contato para remover: ") ;
                fgets( nome, MAX_NOME , stdin );
                nome[strcspn( nome , "\n" )] = '\0' ;
                remover_contato( &agenda , nome );
                break ;
            case 5:
                printf("Saindo...\n") ;
                break ;
            default:
                printf("Opcao invalida, Tente novamente.\n");
        }

    } while ( opcao != 5 );

    Contato *temp ;
    while ( agenda != NULL ) {
        temp = agenda ;
        agenda = agenda->proximo ;
        free( temp ) ;
    }

    return 0 ;
}
