#include <stdio.h>
#include <stdlib.h>
#include "Repositorio.h"

int main() {

		int n = 10;
		Repositorio* r = novoRepositorio(n);
		
		add(r, novoProduto(11, 55.6));
		add(r, novoProduto(31, 59.90));
		add(r, novoProduto(14, 17.55));
		add(r, novoProduto(26, 20.99));
		add(r, novoProduto(10, 99.90));
		add(r, novoProduto(20, 155.70));
		add(r, novoProduto(29, 43.89));
		add(r, novoProduto(36, 49.99));
		
		mostrar(r);
		
		tamanho(r);
		
		tratar(r);
		
		mostrar(r);
		
		tamanho(r);
		
		int i = pesqCodigo(r, 36);
		printf("\nRecebe um codigo de compra i e retorna a posicao da compra: %d \n",i);
		
		int f = pesqValor(r, 99.90);
		printf("\nRecebe um valor de compra v e retorna a posicao da compra: %d \n", f);
		
		printf("\nRetorna verdadeiro se o repositorio esta cheio e falso para o caso oposto : %d\n",estaCheio(r));
		printf("\nRetorna verdadeiro se o repositorio esta vazio e falso para o caso oposto: %d \n",estaVazio(r));
		
		clear(r);
		
	return 0;
}
