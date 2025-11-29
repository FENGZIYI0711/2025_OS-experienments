#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdio.h>
#include <windows.h>

#define MAX_SIZE 1000
#define ALLOC_MIN_SIZE 10//最小分配空间大小.

#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE

typedef struct Bound{
	union {
		struct Bound * preLink;//头部域前驱
		struct Bound * upLink;//尾部域，指向结点头部
	};
	int tag;//0标示空闲,1表示占用
	int size;//仅仅表示 可用空间，不包括 头部 和 尾部空间
	struct Bound * nextLink;//头部后继指针.
}*Space;

#define FOOT_LOC(p) ((p)+(p->size)-1)//尾部域位置

void initSpace(Space * freeSpace,Space * pav);
Space allocBoundTag(Space * pav,int size);
void reclaimBoundTag(Space * pav,Space sp);
void SetColor(int color);
void print(Space s);
void printSpace(Space pav);


#endif /* CONSOLE_H_ */
