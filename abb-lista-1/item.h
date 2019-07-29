//Essas diretivas servem para evitar que um header file seja incluído mais de uma vez
//no mesmo projeto
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

    #include <string.h>
    #include <stdio.h>

    /**
    * Definição de cada aluno
    * A matricula é o atributo identificador
    */
    struct tpAluno {
        char nome[50];
        unsigned int matricula;
    };

    typedef struct tpAluno Item;

    //-----------------------------------------------------------------------------
    /**
     * @param n = nome do aluno até 30 caracteres;
     * @param m = natural indicando a matricula do aluno;
     * @return Um tipo Item preenchido com nome=n e matrícula=m;
     */
    Item setItem( char n[],unsigned int m);

    /**
     * Verifica se um determinado id (matricula)
     * está contido na estrutura item
     * @param (Item item) O item (estrutura) a ser verificado
     * @param (void *id) O id do possível aluno a ser verificado
     * @return (int) Retorna 1 se o id está contido em item ou 0
     * caso contrário
    */
    int isItem(Item *item, void *id);

    /**
     * Verifica se os dois itens possuem mesmo id
     * @return Retorna 1 se tiverem mesmo id ou 0 caso contrário
    */
    int itemCmp(const Item *item1, const Item *item2);

    //-----------------------------------------------------------------------------
    /**
     * Exibe no vídeo os dados de al.
     * @param al = um item com dados de um aluno;
     * @return
     */
    void printItem(Item al);


#endif // ITEM_H_INCLUDED


