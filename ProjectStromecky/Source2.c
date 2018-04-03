#include <stdio.h>

//This reads input in prefix and returns it in postfix and infix

struct uzel {
	int infoI;
	char infoC;
	struct uzel*left;
	struct uzel*right;
};

struct uzel*strom = NULL;

int DoctiCislo(char c) {
	int i = 0;
	while (('0' <= c) && (c <= '9')) {
		i = 10 * i + c - '0';
		c = getchar(); //skoncim s c=mezera nebo newline
	}
	return i;
}

void nacti(struct uzel*pos) {
	char c;
	c = getchar();
	if (('0' <= c) && (c <= '9')) {
		pos->infoI = DoctiCislo(c);
		pos->infoC = -1;
	}
	else {
		pos->infoI = 0;
		pos->infoC = c;
		c = getchar(); //zeru mezeru
		pos->left = malloc(sizeof(struct uzel));
		pos->left->left = NULL;
		pos->left->right = NULL;
		pos->right = malloc(sizeof(struct uzel));
		pos->right->left = NULL;
		pos->right->right = NULL;
		nacti(pos->left);
		nacti(pos->right);
	}
}

void vypisPOSTFIX(struct uzel*pos) {
	if (pos->left != NULL) vypisPOSTFIX(pos->left);
	if (pos->right != NULL) vypisPOSTFIX(pos->right);
	if (pos->infoC == -1) printf("%d", pos->infoI);
	else if (pos->infoC != -1) printf("%c", pos->infoC);
	if (pos != strom) printf(" ");
	else printf("\n");
}

void vypisINFIX(struct uzel*pos) {
	if (pos->left != NULL) {
		printf("(");
		vypisINFIX(pos->left);
	}
	if (pos->infoC == -1) printf("%d", pos->infoI);
	else if (pos->infoC != -1) {
		printf(" %c ", pos->infoC);
	}
	if (pos->right != NULL) {
		vypisINFIX(pos->right);
		printf(")");
	}
}


int main() {
	char c;
	strom = malloc(sizeof(struct uzel));
	strom->left = NULL;
	strom->right = NULL;
	nacti(strom);
	vypisPOSTFIX(strom);
	vypisINFIX(strom);
	printf("\n");
	return 0;
}