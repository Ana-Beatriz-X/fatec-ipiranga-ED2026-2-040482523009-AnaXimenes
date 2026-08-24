/* 
* Programa para controlar o estoque de uma quantidade fixa de
* produtos em seu depósito central. Periodicamente, a loja recebe um lote de reposição, que deve ser
* somado à quantidade em estoque de todos os produtos. Ao final do processo, a loja também deseja
* saber quais produtos permanecem em nível crítico de estoque (abaixo de uma quantidade mínima
* de segurança).
*
* Autor: Ana Beatriz Ximenes Amaral
*
* Data: 24/08/2026
*
* Versão: 1.0
*/

#include <stdio.h>

#define TAMANHO_ESTOQUE 5 // define a variedade de produtos no estoque
#define ESTOQUE_MINIMO 10 // define a quantidade minima de cada produto do estoquee

int estoque[TAMANHO_ESTOQUE]; //declaranddo a variavel estoque que tem como tamanha do vetor a variavel global "TAMANHO_ESTOQUE" 

void exibirCabecalho(void) { //cabeçalho: nome da institição e titulo do programa
	printf("================================         \n");
	printf("SISTEMA DE ESTOQUE - LOJA CONSTRUMAIS    \n");
	printf("================================         \n");
}

void preencherEstoque(void) { // função que preenche o estoque 
	 
	int *p = estoque; // pega o valor armazenado em estoque
	
     for(int i = 0; i < TAMANHO_ESTOQUE; i++){ // looping que percorre todo o tamanho do estoque
         printf("Quantidade do produto %d: ", i + 1); 
         scanf("%d", p + i); // pego o enderço de p + i
	     
	 }
}	 
	 
void exibirEstoque(int momento){// funcao para exibir o estoque de acordo com status dele, 0 estoque antes, 1 estoque apos  
    
    if(momento == 0){
        printf("\n-- Estoque atual (antes da reposicao) --\n");
    }
    else if(momento == 1){
        printf("\n-- Estoque final (apos reposicao) --\n");
    }
    
    int *p = estoque;
    
    for(int i = 0; i < TAMANHO_ESTOQUE; i++){ 
        printf("Produto %d: %d unidades\n", i + 1, *(p + i)); // printa o numero do produto e sua quantidade em estoque(de acordo com ostatus que foi solicitado)
        
    }
}

float calcularMediaEstoque(void){ // calcula a media de todos os produtos no estoque 
    int *p = estoque; 
    float soma = 0.0;
    
    /*
    * EXPLICAÇÃO: Diferença entre: *(P + I) e (P + I):
    *
    * *(P + I) - Pega o valor armazenado no endereço de memoria i, ou seja estoque[i]
    * (P + I) - Calcula o endereço de memoria de i, ou seja &estoque[i]
    */
    
    for(int i = 0; i < TAMANHO_ESTOQUE; i ++){
        
        soma = soma + *(p + i); // acessa o valor armazenado em p+i e acumula em "soma"
    }
    
    float media = soma / TAMANHO_ESTOQUE;
    
    return media;
}

void simularReposicao(int quantidadeAtual, int reposicao){ // função que simula a reposição do estoque mas não muda efetivamente o estoque
    printf("\n-- Simulacao de reposicao (passagem por valor) --\n");
    printf("Simulacao para o produto 1: %d + %d = %d (nao aplicado ainda)\n", quantidadeAtual, reposicao, quantidadeAtual + reposicao);
    printf("Quantidade do produto 1 apos a simulacao (inalterada): %d\n", quantidadeAtual);
}

void aplicarReposicaoGeral(int reposicao){ // Aplica a reposição efetivamente
     int *p = estoque;
     
     printf("\n-- Aplicacao real da reposicao (ponteiro interno ao vetor global) --\n");
     for(int i = 0; i < TAMANHO_ESTOQUE; i++){  
         *(p + i) += reposicao; // acessa o valor armazenado em p+i e soma com o valor reposicao
     }
     
     printf("Reposicao de %d unidades aplicada a todos os produtos do estoque.\n", reposicao);
}

void identificarEstoqueCritico(int minimo){ // funcao que identifica se o produto esta abaixo do estoque minimo 
    int *p = estoque; 
    int produtosCriticos = 0; // contador de produtos em situação critica (abaixo do estoque minimo)
    
    printf("\n-- Analise de estoque critico (minimo = %d unidades) --\n",minimo);
    
    for(int i = 0; i < TAMANHO_ESTOQUE; i++){
        if(*(p + i) < minimo){ // condição para quando o valor armazenado em p+i for menor que o valor minimo do estoque 
            printf("Produto %d esta em nivel critico: %d unidades (abaixo do minimo)\n", i + 1, *(p + i));
            produtosCriticos ++; // adiciona +1 ao contador para cada passagem do loop que a condição (*(p + i) < minimo) do if for verdadeira
        }
    }
    
        if(produtosCriticos == 0){ //condição para casos o contador estiver zerado ou seja a condiçao (*(p + i) < minimo) nao se aplicou a nenhum produto 
            printf("Estoque regularizado.\n");
        }
}

int main(){
    int reposicao;
    
    exibirCabecalho();
    preencherEstoque();
    
    printf("Quantidade de reposicao a aplicar: ");
    scanf("%d", &reposicao);
    
    exibirEstoque(0);
    
    simularReposicao(*estoque, reposicao);
    
    aplicarReposicaoGeral(reposicao);
    
    exibirEstoque(1);
    
    printf("\n-- Media geral do estoque --\n");
    printf("Media final: %.2f unidades\n", calcularMediaEstoque());
    
    identificarEstoqueCritico(ESTOQUE_MINIMO);
    
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
