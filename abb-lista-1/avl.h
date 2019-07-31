#ifndef AVL_H

    #define AVL_H

    #include <stdlib.h>
    #include "abb.h"

    typedef struct tpNo *AVL;

    AVL initAVL(void);

    AVL insertAVL(Item item, AVL arv);

    AVL deleteItemAVL(Item item, AVL arv);

    void inOrdem(AVL arv);

    void preOrdem(AVL arv);

#endif