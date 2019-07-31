#include "abb.h"

struct tpNo {
		
	Item item;
	struct tpNo *esquerda;
	struct tpNo *direita;
};

ABB initABB(void) {
	return NULL;
}

ABB insertABB_ABB(ABB mae, ABB filha) {
	
	if (mae != NULL) {
		
		short compar = itemCmp(&filha->item, &mae->item);
		
		if (compar == -1) {
			mae->esquerda = insertABB_ABB(mae->esquerda, filha);
		} else if (compar == 1) {
			mae->direita = insertABB_ABB(mae->direita, filha);
		} else if (compar == 0) {
			mae->item = filha->item;
		}
		
		return mae;
	}
	
	return filha;
}

ABB insertABB(Item item, ABB arv) {
	
	ABB no = (ABB)malloc(sizeof(struct tpNo));
			
	if (no != NULL) {
		
		no->item = item;
		no->esquerda = NULL;
		no->direita = NULL;
		
		return insertABB_ABB(arv, no);
	}
	
	return arv;
}

ABB buscaPaiABB(const Item *item, ABB arv) {
	
	ABB temp = NULL;
	short compar;
	
	while (arv != NULL) {
	
		compar = itemCmp(item, &arv->item);
		
		if (compar == -1) {
			
			temp = arv;
			arv = arv->esquerda;
		}
		
		else if (compar == 1) {
			
			temp = arv;
			arv = arv->direita;
		}
		
		else if (compar == 0) {
			return temp;
		}
	}
	
	return NULL;
}

ABB deleteItemABB(Item item, ABB arv) {
	
	ABB pai = buscaPaiABB(&item, arv), corrompido, temp;
	
	if (pai != NULL) {
		
		if (!itemCmp(&item, &pai->direita->item)) {
		
			corrompido = pai->direita;
			
			if (corrompido->esquerda != NULL) {
			
				pai->direita = corrompido->esquerda;
				insertABB_ABB(pai->direita, corrompido->direita);
			}
			
			else {
				pai->direita = corrompido->direita;
			}
		}
		
		else {
		
			corrompido = pai->esquerda;
			
			if (corrompido->esquerda != NULL) {
			
				pai->esquerda = corrompido->esquerda;
				insertABB_ABB(pai->esquerda, corrompido->direita);
			}
			
			else {
				pai->esquerda = corrompido->direita;
			}
		}
		
		free(corrompido);
	}
	
	else if (arv != NULL && !itemCmp(&item, &arv->item)) {
		
		if (arv->esquerda != NULL) {
			temp = insertABB_ABB(arv->esquerda, arv->direita);
		} else {
			temp = arv->direita;
		}
		
		free(arv);
		return temp;
	}
	
	return arv;
}

void inOrdemABB(const ABB arv) {
	
	if (arv != NULL) {
		
		inOrdemABB(arv->esquerda);
		printItem(arv->item);
		inOrdemABB(arv->direita);
	}
}

void preOrdemABB(const ABB arv) {
	
	if (arv != NULL) {
		
		printItem(arv->item);
		preOrdemABB(arv->esquerda);
		preOrdemABB(arv->direita);
	}
}

















