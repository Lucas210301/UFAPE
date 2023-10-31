#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define T 100

/*
    Estrutura de dados de um usuario.
    Uso do typedef para nomear a struct.
*/
typedef struct
{
    int idade;
    char nome[100];
    char sexo;
    char estado_civil;
    int amigos;
    int fotos;
}USUARIOS;

/*
    Funcao para cadastrar usuarios.
    Uso do gets(), pois as entradas sao controladas.
*/
void cadastrar_usuarios(USUARIOS *usuario)
{
    // Idade
    scanf("%d", &usuario->idade);
    getchar();
    
    // Nome
    gets(usuario->nome);
    
    // Sexo
    scanf("%c", &usuario->sexo);
    getchar();
    
    // Estado civil
    scanf("%c", &usuario->estado_civil);
    getchar();
    
    // Numero de amigos
    scanf("%d", &usuario->amigos);
    
    // Numero de fotos
    scanf("%d", &usuario->fotos);
}

/*
    Funcao que imprime os registros de um usuario.
*/
void imprimir_usuario(USUARIOS usuario)
{
    printf("Idade: %d\n", usuario.idade);
    printf("Nome: %s\n", usuario.nome);
    printf("Sexo: %c\n", usuario.sexo);
    printf("Estado Civil: %c\n", usuario.estado_civil);
    printf("Numero de amigos: %d\n", usuario.amigos);
    printf("Numero de fotos: %d\n\n", usuario.fotos);
}

int main() 
{
    /*
        VARIAVEIS
        usuarios : Registros de USUARIOS
        i, n     : Quantidade de usuarios
    */
    USUARIOS usuarios[T];
    int i, n;
    
    // Entrade de 'n'
    scanf("%d", &n);
        
    // Recebendo os registros
    for (i = 0; i < n; ++i)
    {
        cadastrar_usuarios(&usuarios[i]);
        imprimir_usuario(usuarios[i]);
    }
    
    return 0;
}