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

	FILE *file;
	file = fopen(cpf, "r");//abrir o arquivo para ler

	if(file == NULL){
		strcpy(arquivo, cpf); // função responsável por copiar os valores da string
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w");//abre o arquivo para escrita
		fprintf(file, "\nCPF: ");
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file);//fecha o arquivo
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file, "\nNome: ");
		fprintf(file, nome);
		fclose(file);
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file, "\nSobrenome: ");
		fprintf(file, sobrenome);
		fclose(file);
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, "\nCargo: ");
		fprintf(file, cargo);
		fclose(file);	
	}
	else{
		printf("\nCPF já cadastrado\n");
	}
	
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
		printf("\nNão localizado! ");
	}
	else{
		printf("\nEssas são as informações do usuário: \n");
		
		while(fgets(conteudo, 200, file) != NULL){//armazena as informações do file em conteudo até acabar as informações
			printf("%s", conteudo);
		}
	}
	printf("\n\n");
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
	char senhadigitada[10]="a";//definindo variavel para senha
	int comparacao;//definindo variavel para comparar a senha digitada
	
	setlocale(LC_ALL, "Portuguese"); //Definindo para o padrão português de caracteres
	
	printf("-----Cartório da EBAC-----\n\n");
	printf("Login de Administrador!\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//compara uma string
	
	if(comparacao == 0 ){
	
		for(laco=1; laco=1; ){
	
			system("cls");//Limpar a tela
	
			//Título do menu:
			printf("-----Cartório da EBAC-----\n\n");
	
			//Opções do menu:
			printf(" Escolha a opção do menu:\n\n");
			printf("  1 - Registrar nomes:\n");
			printf("  2 - Consultar nomes: \n");
			printf("  3 - Deletar nomes: \n");
			printf("  4 - Sair do programa: \n\n ");
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
			
				case 4: 
					printf("Obrigado por utilizar o sistema!\n");
					return 0; //sair do programa 
				break;
				
				default:
					printf("Opção indisponível!\n");
					system("pause");//Pausar tela
				break;	
			}//Fim da seleção
		}
	}
	else
		printf("\nSenha incorreta");
}
