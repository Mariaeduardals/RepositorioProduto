		
		typedef struct repositorio Repositorio;
		
		typedef struct produto Produto;
		
		int add(Repositorio* r, Produto* p);
		int mostrar(Repositorio* r);
		void tratar(Repositorio* r);
		int pesqCodigo(Repositorio* r,int codigo);
		int pesqValor(Repositorio* r, float valor);
		void tamanho(Repositorio* r);
		int estaCheio(Repositorio* r);
		int estaVazio(Repositorio* r);
		void clear(Repositorio* r);
		Produto *novoProduto(int codigo, float valor);
		
		

