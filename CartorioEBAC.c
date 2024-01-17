#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca responsavel por cuidar das strings

int registro(){//Fun��o para registro
	//declarando variaveis "string"
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� escolheu o registro de nomes!\n");
	
	printf("\nDigite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere a string
	
	strcpy(arquivo, cpf); // fun��o respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//abre o arquivo para escrita
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo para atualizar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n");
	
	system("pause");//Pausar tela
}

int consulta(){//fun��o para cosulta
	
	setlocale(LC_ALL, "Portuguese"); //Definindo para o padr�o portugu�s de caracteres
	
	printf("Voc� escolheu consultar nomes!\n");
	//declara��p das variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser cosultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//abrir o arquivo para ler
	
	if(file == NULL){//quando o arquivo � nulo
		printf("\nN�o localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){//armazena as informa��es do file em conteudo at� acabar as informa��es
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s\n\n", conteudo);
	}
	fclose(file);
	system("pause");//Pausar tela
}

int deletar(){//fun��o para deletar
	char cpf[40];
	
	printf("Voc� escolheu deletar nomes!\n");
	printf("\nDigite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		printf("\nCPF n�o encontrado\n");	
	}
	else{
	remove(cpf); //remove o arquivo com o nome do CPF
	}
	printf("\n");
	system("pause");//Pausar tela
}

int main(){
	
	int opcao = 0; //definindo a variavel para opcao do menu
	int laco=1; //definindo variavel la�o 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo para o padr�o portugu�s de caracteres
	
	for(laco=1; laco=1; ){
	
		system("cls");//Limpar a tela
	
		//T�tulo do menu:
		printf("-----Cart�rio da EBAC-----\n\n");
	
		//Op��es do menu:
		printf(" Escolha a op��o do menu:\n\n");
		printf("  1 - Registrar nomes:\n");
		printf("  2 - Consultar nomes: \n");
		printf("  3 - Deletar nomes: \n\n");
		printf("  Qual op��o voc� deseja: ");
	
		scanf("%d", &opcao);//armazenando a op��o do variavel
	
		system("cls"); //Limpar a tela
		
		switch(opcao){ //Inicio da sele��o
			case 1:
				registro();	//chamada da fun��o registro
			break;
			
			case 2:
				consulta();//chamada da fun��o consulta
			break;
			
			case 3:
				deletar();//chamada da fun��o deletar
			break;
			
			default:
				printf("Op��o indispon�vel!\n");
				system("pause");//Pausar tela
			break;	
		}//Fim da sele��o
	}
}
