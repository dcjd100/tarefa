#include <iostream>

using namespace std;

class elemento
{
private:
	string nome;
	elemento * prox;
public:
	elemento(){
		prox = NULL;
	}
	elemento(string x){
		nome = x;
	}
	string getNome(){
		return nome;
	}
	void setNome(string x){
		nome = x;
	}
	elemento * getProx(){
		return prox;
	}
	void setProx(elemento * item){
		prox = item;
	}
};

class listinha
{
private:
	elemento * comeco;
	
public:
	listinha(){
		comeco = NULL;
	}
	elemento * getComeco(){
		return comeco;
	}
	void inserirComeco(string p){
		elemento *novo = new elemento;
		novo->setNome(p);
		novo->setProx(comeco);
		comeco = novo;
	}
	void inserirFinal(string p){
		elemento *novo = new elemento(p);
		novo->setProx(NULL);
		if(comeco != NULL)
		{			
			elemento *auxiliar = comeco;
			while(auxiliar->getProx() != NULL)
			{
				auxiliar = auxiliar->getProx();
			}
			auxiliar->setProx(novo);
		}
		else{
			comeco = novo;
		}
	}
	
	void mostrar(){
		if(comeco == NULL){
			cout << "Sem nada aqui!\n";
		}
		else{
			elemento *auxiliar = comeco;
			while(auxiliar != NULL){
				cout << auxiliar->getNome() << endl;
				auxiliar = auxiliar->getProx();
			}
		}
	}
};

int main(){
	listinha Clubes;
	
	Clubes.inserirComeco("Cruzeiro");
	Clubes.inserirComeco("Sao Paulo");
	Clubes.inserirFinal("Atletico");
	Clubes.inserirFinal("Gremio");
	Clubes.mostrar();
	return 0;
}