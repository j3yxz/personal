#ifndef __el_h__
#define __el_h__
#include<stdio.h>

typedef struct ElementoLista{

	int ora;
	char cognome[20];
} elementoLista;

typedef struct ListaAppuntamenti{

	elementoLista elemento;
	struct ListaAppuntamenti *next;
} lista;

int isEmpty(lista *ptr_a_lista);
lista *init_lista(void);				//restituisce il puntatore alla lista (testa)
int len_lista(lista *ptr_a_lista);
lista *costruisci_lista(lista *testa,char **vettore_ordinato,int n);	//il vettore lo ordino nel main e devo dirgli quanti elementi ci sono
void stampa_orari(lista *ptr_a_lista);	//stampa la lista in ordine alfabetico con all'inizio gli orari
void scrivi_lista_su_file(lista *ptr,FILE* out); //uguale a stampa orari solo che scrive su uno stream (precedentemente aperto)
void orario_persona(lista *ptr_a_lista);//stampa gli orari relativi a una persona specifica
lista *crea_lista_a_mano(lista *mia,char array[][22],int n);
void cancella(lista*);
lista *crea_lista_da_file(lista *mia,FILE *in);
lista* crea_lista_disordinata_da_file(lista**,FILE*);
#endif