/*

#include <stdio.h>

struct uzel {
	int infoI;
	char infoC;
	struct uzel*left;
	struct uzel*right;
	struct uzel*father;
};

struct uzel*strom = NULL;

int DoctiCislo(char c); {
	int i = 0;
	while ((char)0 <= c <= (char)9) {
		i = 10 * i + c;
		c = getchar();
	}
	return i;
}

void nacti(struct uzel**strom) {
	char c;
	struct uzel*pos = *strom;
	c = getchar();
	pos = malloc(sizeof(struct uzel));
	pos->left = NULL;
	pos->right = NULL;
	pos->father = pos;
	pos->infoI = 0;
	pos->infoC = -1;
	if ((char)0 <= c <= (char)9) pos->infoI = DoctiCislo(c);
	else {
		pos->infoC = c;
		c = getchar();
	}
	while (c != '\n') {
		c = getchar();
		if (pos->left = NULL) {
			pos->left = malloc(sizeof(struct uzel));
			pos = pos->left;
		}
		else if (pos->right = NULL) {
			pos->right = malloc(sizeof(struct uzel));
			pos = pos->right;
		}
		if ((char)0 <= c <= (char)9) {

		}
	}
}

int main{

} */