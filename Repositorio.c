		#include <stdio.h>
		#include <stdlib.h>
		#include "Repositorio.h"
		
		
		struct produto{
		float valor;
		int codigo;
		};
		
		struct repositorio{
		Produto **vetor;
		int k;
		int N;
		};
		
		//Utilizei uma lista ordenada com vetor e busca binária.
		
		Repositorio* novoRepositorio(int n){ //1
		
		Repositorio* r = (Repositorio*) malloc(sizeof(struct repositorio)); //1 //1
		r->vetor = (Produto **) malloc(n * sizeof(struct produto)); //1
		r->N = n; //1
		r->k = 0; //1
		
		return r; //1
		
		//Complexidade temporal - O(5) e espacial - O(2) = O(c). Constante.
		}
		
		int posicaoCorreta(Repositorio* r, Produto* p){ //2
		
		int inicio = 0; //1
		int fim = r->k - 1; //1 //1
		
		  while(inicio <= fim){ //enquanto o inicio for menor que o fim, ou seja no pior caso n vezes
		
		   int meio = (inicio + fim) / 2; 
		   
		   if(p->valor < r->vetor[meio]->valor)  //1
		         fim = meio - 1;  //1
		     else
		         inicio = meio + 1; //1
		   }
		//foi utilizado uma busca binária, e por essa busca ir dividindo os valores ao meio reduz o tempo para encontrar o valor
		//facilitando e tornado-a mais rápida, por isso log n.
		
		return inicio; //1
		//Complexidade temporal - O(log n) -> linear. Complexidade espacial - O(4) = O(c). Constante.
		}
		
		
		int add(Repositorio* r, Produto* p){ //2
		
		if(r->k == r->N) return; //1
		
		int pos =  posicaoCorreta(r,p); //1 //1
		
		if(r->vetor[pos] == NULL){ //1
		r->vetor[pos] = p; //1
		r->k = r->k + 1; //1
		}else{
		
		int i = 0; //1
		for(i = r->k; i > pos; i--){ //n
		r->vetor[i] = r->vetor[i - 1]; //1
		}
		
		r->vetor[pos] = p; //1
		r->k = r->k + 1; //1
		}
		   	//Complexidade temporal - O(8 + n) -> linear. Complexidade espacial - O(4) = O(c). Constante.
		}
		
		void tratar(Repositorio* r){ //1
			float maior; //1
			
				maior = r->vetor[r->k-1]->valor; //1
					r->vetor[r->k-1] = NULL; //1
					r->k = r->k -1; //1
			
			printf("\nValor maior %f \n", maior); //1
			
			//Complexidade temporal - O(4) e espacial - O(2) = O(c). Constante.
		}
		
		int pesqCodigo(Repositorio* r, int codigo){ //2
		 
		  int j; //1
		  
		  for(j = 0; j < r->k; j++){ //n
		  	if(r->vetor[j]->codigo == codigo){ //1
		  		return j + 1; //1
			  }
		  }
		  return -1; //1
		//Complexidade temporal - O(3 + n)-> linear. Complexidade espacial - O(3) = O(c). Constante.
		}
		int pesqValor(Repositorio* r, float valor){ //2
			
		  int i = posicaoCorreta(r,novoProduto(0,valor));  //1 //log n
		
		  if(r->vetor[i - 1]->valor == valor ){ //1
		  	return i; //1
		  }else{ 
		  	return -1; //1
 		  }
 		
 		  	//Complexidade temporal -> O (log n). Complexidade espacial - O(3) = O(c). Constante.
		}
		
		void tamanho(Repositorio* r){ //1
			printf("\nTamanho %d \n", r->k); //1
				//Complexidade temporal - O(1) e espacial - O(1) = O(c). Constante.
		}
		
		int mostrar(Repositorio* r){ //1
		int i = 0; //1
		for( i = 0; i < r->k; i++) //n
		    printf("Codigo - %d | Valor produto - %f \n",r->vetor[i]->codigo, r->vetor[i]->valor);//1
		    
			//Complexidade temporal - O(1 + n)-> linear. Complexidade espacial - O(2) = O(c). Constante.
		}
		
		int estaCheio(Repositorio* r){ //1
			if(r->k == r->N){ //1
 				return 1; //1
			}
			return 0; //1
			
			//Complexidade temporal - O(3) e espacial - O(1) = O(c). Constante.
		}
		
		int estaVazio(Repositorio* r){ //1
			if(r->k == 0){ //1
				return 1; //1
			}else{
			return 0; //1
		}
				//Complexidade temporal - O(3) e espacial - O(1) = O(c). Constante.
		}
		
		void clear(Repositorio* r){ //1
		int i; //1
			printf("\nElementos removidos !!"); //1
			for(i = 0; i < r->k; i++){ //n
				if (r->vetor != NULL){ //1
					r->vetor[i] = NULL; //1
					
				}
				}
				r->k = 0; //1
				free(r);//1
				
				
			//Complexidade temporal - O(5 + n) -> linear. Complexidade espacial - O(2) = O(c). Constante.
			}
		
		Produto *novoProduto(int codigo, float valor){ //2
			Produto *p = (Produto*) malloc(sizeof(Produto)); //1 //1
			p->codigo = codigo; //1
			p->valor = valor; //1
			return p; //1
			
			//Complexidade temporal - O(4) e espacial - O(3) = O(c). Constante.
		}
