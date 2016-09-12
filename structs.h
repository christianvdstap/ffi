#ifndef STRUCTS_H
#define STRUCTS_H

struct simple {
	int number;
};

int simpleFunc(struct simple *param);
int simplePointerFunc(struct simple **param);

#endif
