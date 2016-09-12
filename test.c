#include "structs.h"
#include <stdio.h>

int main() {
	struct simple s = {1};
	simpleFunc(&s);
	printf("%d\n", s.number);
}
