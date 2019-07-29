#ifndef ABB_H
	
	#define ABB_H
	
	#include <stdlib.h>
	#include "item.h"
	
	typedef struct tpNo *ABB;
	
	struct tpNo {
		
	Item item;
	struct tpNo *esquerda;
	struct tpNo *direita;
};
	
	ABB initABB(void);
	
	ABB insertABB(Item item, ABB arv);
	
	ABB deleteItemABB(Item, ABB arv);
	
	void preOrdemABB(const ABB arv);
	
	void inOrdemABB(const ABB arv);
	
#endif
