#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mergesort.h"
#include "el.h"
// Combina i due sottoarray ordinati [p, q] e [q+1, r].mio personale tempo impiegato:27.7275s
void merge(char array[][22], int p, int q, int r) //PORCODIO r = sizeof(vettore) quindi se vet[n]; r=n-1;
{	
	char scambio[22];
	for (;q<r;q++){
	//	printf("q:%d\n",q);
		//printf(array[q+1]);
		if(strcoll(array[q],array[q+1])<0) return;
		else {
			for(;q<=r;q++){
				
				for(int j=q; j>=p && strcoll(array[j],array[j+1])>0; j--){
				//	printf("j:%d\n",j);
					strcpy(scambio,array[j]);
					strcpy(array[j],array[j+1]);
					strcpy(array[j+1],scambio);
				}
			}
		}
	}
}
/*
#include<stdlib.h>
// Combina i due sottoarray ordinati [p, q] e [q+1, r]. quello della soluzione:
void merge(int *array, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = 0; //array 0-based
	int* B =(int *) malloc((r-p+1)*sizeof(int));

	//Ordina
	while (i <= q && j <= r)
	{
		if (array[i] < array[j])
			B[k] = array[i++];
		else
			B[k] = array[j++];

		k++;
	}
	//---

	//Ricopia leftover sx
	while (i <= q)
		B[k++] = array[i++];
	//---

	//Ricopia leftover dx
	while (j <= r)
		B[k++] = array[j++];
	//---

	//Ricopia B in A
	for (k = p; k <= r; k++)
		array[k] = B[k-p];
	//---

	free(B);
}

*/




// Ordina l'array dall'indice p all'indice r inclusi
void mergeSort(char array[][22], int p, int r) //PORCODIO r = sizeof(vettore) quindi se vet[n]; r=n-1;
{
	int q = (p + r) / 2;           // si noti che in C la divisione tra interi memorizzata in variabile intera comporta il troncamento del numero all'intero inferiore (floor)
	if (p < r)
	{
		mergeSort(array, p, q);    // Ordina il sottoarray di sinistra
		mergeSort(array, q + 1, r);  // Ordina il sottoarray di destra
		merge(array, p, q, r);      // Combina i due sottoarray
	}
}

lista* merge_liked_lists(lista *l_sinistra,lista *l_destra){
/*	printf("mergeee!\n");
	
	puts("________________");
	stampa_orari(l_sinistra);
	puts("________________");
	stampa_orari(l_destra);*/
	lista* nuova_testa=l_sinistra;
	lista *sinistra=l_sinistra;
	lista *destra=l_destra;
	lista *sinistra_iniziale=sinistra;
	lista *destra_iniziale=destra;
	lista *scambio;
	if(l_destra==NULL){ //stampa_orari(l_sinistra);puts("\n/\n");
	return l_sinistra;}
	if (l_sinistra==NULL) {//stampa_orari(l_destra);puts("\n/\n");
	return l_destra;}

	if(strcoll(nuova_testa->elemento.cognome,l_destra->elemento.cognome)>0) nuova_testa=l_destra;

	//	printf("[0]\n");
	while(sinistra!=NULL){

	//	printf("[1]\n");
		if(strcoll(sinistra->elemento.cognome,destra->elemento.cognome)<=0){
		//	puts("[1]");
			
	//	printf("[2]\n");
			sinistra_iniziale=sinistra;
			sinistra=sinistra->next;
		} else {	//qua nella condizione del while controllo da destra->next, perché il primo l'ho già beccato nell'if (sono in else infatti)
			
//		printf("[3]\n");
			destra=destra_iniziale;
			if(destra==NULL) break;
			else if(!(destra->next==NULL)){
	//		printf("[3.1]\n");
				while(strcoll(sinistra->elemento.cognome,destra->next->elemento.cognome)>0) {
					destra=destra->next;
					//in questo modo controllo tutti gli elementi senza rischiare di fare strcoll su stringhe strane
					if(destra->next==NULL) break;
				}
			}
			//attacco qua i pezzi nell'ordine giusto
			if(sinistra_iniziale==sinistra){
			//	printf("[6]\n");
				//se devo scambiare anche la prima
				/*stampa_orari(sinistra_iniziale);
				puts("_______");
				stampa_orari(destra_iniziale);

				if(destra_iniziale==NULL) puts("MA ALLORA PORCA MADONNA");*/
				scambio=destra->next;
				destra->next=sinistra_iniziale;
				//sinistra->next=scambio;
				sinistra_iniziale=sinistra;
				
				sinistra=sinistra->next;
				//sinistra=sinistra->next;
				destra_iniziale=scambio;
				destra=destra_iniziale;
				if(destra_iniziale==NULL) {//stampa_orari(nuova_testa);puts("\n/\n"); 
				return nuova_testa;}

	//	printf("[7]\n");
			} else if(destra_iniziale->next==NULL && sinistra_iniziale->next!=NULL){
			/*	puts("___");
				stampa_orari(sinistra_iniziale);puts(":::::::::::\n");stampa_orari(destra_iniziale);
				puts("___");*/
			//	printf("[7]\n");
				sinistra=sinistra_iniziale;
				while(sinistra!=NULL){

	//	printf("[1]\n");
					if(strcoll(sinistra->elemento.cognome,destra_iniziale->elemento.cognome)<=0){
						//puts("[1]");
						
				//	printf("[2]\n");
						sinistra_iniziale=sinistra;
						sinistra=sinistra->next;
					} else break;
				}
				scambio=sinistra_iniziale->next;

				sinistra_iniziale->next=destra_iniziale;

				destra_iniziale->next=scambio;
				destra_iniziale=destra;
				destra=destra_iniziale;

			//	stampa_orari(nuova_testa);puts("\n/\n");
				return nuova_testa;
			} else {
//printf("[8]\n");
				scambio=sinistra_iniziale->next;
				sinistra_iniziale->next=destra_iniziale;
				destra_iniziale=destra->next;		
				destra->next=scambio;
				sinistra_iniziale=sinistra;
				sinistra=sinistra->next;
				destra=destra_iniziale;
	//	printf("[4]\n");
				if(destra_iniziale==NULL){
	//stampa_orari(nuova_testa);puts("\n/\n"); 
					return nuova_testa;}
			}
		}
		//devo attaccare il resto che mi è rimasto in destra
/*		if (sinistra==NULL) break;
		sinistra_iniziale=sinistra;
		
		sinistra=sinistra->next;
*/
	}
	//	sinistra_iniziale->next=destra_iniziale;
	//	printf("[1111]\n");
	if(destra_iniziale!=NULL) sinistra_iniziale->next=destra_iniziale; //non so se serve

	//return testa (sotto)






/*	while(sinistra->next!=*croce && sinistra->next!=NULL){
		if(strcoll(sinistra->elemento.cognome,destra->elemento.cognome)<0) {
			sinistra_iniziale=sinistra;
			sinistra=sinistra->next;
		}
		else {
			while(strcoll(sinistra->elemento.cognome,destra->next->elemento.cognome)>0 && destra!=ultimo){

				 destra=destra->next;
			}
			
			if(sinistra_iniziale==*testa) {
				testa=croce;
			}
				
			sinistra_iniziale->next=destra_sinistra;
			scambio=destra->next;
			destra->next=sinistra;
			
			destra=scambio;
			destra_sinistra=destra;
			sinistra=sinistra->next;
		
		}
	}
*	stampa_orari(nuova_testa);
	puts("\n/\n");*/
	return nuova_testa;
}
// Ordina l'array dall'indice p all'indice r inclusi
lista** mergeSort_linked_list(lista* *testa) //PORCODIO r = sizeof(vettore) quindi se vet[n]; r=n-1;
{
	//printf("[1]\n");
	lista *primo=*testa;
	//static int i=0;

	//if(*testa==NULL || (*testa)->next==NULL) return;
	if(primo==NULL) return NULL; else if(primo->next==NULL ) return testa;
	lista* slow=primo;
	lista* fast=primo;
	lista **a,**b;
	
	//printf("[2]\n");
	while(fast!=NULL && fast->next!=NULL && slow->next->next!=NULL){

	
		//if(fast->next==NULL) {printf("if 1\n"); break;}
		slow=slow->next;
		//if(fast->next->next==NULL) {printf("if 2\n");break; }
		//if(fast->next->next->next==NULL) {fast=fast->next->next; printf("if 3\n");/* sono sicuro sia giusta*/break; }
		
		fast=fast->next->next;

	}

//	printf("[3]\n");
	fast=slow->next;
	slow->next=NULL;
	//b=a->next;
	//printf("\ninizio sottochiamate\n");
	
	//	printf("%d a\n",i++);
	//	if(i>9998) stampa_orari(testa);
		a=mergeSort_linked_list(&primo);    // Ordina il sottoarray di sinistra
	//	printf("b\n");
		b=mergeSort_linked_list(&fast);  // Ordina il sottoarray di destra
	//	printf("c\n");
		*testa=merge_liked_lists(*a, *b);      // Combina i due sottoarray
	
		//stampa_orari(*testa);
	
	return testa;
}

