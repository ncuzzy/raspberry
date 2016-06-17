#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int(*visit)(int e);

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

int CreatBiTree(BiTree &T) {
	char m;
	scanf("%c",&m);
	if (m == '#')
		T = NULL;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return -1;
		T->data = m;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	return 0;
}
int PreOrderTraverse(BiTree T, int(*visit)(char e)) {
	if (T) {
		if (visit(T->data))
			if (PreOrderTraverse(T->lchild, visit))
				if (PreOrderTraverse(T->rchild, visit))
					return 0;
	}
	else
		return 0;
}
int PrintElement(char e) {
	printf("%c",e);
	return 1;
}
int main() {
	BiTree T;
	CreatBiTree(T);
	PreOrderTraverse(T,PrintElement);
}
