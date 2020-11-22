#include "el.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int isEmpty(lista* mia){
	return (mia==NULL);

}

lista *init_lista(void){

	lista *mia=NULL;
	return mia;

}

int len_lista(lista *mia){
	if(mia==NULL) return 0;
	return 1+len_lista(mia->next);
}

lista *costruisci_lista(lista *mia,char **vettore_ordinato,int n){

	lista *testa=mia;
	char *spazio;
	for(int i=0;i<n;i++){
		mia=(lista*)malloc(sizeof(lista));
		//mia->elemento=(elementoLista*)malloc(sizeof(elementoLista));
		
		spazio=strchr(vettore_ordinato[i],' ');
		*spazio=0;
		strcpy(mia->elemento.cognome,vettore_ordinato[i]);

		while(!isdigit(++spazio));	
		
		mia->elemento.ora=atoi(spazio);
		mia->next=NULL;
		mia=mia->next;
	}
	return testa;
}
lista *crea_lista_a_mano(lista *mia,char array[][22],int n){
	lista *attuale=mia,*prossimo=NULL,*testa=mia;
	char *spazio;
	for (int i=0;i<n;i++){
		mia=(lista*)calloc(1,sizeof(lista));
		attuale=testa;
		while(attuale!=NULL && strcoll(array[i],/*array[i+1]*/attuale->elemento.cognome)>0){
			prossimo=attuale;
			attuale=attuale->next;
		}
		spazio=strchr(array[i],(int)*(" "));
		*spazio=0;
		strcpy(mia->elemento.cognome,array[i]);

		//while(!isdigit(spazio++)); DIOPORCO
		spazio++;
		
		mia->elemento.ora=atoi(spazio);
		mia->next=attuale;
		if(prossimo==NULL) testa=mia;
		else prossimo->next=mia,prossimo=NULL;
		

		attuale=testa;
	}
	mia=testa;
	return testa;
}
lista *crea_lista_disordinata_da_file(lista* *testa,FILE *in){
	lista *mia;
	lista* coda;
	lista* new;
	int n=0,i=0,new_line_count=0;
	char *spazio;
	char temp[22];
	*testa=(lista*)calloc(1,sizeof(lista));
	mia=*testa;

	while(new_line_count!=EOF){
		new_line_count=fgetc(in);
		if(new_line_count=='\n') { 
			temp[i]=0;
			i=0;
			n++;
			spazio=strchr(temp,(int)*(" "));
			*spazio=0;
			strcpy(mia->elemento.cognome,temp);

		//while(!isdigit(spazio++)); DIOPORCO
			spazio++;

			mia->elemento.ora=atoi(spazio);

			coda=mia;
			new=(lista*)calloc(1,sizeof(lista));
			mia->next=new;
			mia=mia->next;
		}
		else temp[i++]=new_line_count;
	}


	free(mia);
	coda->next=NULL;
	return *testa;
}
lista *crea_lista_da_file(lista *mia,FILE *in){
	lista *attuale=mia,*prossimo=NULL,*testa=mia;
	int n=0,i=0,new_line_count=0;
	char *spazio;
	char temp[22];
	while(new_line_count!=EOF){
		new_line_count=fgetc(in);
		if(new_line_count=='\n') { 
			temp[i]=0;
			i=0;
			n++;




		mia=(lista*)calloc(1,sizeof(lista));
		attuale=testa;
		while(attuale!=NULL && strcoll(temp,/*array[i+1]*/attuale->elemento.cognome)>0){
			prossimo=attuale;
			attuale=attuale->next;
		}
		spazio=strchr(temp,(int)*(" "));
		*spazio=0;
		strcpy(mia->elemento.cognome,temp);

		//while(!isdigit(spazio++)); DIOPORCO
		spazio++;
		
		mia->elemento.ora=atoi(spazio);
		mia->next=attuale;
		if(prossimo==NULL) testa=mia;
		else prossimo->next=mia,prossimo=NULL;
		

		attuale=testa;


		}
		

		else temp[i++]=new_line_count;
	}


	return testa;
}





void stampa_orari(lista *testa){

	lista *mia=testa;
	while(mia!=NULL) {
		
		printf("%d %s\n",mia->elemento.ora,mia->elemento.cognome);
		mia=mia->next;
	}
	printf("eheh\n");
	return;
}


void scrivi_lista_su_file(lista *mia,FILE* out){
	while(mia!=NULL) {
		
		fprintf(out,"%d %s\n",mia->elemento.ora,mia->elemento.cognome);
		mia=mia->next;
	}
	return;
}

void orario_persona(lista *mia){
	printf("\nDi chi stiamo parliamo?");
	char pers_da_cercare[20];
	if(scanf("%s",pers_da_cercare)!=1) printf("Brutta storia con scanf\n");
	else fflush(stdin);
	while(mia!=NULL) {
		if(strcmp(pers_da_cercare,mia->elemento.cognome)==0) printf("ora: %d\n",mia->elemento.ora);
		else if(strcmp(pers_da_cercare,mia->elemento.cognome)>0) break;
		mia=mia->next;
	}

}

void cancella(lista *mia){
	lista *ptr=mia->next;
	while(ptr!=NULL){
		free(mia);
		mia=ptr;
		ptr=ptr->next;
	}


}


