//  +-----------------------------------------------------------------+
//  | Árvore Binária de Busca - 2020.2 - Árvore em nível. Welington.  |
//  +-----------------------------------------------------------------+

#include<iostream>
#include<cstdlib> //only on windowns, don't work at linux
#include<queue>
using namespace std;

//------------[DEFINIÇÃO STRUCT ÁRVORE]--------------------------------

struct NoArvore
{
    int Info;
    NoArvore *esq;
    NoArvore *dir;
};
typedef NoArvore* Arvore;

//-----------------[PROTÓTIPOS]----------------------------------------

void mostra (Arvore& a, int n);
void insereAbbRec(Arvore& A, int Info);
void emnivel(Arvore& A);
void insere(Arvore& A);

//--------------------[MAIN]-------------------------------------------

int main(){

    setlocale(LC_ALL, "Portuguese");

    Arvore A = NULL;
   
    insere(A);
  
    if(A != NULL){
        cout<<"EXIBINDO ÁRVORE:\n\n";
        mostra(A, 0);
    }

    if(A != NULL)
        emnivel(A);

    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}

//--------------[FUNÇÕES ÁRVORE]--------------------------------------

void mostra (Arvore& a, int n) {
    if (a) {
        int i;
        mostra (a->dir, n+1);

        for (i = 0; i < n; i++) cout << "    ";
            cout << a->Info << endl;

        mostra (a->esq, n+1);
    }
}

void insereAbbRec (Arvore& A, int Info){        //FUNÇÃO INSERE DO SANDRO
    if(A == NULL){                              //SE O PONTEIRO A FOR NULO, INSERIR UM NOVO NÓ
         A = new NoArvore;
         A->Info = Info;
         A->esq = A->dir = NULL;
    }

    else if(Info > A->Info)
            insereAbbRec(A->dir, Info);         //INSERINDO NoArvore RAMO DIREITO

        else
            insereAbbRec(A->esq, Info);         //INSERINDO NoArvore RAMO ESQUERDO
}

void emnivel(Arvore& A){

    queue<Arvore> fila;

    cout<<"\nELEMENTOS EM NIVEL: ";

    fila.push(A);                               //INSERINDO NÓ RAIZ NA FILA

    while(!fila.empty()){                       //ENQUANTO A FILA NÃO ESTIVER VAZIA

        Arvore SubArvore = fila.front();        //SUBÁRVORE RECEBE O 1º ELEMENTO DA FILA
        cout<<SubArvore->Info<<" ";             //EXIBINDO A INFORMAÇÃO DO NÓ RAIZ DA SUBÁRVORE

        fila.pop();                             //REMOVENDO O 1º ELEMENTO DA FILA

        if(SubArvore->esq != NULL)              //CASO O PONTEIRO DA ESQUERDA SEJA VÁLIDO,
            fila.push(SubArvore->esq);          //ENFILEIRA SUBÁRVORE DA ESQUERDA

        if(SubArvore->dir != NULL)              //CASO O PONTEIRO DA DIREITA SEJA VÁLIDO,
            fila.push(SubArvore->dir);          //ENFILEIRA SUBÁRVORE DA DIREITA
    }
}

void insere(Arvore& A)
{
    int x = 0;
    while (1) {
    cout<<"Insira um valor x: ";
    cin>>x;
    if (x == -1)
    break;
    insereAbbRec(A, x); 
    }
}
    

