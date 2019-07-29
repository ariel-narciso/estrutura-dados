#include <stdio.h>
#include "abb.h"

int main(void) {
	
	ABB turma = initABB();
	int i;
	
	//for (i = 1; i <= 5; i++) {
		turma = insertABB(setItem("narciso", 100), turma);
	//}
	
	turma = insertABB(setItem("narciso", 150), turma);
	turma = insertABB(setItem("narciso", 50), turma);
	turma = insertABB(setItem("narciso", 75), turma);
	turma = insertABB(setItem("narciso", 85), turma);
	turma = insertABB(setItem("narciso", 81), turma);
	turma = insertABB(setItem("narciso", 65), turma);
	turma = insertABB(setItem("narciso", 68), turma);
	turma = insertABB(setItem("narciso", 60), turma);
	turma = insertABB(setItem("narciso", 86), turma);
	
	//preOrdemABB(turma);
	turma = deleteItemABB(setItem("oie", 75), turma);
	inOrdemABB(turma);
	
	return 0;
}
