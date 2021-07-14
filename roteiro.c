#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    FILE *origem;
    FILE *destino;
    long tamanho;

    origem = fopen("musica.mp3", "r");

    char nomeorigem[] = "musica.mb3";
    if (origem != NULL)
    {
        // movimenta a posição corrente de leitura no origem
        // para o seu fim
        fseek(origem, 0, SEEK_END);

        // pega a posição corrente de leitura no origem
        tamanho = ftell(origem);

        // imprime o tamanho do origem
        printf("O origem %s possui %ld bytes\n", nomeorigem, tamanho);
    }
    else
    {
        printf("Origem inexistente\n");
        return 0;
    }
    fclose(origem);

    origem = fopen("musica.mp3", "r");
    destino = fopen("bytes.txt", "w");

    long i;
    int num;
    char carac;
    char final[5] = "final";

    for (i = 0; i <= tamanho; i++)
    {
        num = fgetc(origem);
        carac = num;
        fprintf(destino, "%d\n", num);
    }

    fclose(origem);
    fclose(destino);
    system("python3 script.py");
}
// 4435656