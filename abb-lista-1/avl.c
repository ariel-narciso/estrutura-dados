#include "avl.h"

struct tpNo {

    Item item;
    AVL esquerda;
    AVL direita;
};

AVL initAVL(void) {
    return NULL;
}

unsigned int getNosAVL(AVL arv) {

    if (arv == NULL) {
        return 0;
    }

    return 1 + getNosAVL(arv->esquerda) + getNosAVL(arv->direita);
}

unsigned int getAlturaAVL(AVL arv) {

    if (arv == NULL) {
        return -1;
    }

    unsigned int esquerda = getAlturaAVL(arv->esquerda);
    unsigned int direita = getAlturaAVL(arv->direita);

    if (esquerda > direita) {
        return 1 + esquerda;
    }

    return 1 + direita;
}

int getFatorBalanceamento(AVL arv) {
    return getAlturaAVL(arv->esquerda) - getAlturaAVL(arv->direita);
}

AVL rotacaoSimplesDir(AVL arv) {

    if (arv != NULL && arv->esquerda) {

        AVL novaRaiz = arv->esquerda;
        AVL temp = novaRaiz->direita;

        novaRaiz->direita = arv;
        arv->esquerda = temp;

        return novaRaiz;
    }

    return NULL;
}

AVL rotacaoSimplesEsq(AVL arv) {

    if (arv != NULL && arv->direita != NULL) {

        AVL novaRaiz = arv->direita;
        AVL temp = novaRaiz->esquerda;

        novaRaiz->esquerda = arv;
        arv->direita = temp;

        return novaRaiz;
    }

    return NULL;
}

AVL rotacaoDuplaDir(AVL arv) {

    if (arv != NULL) {

        arv->esquerda = rotacaoSimplesEsq(arv->esquerda);
        return rotacaoDuplaDir(arv);
    }

    return NULL;
}

AVL rotacaoDuplaEsq(AVL arv) {

    if (arv != NULL) {

        arv->direita = rotacaoSimplesDir(arv->direita);
        return rotacaoSimplesEsq(arv);
    }

    return NULL;
}

AVL balancearAVL(AVL arv) {

    if (arv != NULL) {

        int fb = getFatorBalanceamento(arv);

        if (fb > 1) {

            if (getFatorBalanceamento(arv->direita) < 0) {
                return rotacaoDuplaDir(arv);
            }

            return rotacaoDuplaDir(arv);
        }

        if (fb < -1) {

            if (getFatorBalanceamento(arv->direita) > 0) {
                return rotacaoDuplaEsq(arv);
            }

            return rotacaoSimplesEsq(arv);
        }
    }

    return arv;
}

AVL insertAVL(Item item, AVL arv) {

    if (arv == NULL) {

        AVL no = (AVL)malloc(sizeof(struct tpNo));

        if (no != NULL) {

            no->item = item;
            no->esquerda = NULL;
            no->direita = NULL;
        }

        return no;
    }

    short compar = itemCmp(&item, &arv->item);

    if (compar == -1) {
        arv->esquerda = insertAVL(item, arv->esquerda);
    } else if (compar == 1) {
        arv->direita = insertAVL(item, arv->direita);
    } else if (compar == 0) {
        arv->item = item;
    }

    return balancearAVL(arv);
}

AVL deleteItemAVL(Item item, AVL arv) {

    if (arv == NULL) {
        return NULL;
    }

    short compar = itemCmp(&item, &arv->item);

    if (compar == -1) {
        return deleteItemAVL(item, arv->esquerda);
    } else if (compar == 1) {
        return deleteItemAVL(item, arv->direita);
    }

    else if (compar == 0) {

        // continua ...
    }
}

void inOrdem(AVL arv) {

    if (arv != NULL) {

        inOrdem(arv->esquerda);
        printItem(arv->item);
        inOrdem(arv->direita);
    }
}

void preOrdem(AVL arv) {

    if (arv != NULL) {

        printItem(arv->item);
        preOrdem(arv->esquerda);
        preOrdem(arv->direita);
    }
}