#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsavel por cadastrar os usuarios nop sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando insformações do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf ); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // abre o arquivo e o "a" armazena dentro do arquivo
	fprintf(file,","); // escrevendo "," dentro do arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando insformações do usuario
	scanf("%s",nome); //%s refere-se a strings
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//inicio da criação de variaveis/string
	char conteudo[200];
	char cpf[40];
	//final da criação de variaveis/string
	printf("Digite o cpf a ser consultado: "); //coletando insformações do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
	
	
	if(file == NULL) // refere-se caso não tenha o cpf citado no sistema
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!. \n");// mensagem dada após não achar o cpf no sistema
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		        
		printf("\nInformações: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}

	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);
	
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo "r" significa ler
	fclose(file); // fecha o arquivo
	
	if(file == NULL) //caso não tenha o cpf no sistema
	{
		printf("O Usuário não se encontra no sistema! \n");//caso a resposta dada pelo o usuario não exista
		
	}
		else
		{
		remove(cpf);
		printf("Usuário deletado com sucesso! \n\n");
		} //caso tenha o cpf cadastrado no sistema

		system("pause");
	 	
}


int main ()
    {
    int opcao=0; //Definindo as variaveis
    int x=1;
    
    for(x=1;x=10;)
    {

       
            system("cls");// responsavel por limpar a tela
        

	        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	        printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	        printf("Escolha a opção desejada do menu\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
	        printf("Opção: ");//fim do menu
	
	        scanf("%d", &opcao); //armazenando a escolha do usuário
	
 	        system("cls");
 	    
 	    
 	        switch(opcao)//inicio da seleção do menu
	 	    {
			case 1:
			registro();//chamada de funções
 	        break;
 	        
 	        case 2:
 	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	        
	        default:
	       	printf("Essa opção não está disponivel!\n");
	        system("pause");
	        break;
		    // final da seleção do menu
		
		}
	
	   
    }
}

