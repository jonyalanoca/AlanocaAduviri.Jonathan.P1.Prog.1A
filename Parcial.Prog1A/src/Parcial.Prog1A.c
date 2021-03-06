
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 6
typedef struct{
	int id;
	char nombre[20];
	char tipo;
	float efectividad;
}eVacuna;

int ordenarVacunas(eVacuna lista[], int tam);
int mostrarArray(eVacuna lista[], int tam);

float aplicarAumento(int precio);
int reemplazarCaracteres(char texto[], char letra1, char letra2);
int main(void) {
	setbuf(stdout,NULL);
	eVacuna vacunas[TAM]={
			{1001,"Moderna",'c',80},
			{1002,"Pfizer",'b',100},
			{1003,"Sputnik",'b',50},
			{1004,"Johnson",'c',95},
			{1005,"Sanofi",'b',75},
			{1006,"Cansino",'c',99},
	};
	printf("Precio total: %.2f\n",aplicarAumento(1000));
	ordenarVacunas(vacunas,TAM);
	mostrarArray(vacunas,TAM);

	printf("%d\n",reemplazarCaracteres("jonathan",'n','o'));
	return EXIT_SUCCESS;
}
float aplicarAumento(int precio){
	float total;
	if(precio<=0){
		total=precio;
	}else{
		total=precio+(precio*5/100);
	}
	return total;
}
int reemplazarCaracteres(char texto[], char letra1, char letra2){
	int todoOk=0;
	if(texto!=NULL){
		int tam=strlen(texto);

		for(int i=0; i<tam;i++){

			if(texto[i]==letra1){
				texto[i]=letra2;
				todoOk++;
			}
		}
	}
	return todoOk;
}
int ordenarVacunas(eVacuna lista[], int tam){
    int todoOk=-1;
    eVacuna aux;
    if(lista!=NULL && tam>0){
        for(int i=0; i<tam-1;i++){
			for(int u=i+1; u<tam; u++){
    			if(lista[i].tipo>lista[u].tipo){
    				aux=lista[i];
    				lista[i]=lista[u];
    				lista[u]=aux;
    			}else if(lista[i].tipo==lista[u].tipo && lista[i].efectividad>lista[u].efectividad){
    				aux=lista[i];
    				lista[i]=lista[u];
    				lista[u]=aux;
    			}
			}
		}
        todoOk=0;
    }
    return todoOk;
}
int mostrarArray(eVacuna lista[], int tam){
    int todoOk=-1;
    if(lista!=NULL && tam>0){
        printf("ID NOMBRE TIPO EFECTIVIDAD\n");
        for(int i=0; i<tam;i++){
			printf("%d %s %c %.2f\n", lista[i].id, lista[i].nombre, lista[i].tipo, lista[i].efectividad);
        }
        todoOk=0;
    }
    return todoOk;
}
