/* Implementazione dell'Algoritmo BitPattern per il PatternMatching.
L'algoritmo controlla quante volte il pattern P viene ripetuto nel testo T.
(Si presuppone un tempo di esecuzione O(n)).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lunghezza.h"

/* Prototipi di funzioni:*/

void buildArray(int ar[], char *testo, char k); // costruisce i vettori Ux settando a 1 le posizioni in cui x compare nel pattern P, per 														ogni x dell'alfabeto del testo T.
void printArray(int ar[], int dim); 			// stampa a video un array
int occurrency(char *testo, char *pattern, int l_testo, int l_pattern); // conteggio occorrenze tramite la matrice m(i,j);
char *substring(char *t1, int in, int f); 		//copia nell'array temp la sottostringa di lunghezza i dell'array t1
int *shiftRight(int *p, int i); 				// shifta a destra il puntatore p
int *logicAnd(int *p, int v[], int i);			// AND logico

int main() {
	char *testo=(char *)malloc(sizeof(char)*5000000000);
	char *pattern=(char *)malloc(sizeof(char)*10);
	printf("Inserisci il testo T ");
	scanf("%s", testo);	
	printf("Inserisci il pattern P ");
	scanf("%s", pattern);
	int lunghTesto=length(testo);
	int lunghPattern=length(pattern);
	printf("Ci sono %d occorrenze del pattern P nel testo T\n", occurrency(testo, pattern, lunghTesto, lunghPattern));
} 
int occurrency(char *testo, char *pattern, int l_testo, int l_pattern){ 
	/* 
	DEFINIZIONE DEL CALCOLO DELLA MATRICE M
	M(i,j)=1 sse P[: j] = T[i-j+1 : i]
	-- La variabile count memorizza il numero di occorrenze del pattern P nel testo T --
		Se M(i,j) == 1 quando j==l_pattern --> Incremento di 1 il contatore count
	
	Passo 1: Costruzione dei vettori Ux per ogni x dell'alfabeto sigma
	*/		
	
	int a[l_pattern]; buildArray(a, pattern, 'a');
	int b[l_pattern]; buildArray(b, pattern, 'b');
	int c[l_pattern]; buildArray(c, pattern, 'c'); 
	int d[l_pattern]; buildArray(d, pattern, 'd');
	int e[l_pattern]; buildArray(e, pattern, 'e');
	int f[l_pattern]; buildArray(f, pattern, 'f');
	int g[l_pattern]; buildArray(g, pattern, 'g');
	int h[l_pattern]; buildArray(h, pattern, 'h');
	int i[l_pattern]; buildArray(i, pattern, 'i');
	int j[l_pattern]; buildArray(j, pattern, 'j');
	int k[l_pattern]; buildArray(k, pattern, 'k');
	int l[l_pattern]; buildArray(l, pattern, 'l');
	int m[l_pattern]; buildArray(m, pattern, 'm');
	int n[l_pattern]; buildArray(n, pattern, 'n');
	int o[l_pattern]; buildArray(o, pattern, 'o');
	int p[l_pattern]; buildArray(p, pattern, 'p');
	int q[l_pattern]; buildArray(q, pattern, 'q');
	int r[l_pattern]; buildArray(r, pattern, 'r');
	int s[l_pattern]; buildArray(s, pattern, 's');
	int t[l_pattern]; buildArray(t, pattern, 't');
	int u[l_pattern]; buildArray(u, pattern, 'u');
	int v[l_pattern]; buildArray(v, pattern, 'v');
	int w[l_pattern]; buildArray(w, pattern, 'w');
	int x[l_pattern]; buildArray(x, pattern, 'x');
	int y[l_pattern]; buildArray(y, pattern, 'y');
	int z[l_pattern]; buildArray(z, pattern, 'z');
		
	/* la prima riga della matrice m 
	viene calcolata esplicitamente 
	seguendo la definizione
	*/
	int m1[l_pattern]; 
	int j1;			
	char * subPattern=substring(pattern, 1, 1);  // P[: j]
	char * subTesto=substring(testo, 1, 1); 	 // T[i-j+1: i]
	if (subPattern[0]==subTesto[0])
		m1[0]=1;
	else
		m1[0]=0;	
	for(j1=1; j1<l_pattern; j1++){
		m1[j1]=0;
	}
	printf("Riga 1 :\t");
	int kk;
	for(kk=0; kk<l_pattern; kk++){
		printf("%d ", m1[kk]);	
	}
	printf("\n");
	int count=0;
	int index;
	int *puntat=m1; // puntatore alla prima riga della matrice
	/* Calcolo della righe i della matrice M(i,j):
		Per ogni i, M(i,*) viene calcolata come 
		(R_SHIFT(M(i-1,*))L_AND(U(T[i])))
	*/	
	for(index=1; index<l_testo; index++){
		int *m1s = shiftRight(puntat, l_pattern);
		int *m2; 
		switch (testo[index]){
			case 'a': m2 = logicAnd(m1s, a, l_pattern);break;
			case 'b': m2 = logicAnd(m1s, b, l_pattern);break;
			case 'c': m2 = logicAnd(m1s, c, l_pattern);break;
			case 'd': m2 = logicAnd(m1s, d, l_pattern);break;
			case 'e': m2 = logicAnd(m1s, e, l_pattern);break;
			case 'f': m2 = logicAnd(m1s, f, l_pattern);break;
			case 'g': m2 = logicAnd(m1s, g, l_pattern);break;
			case 'h': m2 = logicAnd(m1s, h, l_pattern);break;
			case 'i': m2 = logicAnd(m1s, i, l_pattern);break;
			case 'j': m2 = logicAnd(m1s, j, l_pattern);break;
			case 'k': m2 = logicAnd(m1s, k, l_pattern);break;
			case 'l': m2 = logicAnd(m1s, l, l_pattern);break;
			case 'm': m2 = logicAnd(m1s, m, l_pattern);break;
			case 'n': m2 = logicAnd(m1s, n, l_pattern);break;
			case 'o': m2 = logicAnd(m1s, o, l_pattern);break;
			case 'p': m2 = logicAnd(m1s, p, l_pattern);break;
			case 'q': m2 = logicAnd(m1s, q, l_pattern);break;
			case 'r': m2 = logicAnd(m1s, r, l_pattern);break;
			case 's': m2 = logicAnd(m1s, s, l_pattern);break;
			case 't': m2 = logicAnd(m1s, t, l_pattern);break;
			case 'u': m2 = logicAnd(m1s, u, l_pattern);break;
			case 'v': m2 = logicAnd(m1s, v, l_pattern);break;
			case 'w': m2 = logicAnd(m1s, w, l_pattern);break;
			case 'x': m2 = logicAnd(m1s, x, l_pattern);break;
			case 'y': m2 = logicAnd(m1s, y, l_pattern);break;
			case 'z': m2 = logicAnd(m1s, z, l_pattern);break;

		}
		puntat=m2;	
		printf("Riga %d :\t", index+1);
		int hh;	
		for(hh=0; hh<l_pattern; hh++){
			printf("%d ", m2[hh]);
		}	
		printf("\n");
		if (m2[l_pattern-1]==1)
			count++;
	}
	return count;
}
int *shiftRight(int *p, int i){
	int j;
	int *punt=(int *)malloc((i)*sizeof(int));
	for(j=1; j<i; j++){
		punt[j]=p[j-1];
	}
	punt[0]=1;
	return punt;
}
int *logicAnd(int *p, int v[], int j){
	int *ret=(int *)malloc((j)*sizeof(int));
	int i;
	for(i=0; i<j; i++){
		if (v[i]==1 && p[i]==1)
			ret[i]=1;
		else
			ret[i]=0;		
	}
	return ret;
}
void buildArray(int ar[], char *testo, char k){ 
	int i;
	for(i=0; i<strlen(testo); i++){ 
		if (testo[i]==k){
			ar[i]=1;	
		 }else
			ar[i]=0;	
	}
}
void printArray(int ar[], int dim){ 
	int i;
	for(i=0; i<dim; i++){
		printf("%d ", ar[i]);
	}
	printf("\n");
}


char* substring(char *t1, int i, int f){ 
	char* punt = (char *)malloc((f-i+1)*sizeof(char));
	int k=0;
	int j;
	for(j=i-1; j<f; j++){ 
		punt[k]=t1[j];
		k++;
	}
	return punt;
}
