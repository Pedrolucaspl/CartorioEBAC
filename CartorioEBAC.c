#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsavel por cuidar das strings

int registro(){//Função para registro
	//declarando variaveis "string"
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu o registro de nomes!\n");
	
	printf("\nDigite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cpf); //%s refere a string
	
	strcpy(arquivo, cpf); // função responsável por copiar os valores da string
	
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

int consulta(){//função para cosulta
	
	setlocale(LC_ALL, "Portuguese"); //Definindo para o padrão português de caracteres
	
	printf("Você escolheu consultar nomes!\n");
	//declaraçãp das variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser cosultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//abrir o arquivo para ler
	
	if(file == NULL){//quando o arquivo é nulo
		printf("\nNão localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){//armazena as informações do file em conteudo até acabar as informações
		printf("\nEssas são as informações do usuário: ");
		printf("%s\n\n", conteudo);
	}
	fclose(file);
	system("pause");//Pausar tela
}

int deletar(){//função para deletar
	char cpf[40];
	
	printf("Você escolheu deletar nomes!\n");
	printf("\nDigite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		printf("\nCPF não encontrado\n");	
	}
	else{
	remove(cpf); //remove o arquivo com o nome do CPF
	}
	printf("\n");
	system("pause");//Pausar tela
}

int main(){
	
	int opcao = 0; //definindo a variavel para opcao do menu
	int laco=1; //definindo variavel laço 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo para o padrão português de caracteres
	
	for(laco=1; laco=1; ){
	
		system("cls");//Limpar a tela
	
		//Título do menu:
		printf("-----Cartório da EBAC-----\n\n");
	
		//Opções do menu:
		printf(" Escolha a opção do menu:\n\n");
		printf("  1 - Registrar nomes:\n");
		printf("  2 - Consultar nomes: \n");
		printf("  3 - Deletar nomes: \n\n");
		printf("  Qual opção você deseja: ");
	
		scanf("%d", &opcao);//armazenando a opção do variavel
	
		system("cls"); //Limpar a tela
		
		switch(opcao){ //Inicio da seleção
			case 1:
				registro();	//chamada da função registro
			break;
			
			case 2:
				consulta();//chamada da função consulta
			break;
			
			case 3:
				deletar();//chamada da função deletar
			break;
			
			default:
				printf("Opção indisponível!\n");
				system("pause");//Pausar tela
			break;	
		}//Fim da seleção
	}
}
