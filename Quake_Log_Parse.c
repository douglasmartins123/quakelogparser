#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//teste
// declaracao variaveis
int totalKills=0;
int totalInit=0;
int totalItem=0;
int userChanges=0;
char* token;
char frase[1000];
char string[];
char lineOutput[];
int test;
int i;
char *items[] = {};

int main (int argc, char *argv[]) {
	
	printf("Aplicacao que conta a quantidade de Jogos e Derrotas \n no arquivo 'qgames.log' localizado na pasta atual: \n\n");
	FILE *file;
	file = fopen("qgames.log", "r");
	
	if (file == NULL){
		printf("Arquivo nao encontrado!\n");
		exit(0);
	}

	char read[100];
	while(fgets(frase,1000,file)!= NULL){
		strcpy(lineOutput, frase);
	    token = strtok(frase, " ");
	    i=0;
	    while (token != NULL) {
	        token = strtok(NULL, " ");
	        if (i == 0){
		       	if (stricmp (token, "Kill:") == 0 )kills();
		       	if (stricmp (token, "InitGame:") == 0 )addInit();
			}
	       	i++;
	    }
	}
	fclose(file);
	mostraDados();
	system("pause");
}

char* addItem(char x[]){
	//funcao que adiciona um item no array items;
	int countP = countItems();
	items[countP]=x;	
	i++;
	return 0;	
}

char* checkItem(char y[]){
	// funcao checa se o Item ja foi cadastrado e retorna o resultado sendo 0: falso e 1:verdadeiro;;
	i=0;
	while(items[i] != '\0')
	{
		if (stricmp (items[i],y) == 0){
			return 1;
		};
		i++;
	}
	return 0;
}

int countItems(){
	//funcao que conta quantos indices tem no array items ;
	i=0;
	while(items[i] != '\0'){
		i++;
	}
	return i;
}

void showItems(){
	//funcao que lista o array items ;
	i=0;
	while(items[i] != '\0'){
		printf("%i %s \n",i,items[i]);
		i++;
	}
}

void mostraDados(void){

	printf("   Total_Games: %i \n\n",totalInit);
	printf("   { \n");
	printf("     total_kills: %i \n", totalKills);
	printf("     players: {        }\n");
	printf("     kills: {          }\n");

	printf("   }\n\n");

}

void Item(){
	//Funcao Desatibilitada
    token = strtok(lineOutput, " ");
    i=0;
    while (token != NULL) {
        token = strtok(NULL, " \\");
        if (i == 2){
	       	//if (checkItem(token)==0 addItem(token));
	       	//printf("%s \n", token);
	       test = checkItem(token);
	       //if (test==0) addItem(token);
	       addItem(token);
	       showItems();
		}
       	i++;
    }
	system("pause");
	totalItem++;
}

void kills(){
    totalKills++;
}
	
void addInit(){
	totalInit++;
}

