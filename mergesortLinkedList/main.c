#include <time.h>
#ifdef benchmark
/* this macro is used to mark chunks of code that need to be benchmarked.
   it allows for a single use of ifdef instead of scattering it around.*/
#define MEASURE(name, func) \
{\
  clock_t first=clock();\
  func;\
  clock_t second=clock();\
  printf("Processor time taken by %s: %ldms\n", name,\
    (second-first)*1000/CLOCKS_PER_SEC);\
}
#else
#define MEASURE(name, func) func
#endif
//bisogna aggiungere -Dbenchmark al gcc


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "mergesort_linked_list.h"
#include "el.h"
#include<math.h>

void paragone(char vett[][22],lista* mia,int n,FILE* out){
	int strlen_sz,j=0;
	for(int i=0;i<n;i++){
		strlen_sz=strlen(mia->elemento.cognome);

		while (vett[i][j]==mia->elemento.cognome[j] && ++j<strlen_sz); 

		if(j==strlen_sz){
			j=0;
			fprintf(out,"%d corretto: %s | %s strlen_sz:%d\n",i,mia->elemento.cognome,vett[i],strlen_sz);
			mia=mia->next;
			
		}
		else {fprintf(out,"%d fallito: %s | %s strlen_sz:%d\n",i,mia->elemento.cognome,vett[i],strlen_sz); return;}
	}
	fprintf(out,"Le 2 liste corrispondono, sono ordinate.\n");
	return;
}
void paragone_tra_liste(lista* l_1,lista* l_2,FILE* out){

	int i=0;
	int strlen_s1;
	int strlen_s2;		
	while (l_1!=NULL){ 


		strlen_s1=strlen(l_1->elemento.cognome);

		strlen_s2=strlen(l_2->elemento.cognome);
		



		if(strlen_s2==strlen_s1){
			
			fprintf(out,"%d corretto: %s | %s strlen_sz:%d\n",i,l_1->elemento.cognome,l_2->elemento.cognome,strlen_s1);
			l_2=l_2->next;
			l_1=l_1->next;
			i++;
		}
		else {fprintf(out,"%d fallito: %s | %s strlen_sz:%d\n",i,l_1->elemento.cognome,l_2->elemento.cognome,strlen_s2); return;}
	}
	if(l_2!=NULL) printf("Dimensioni liste diverse\n");
	else printf("Le 2 liste corrispondono, sono ordinate.\n");

}

void script(const char *nomefile,int fanculo){

	FILE *f=fopen(nomefile,"w");
	if(f==NULL) printf("Errore apertura\n");
	srand((unsigned)time(NULL));

	int l_nome,t,carattere,n=fanculo;
	while(n--){
		l_nome=1+rand()%17;
		t=1+rand()%10;
		for(int i=0;i<l_nome;i++){
			
			carattere=65+rand()%25;
			fputc(carattere,f);
		}
		fputc(' ',f);
		fputc(t+47,f);
		fputc('\n',f);
	}
	fclose(f);
}

int main (int argc,char *argv[]) {
	int fanculo=atoi(argv[1]);
	script("dati_nuovi.txt",fanculo);
	lista *testa1=init_lista();
	lista **coda;
	FILE *f1;
	f1=fopen("dati_nuovi.txt","r");

	puts("____________________________");
	MEASURE("Creazione linked_list da file",
	crea_lista_disordinata_da_file(&testa1,f1));
	MEASURE("La bellissima mergesort sulle linked list",
	coda=mergeSort_linked_list(&testa1));
	

	FILE* ecco=fopen("ecco.txt","w");
	//stampa_orari(*coda);
	MEASURE("Scrittura della lista su file di output",
	scrivi_lista_su_file(*coda,ecco));

	//lista* dioporco=testa1;
	//stampa_orari(testa1,ecco));
/*	printf(coda->elemento.cognome);
	puts("\n");
	if (coda!=NULL) {
	stampa_orari(coda);
}
*/
	//coda=testa1;
//	stampa_orari(*coda);

	puts("____________________________");
	fclose(f1);
	f1=fopen("dati_nuovi.txt","r");
	FILE *out=fopen("out.txt","w");
	if(f1==NULL) printf("ciaone fopen\n");


//**************************************** uncomment this part for trying to sort with a standard mergesort on vectors
	
	char lista_disordinata[150002][22];
	int n=0,i=0,new_line_count=0;
	lista *testa=init_lista();
	MEASURE("costruisco il vettore (lettura file)",
	while(new_line_count!=EOF){
		new_line_count=fgetc(f1);
		if(new_line_count=='\n') { lista_disordinata[n++][i]=0;i=0; }
		else lista_disordinata[n][i++]=new_line_count;
	});
	MEASURE("Mergesort sul vettore",

	mergeSort(lista_disordinata,0,n-1));
	MEASURE("Creazione linked_list da vettore ordinato",

	fclose(f1);
	char temp[22];
	strcpy(temp,lista_disordinata[n-1]);
	new_line_count=n;
	
	for(i=0;i<--n;i++){
		strcpy(lista_disordinata[n],lista_disordinata[i]);
		strcpy(lista_disordinata[i],temp);
		strcpy(temp,lista_disordinata[n-1]);
	}
	

	n=new_line_count;




	
	
	//printf("benchmarked\n");
	
	testa=crea_lista_a_mano(testa,lista_disordinata,n));

//tolgo il merge sort sui vettori per avere n grandi

 //**************************************/

	lista *mia=init_lista();
	//stampa_orari(testa);
	f1=fopen("dati_nuovi.txt","r");
	puts("____________________________");
	MEASURE("InsertionSort (crea linked_list ordinata da file)",mia=crea_lista_da_file(mia,f1));
	printf("____________________________\n");
//	paragone(lista_disordinata,testa,n,out);
	//cancella(testa);
	paragone_tra_liste(mia,*coda,out);
	fclose(out);
	fclose(f1);

	//script("dati_nuovi.txt");




	return 0;
}
