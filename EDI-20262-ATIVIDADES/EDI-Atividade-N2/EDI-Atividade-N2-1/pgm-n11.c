/*
 *Programa feito para lançar as notas de uma turma de tamanho fixo, aplicar um bônus de
 *participação a todos os alunos e analisar a média da turma antes e depois do ajuste.
 *
 * Data: 17/08/2026
 * Autor: Ana Beatriz Ximenes
 * Versão: 1.0
 */

#include <stdio.h>

#define TAMANHO_TURMA 5 // define a quantidade de alunos na turma

void exibirCabecalho(void) { //cabeçalho: nome da institição e titulo do programa
	printf("================================\n");
	printf("  SISTEMA DE NOTAS - TURMA ADS  \n");
	printf("================================\n");
}

float calcularMedia(float vetor[], int tamanho) { // Para deixar o codigo mais eficiente, quando declaramos um vetor apenas com "[]" ele não copia o valor inteiro, ele acessa o endereço de memoria do primeiro item do vetor,funcionando como passagem por referencia
	float soma = 0;

	for(int i = 0; i < tamanho; i++) {
		soma = soma + vetor[i];

	}

	float media = soma / tamanho;
	return media;
}

void simularAjuste(float notaOriginal, float bonus) { // Simulação de adição de bonus, pegando a primeira nota do vetor e adicionando o bonus, sem fazer mudanças ao valor original

	notaOriginal = notaOriginal + bonus;
	printf("%.2f", notaOriginal);

}

void aplicarBonus(float *nota, float bonus) { // Aplica o bonus utilizando apontamento no endereço de memoria da variavel "nota"
	*nota = *nota + bonus;

}
int main() {

	exibirCabecalho();

	float notas[TAMANHO_TURMA], bonus;

	for(int i = 0; i < TAMANHO_TURMA; i ++) { // laço "for" que percorre todo vetor e preenche com as notas dos alunos

		printf("Nota do aluno %d: ", i+1);
		scanf("%f", &notas[i]);
	}
	
	printf("Informe o valor do bonus a aplicar: ");
	scanf("%f", &bonus);

	printf("\n--- Media da turma antes do ajuste ---\n");
	printf("Media inicial: %.2f\n",calcularMedia(notas, TAMANHO_TURMA));

	printf("\n--- Simulacao do ajuste (passagem por valor) ---");
	printf("\nSimulacao para o aluno 1: %.2f + %.2f = ", notas[0], bonus);
	simularAjuste(notas[0],bonus);
	printf(" (nao aplicado ainda)");
	printf("\nNota do aluno 1 apos a simulacao (inalterada): %.2f", notas[0]);


	for(int i = 0; i < TAMANHO_TURMA; i ++) { //laço "for" que aplica o bonus em todas as notas
		aplicarBonus(&notas[i],bonus);
	}

	printf("\n\n--- Aplicacao real do bonus (passagem por referencia) ---");
	printf("\nBonus de %.2f aplicado a todas as notas da turma.", bonus);


	printf("\n\n--- Notas finais da turma ---\n");

	for (int i = 0; i < TAMANHO_TURMA; i++) {// laço "for" de repetição que printa as notas com os ajustes feitos de acordo com a função Aplicarbonus
		printf("Aluno %d: %.2f\n", i+1, notas[i]);
	}


	printf("\n--- Media da turma apos o ajuste ---\n");
	printf("Media final: %.2f\n",calcularMedia(notas, TAMANHO_TURMA));


	return 0;

}//fim da main