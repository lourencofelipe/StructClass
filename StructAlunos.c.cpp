#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#define SAIR 5
#define CONFIRM 2 
#define SUBMENU 2
#define LIST 2
void escolha1(void);
void escolha2(void);
void escolha3(void);
void escolha4(void);



void limparTela();
void gotoxy(short x, short y);

typedef struct listaAlunos {
	int mat;
	char name[100];
	float nota1; 
	float nota2; 
	float average;
} turma;


char cantoec = 201, cantoeb = 200, cantodc = 187, cantodb = 188, cima = 205 , lado = 186, cruze = 204, cruzd = 185, auxname[100]; 
int opcao = 0, i = 0, totalEstudantes = 0, totalMatriculas = 0, id = 0, error = 0, confirm = 0, submenu = 0, aux1 = 0, whati = 0, SimOuNao = 0, auxmat = 0, x = 0, have = 0, list = 0, listaOpcao = 0, go = 0, j = 0;
float auxnota1 = 0;
float auxnota2 = 0;
float auxaverage = 0;
turma student[100];

int main(void) {
	
	while (opcao != SAIR) 
	{
		printf("%c", cantoec);	         
		for(i = 1; i < 40; i++)
		{
			printf("%c", cima);
		}
		printf("%c\n", cantodc);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c                M.E.N.U                %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t Alunos Cadastrados [%3d]       %c\n",lado, totalEstudantes, lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t [1] Incluir Alunos             %c\n",lado,lado);
		printf("%c\t [2] Excluir Alunos             %c\n",lado,lado);
		printf("%c\t [3] Listar Alunos              %c\n",lado,lado);
		printf("%c\t [4] Lancar Nota                %c\n",lado,lado);
		printf("%c\t [5] Sair                       %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t O que deseja fazer?            %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c", cantoeb);
		for(i = 1; i < 40; i++)
		{
			printf("%c", cima);
		}
		printf("%c\n", cantodb);
		gotoxy(9, 14);
		scanf("%d", &opcao);
		
		if (opcao == 1) 
		{
		escolha1();
		}
		limparTela();
		
		if (opcao == 2) 
		{
		escolha2();
		}
		
		if(opcao == 3) 
		{
		escolha3();
		}
		if(opcao == 4) 
		{
		escolha4();
		}
		if (opcao == 5) 
		{
			system("cls");
		}
	}
}

void limparTela() 
{ 
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void escolha1(void){
		opcao = 0;
			auxiliar3:
			system("cls");
			while(submenu != SUBMENU) 
			{
				while(confirm != CONFIRM) 
				{
					limparTela();
					gotoxy(5,5);
					printf("Nome: ");
					fgets(student[totalMatriculas].name, 100, stdin);
					while(error == 0) 
					{
						if (go > 0) {
							printf("%c", cantoec);	         
							for(i = 1; i < 40; i++)
							{
								printf("%c", cima);
							}
							printf("%c\n", cantodc);		
							for(i = 1; i < 16; i++)
							{
								printf("%c\t\t\t\t\t%c\n",lado,lado);
							}
							printf("%c", cantoeb);
							for(i = 1; i < 40; i++)
							{
								printf("%c", cima);
							}
							printf("%c\n", cantodb);
							gotoxy(0,2);
							printf("%c      I N C L U I R   A L U N O S      ", lado);
							gotoxy(5,5);
							printf("Nome: %s", student[totalMatriculas].name);
						}
						gotoxy(5,6);
						printf("Matricula: ");
						scanf("%d", &id);
						if (id != 98) 
						
						{
							if(id > 100)
							{
							gotoxy(5,9);
							printf("Erro! O numero de matriculas ");
							gotoxy(5,10);
							printf("ultrapassou o limite! ");
							gotoxy(5,17);
							system("pause");
							system("cls");
							goto auxiliar3;
							}
							if (totalMatriculas == 0) 
							{
								student[totalMatriculas].mat = id;
								have++;
							} else 
							{
								for(i = 0; i <= totalMatriculas; i++) 
								{
									if(student[i].mat == id) 
									{
										error++;
									}
								}
							}
						} else 
						{
							error = 1;
						}
						if (error > 0) 
						{
							gotoxy(5,14);
							printf("A matricula ja existe!");
							gotoxy(0,17);
							system("pause");
							system("cls");
							error = 0;
							go++;
						} else 
						{
							student[totalMatriculas].mat = id;
							error = 1;
						}
					}
					go = 0;
					error = 0;
					gotoxy(5,7);
					printf("Primeira Nota: ");
					scanf("%f", &student[totalMatriculas].nota1);
					gotoxy(5,8);
					printf("Segunda Nota: ");
					scanf("%f", &student[totalMatriculas].nota2);
					student[totalMatriculas].average = (student[totalMatriculas].nota1 + student[totalMatriculas].nota2) / 2;
					gotoxy(5,9);
					printf("Media: %.2f\n\n", student[totalMatriculas].average);
					gotoxy(5,12);
					printf("[1] Para confirmar"); 
					gotoxy(5,13);
					printf("[2] Para Cancelar");
					gotoxy(5,14);
					scanf("%d", &confirm);
					if (confirm == 2) 
					{
						system("cls");
						if (totalMatriculas == 0) 
						{
							have = 0;
						}
					} else if (confirm == 1) 
					{
						limparTela();
						totalMatriculas++;
						totalEstudantes++;
						system("cls");
						confirm = 2;
					}
				}
				confirm = 0;
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 9; i++)
				{
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      I N C L U I R   A L U N O S      ", lado);
				gotoxy(5,5);
				printf("[1] Incluir Aluno");
				gotoxy(5,6);
				printf("[2] Voltar ao Menu");
				gotoxy(5,7);
				scanf("%d", &submenu);
				if(submenu == 1) 
				{
					submenu = 0;
					system("cls");
				} else if (submenu == 2) 
				{
					submenu = 2;
					system("cls");
				}
			}	
			submenu = 0;

}
void escolha2(void){
	
			opcao = 0;
			system("cls");
			while (submenu != SUBMENU) 
			{
				
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 16; i++)
				{
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      E X C L U I R   A L U N O S      ", lado);
				
				gotoxy(5,4);
				printf("Para excluir um aluno,");
				gotoxy(5,5);
				printf("digite a matricula do mesmo:");
				gotoxy(5,6);
				scanf("%d", &id);
				for(i = 0; i < totalMatriculas; i++) 
				{
					if (student[i].mat == id) 
					{
						aux1++;
						whati = i;
					}
				} 
				if (aux1 == 1) 
				{
					gotoxy(5,8);
					printf("Deseja excluir o aluno %s", student[whati].name); 
					gotoxy(5,9);
					printf("que possui a matricula %d?", student[whati].mat);
					gotoxy(5,11);
					printf("[1] Sim");
					gotoxy(5,12);
					printf("[2] Nao");
					gotoxy(5,13);
					scanf("%d", &SimOuNao);
					if (SimOuNao == 1) 
					{
						if(totalEstudantes == 1) 
						{
							have = 0;
						}
						totalEstudantes--;
						student[whati].average = 2938;
						student[whati].mat = 3847;
						gotoxy(5,14);
						printf("Aluno excluido com sucesso!\n");
						gotoxy(0,17);
						system("pause");
						system("cls");
					} 
					system("cls");
				} else 
				{
					gotoxy(5,14);
					printf("Erro! Essa matricula nao existe!\n");
					gotoxy(0,17);
					system("pause");
					system("cls");
				}
				aux1 = 0;
				SimOuNao = 0;
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 11; i++)
				{
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      E X C L U I R   A L U N O S      ", lado);
				
				gotoxy(5,4);
				printf("Deseja excluir outro aluno ou");
				gotoxy(5,5);
				printf("voltar ao menu principal?");
				gotoxy(5,7);
				printf("[1] Excluir Aluno");
				gotoxy(5,8);
				printf("[2] Menu Principal");
				gotoxy(5,9);
				scanf("%d", &submenu);
				system("cls");
			}
			submenu = 0;
	
}
void escolha3(void){
		opcao = 0;
			system("cls");
			if(have <= 0) 
			{
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 7; i++)
				{
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c     L I S T A   D E   A L U N O S     ", lado);
				gotoxy(3,4);
				printf("Erro!");
				gotoxy(3,5);
				printf("Nao existe nenhum aluno cadastrado!");
				gotoxy(0,8);
				system("pause");
				system("cls");
			} 
			else 
			{
				for(i = 0; i < totalMatriculas; i++)
				{
					for(x = 0; x < totalMatriculas; x++)
					{
						if(student[i].average < student[x].average)
						{
							turma auxiliar =  student[x];
							student[x] = student[i];
							student[i] = auxiliar;
						}			
					}
				}
				j = 0;
				while(list != LIST) 
				{
					while(j <= totalMatriculas) 
					{
						if (student[j].average != 1999 && j != totalMatriculas) 
						{
							
							printf("%c", cantoec);	         
							for(i = 1; i < 40; i++)
							{
								printf("%c", cima);
							}
							printf("%c\n", cantodc);		
							for(i = 1; i < 16; i++)
							{
								printf("%c\t\t\t\t\t%c\n",lado,lado);
							}
							printf("%c", cantoeb);
							for(i = 1; i < 40; i++)
							{
								printf("%c", cima);
							}
							printf("%c\n", cantodb);
							
							gotoxy(0,2);
							printf("%c     L I S T A   D E   A L U N O S     ", lado);
							gotoxy(5,5);
							printf("Nome: %s", student[j].name);
							gotoxy(5,6);
							printf("Primeira nota: %.2f\n", student[j].nota1);
							gotoxy(5,7);
							printf("Segunda nota: %.2f\n", student[j].nota2);
							gotoxy(5,8);
							printf("Matricula: %d\n", student[j].mat);
							gotoxy(5,9);
							printf("Media: %.2f\n\n", student[j].average);
							gotoxy(5,11);
							printf("[1] < Pagina Anterior");
							gotoxy(5,12);
							printf("[2] Menu");
							gotoxy(5,13);
							printf("[3] > Proxima Pagina");
							gotoxy(5,14);
							scanf("%d", &listaOpcao);
						}
						if (j == totalMatriculas) 
						{
							list = 2;
						}
						if (listaOpcao == 1 && j > 0) 
						{
							j--;
						} else if (listaOpcao == 2) 
						{
							j = totalMatriculas + 1;
							list = 2;
						} else if (listaOpcao == 3 && j < totalMatriculas) 
						{
							j++;	
						} else if (listaOpcao == 3 && j == totalMatriculas) 
						{
							j = totalMatriculas + 1;
							list = 2;
							gotoxy(0,17);
							system("pause");
						}
						if (j != totalMatriculas) 
						{
							system("cls");
						}
					}
					system("cls");
				}
				list = 0;
				j = 0;
			}
	
	
}
void escolha4(void){
		opcao = 0;
			system("cls");
			while (submenu != SUBMENU) 
			{
				
				printf("%c", cantoec);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 16; i++)
				{
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++)
				{
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c         L A N C A   N O T A          ", lado);
				gotoxy(5,5);
				printf("Para lancar a nota do aluno,");
				gotoxy(5,6);
				printf("digite a matricula do mesmo:");
				gotoxy(5,7);
				printf("[101] Sair");
				gotoxy(5,8);
				scanf("%d", &id);
				if (id != 101) 
				{
					aux1 = 0;
					for (i = 0; i <= totalMatriculas; i++) 
					{
						if (student[i].mat == id) 
						{
							aux1++;
							whati = i;
						}
					} 
					
					if (aux1 == 1) 
					{
						gotoxy(5,10);
						printf("Digite a primeira nota: ");
						scanf("%f", &student[whati].nota1);
						gotoxy(5,11);
						printf("Digite a segunda nota: ");
						scanf("%f", &student[whati].nota2);
						student[whati].average = (student [whati].nota1 + student[whati].nota2) / 2;
						gotoxy(5,12);
						printf("Media: %.2f\n", student[whati].average);
						gotoxy(0,17);
						system("pause");
						system("cls");
						submenu = 2;
					} else 
					{
						gotoxy(5,14);
						printf("Erro! Essa matricula nao existe!\n");
						gotoxy(0,17);
						system("pause");
						system("cls");
					}
					aux1 = 0;
				} else 
				{
					submenu = 2;
					system("cls");
				}
			}
			submenu = 0;
}
