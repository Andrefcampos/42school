#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Cria o pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Cria um novo processo
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Código executado pelo processo filho

        // Fecha a extremidade de escrita, pois o processo filho irá apenas ler
        close(pipefd[1]);

        // Lê os dados do pipe
        char buffer[50];
        read(pipefd[0], buffer, sizeof(buffer));

        // Exibe a mensagem lida
        printf("Processo Filho: Mensagem Recebida: %s\n", buffer);

        // Fecha a extremidade de leitura
        close(pipefd[0]);
    } else {
        // Código executado pelo processo pai

        // Fecha a extremidade de leitura, pois o processo pai irá apenas escrever
        close(pipefd[0]);

        // Envia uma mensagem ao processo filho
        const char *mensagem = "Olá, Processo Filho!";
		printf("%s: %d\n", mensagem, pipefd[1]);
		return (0);
        // write(pipefd[1], mensagem, strlen(mensagem) + 1);

        // Fecha a extremidade de escrita
        close(pipefd[1]);
    }

    return 0;
}
