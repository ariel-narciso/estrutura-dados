/********************************************************************
 * Este arquivo implementa um item do tipo Aluno.
 * Nesta implementa��o um aluno possui dois campos: matr�cula e nome.
 * A estrutura de um Aluno est� definida no arquivo Item.h.
 */

#include "item.h"

//-----------------------------------------------------------------------------
/**
 * @param n = nome do aluno at� 30 caracteres;
 * @param m = natural indicando a matricula do aluno;
 * @return Um tipo Item preenchido com nome=n e matr�cula=m;
 */
Item setItem(char n[], unsigned int m){
    Item al;
    strcpy(al.nome, n);
    al.matricula = m;
    return al;
}

int isItem(Item *item, void *id) {

    if (item == NULL || id == NULL || *((unsigned int *)id) != item->matricula)
        return (0);

    return (1);
}

int itemCmp(const Item *item1, const Item *item2) {
	
	if (item1 == NULL || item2 == NULL) {
		return (13);
	}
	
    if (item1->matricula == item2->matricula) {
        return (0);
    }
    
    if (item1->matricula < item2->matricula) {
    	return (-1);
    }

    return (1);
}

//-----------------------------------------------------------------------------
/**
 * Exibe no v�deo os dados de al.
 * @param al = um item com dados de um aluno;
 * @return
 */
void printItem(Item al){
    printf("\n Nome: %s  ",al.nome);
    printf("\n Matricula: %d\n",al.matricula);
}






