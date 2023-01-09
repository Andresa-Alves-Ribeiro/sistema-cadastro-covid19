#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}rgData;

rgData entrada(char msg[]){
    rgData dt;

    printf("%s Exemplo: (dd/mm/aaaa): ",msg);
    scanf ("%d/%d/%d", &dt.dia,&dt.mes, &dt.ano);

    return(dt);

}

int main (int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    system("color 0A");
    printf("\n\t\t\t\t\t ***** BEM VINDO(A)!! ***** \n\n ");
    system("pause");
    system("cls");
    menu_inicial();


    system("pause");
    return 0;
}


void menu_inicial()
{
    printf("\n\t\t\t\t**************  SISTEMA BÁSICO DE SAÚDE  ***********************");
    printf("\n\t\t\t\t****************   1- Login     ***************************");
    printf("\n\t\t\t\t****************   2- Sair      ***************************");
    char op = NULL;
    printf("\n\n\t\t\t\t\t DIGITE A OPÇÃO: ");
    scanf("%s",&op);

    if(op == '1')
        {
          login();
        }else if(op == '2')
             {
               sair();
             }else
                 {
                    op = NULL;
                    system("color 0C");
                    printf("\n\t\t\t\t\t\t Opção não encontrada. Tente novamente!\n\n\n");
                    system("pause");
                    system ("color 0A");
                    system("cls");
                    menu_inicial();
                 }
}

void login()
    {
        char login[10] = "admin";
        char digUser[10];
        int  senha = 1234;
        int digSenha;


        system("cls");
        printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n\n");
        printf("\t\t\t\tUSER: ");
        scanf("%s", &digUser);

        printf("\n\t\t\t\tSENHA: ");
        scanf("%i", &digSenha);

        while (strcmp(digUser,login) || digSenha != senha)
               {
                    system("cls");
                    system("color 0C");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n");
                    printf("\nDados Incorretos! Tente novamente \n");
                    system("pause");

                    system("cls");
                    system("color 0A");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n");
                    printf("\t\t\t\tUSER: ");
                    scanf("%s", &digUser);

                    system("cls");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n");
                    printf("\t\t\t\tSENHA: ");
                    scanf("%i", &digSenha);
               }

        menu_principal();

    }


        void menu_principal()
        {
         system("cls");
         char op = NULL;

    printf("\n\t\t\t\t**************  SISTEMA UNIP SAÚDE  ***********************");
    printf("\n\t\t\t\t***********   1- Consultar Paciente   *********************");
    printf("\n\t\t\t\t***********   2- Cadastrar Paciente   *********************");
    printf("\n\t\t\t\t***********   3- Encerrar Sessão      *********************");
    printf("\n\t\t\t\t***********   4- Sair                 *********************");

    printf("\n\n\t\t\t\t\t DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s",&op);
    switch(op)
        {
            case '1':
                op = NULL;
                consulta();
                break;
            case '2':
                op = NULL;
                cadastro();
                break;

            case '3':
                op = NULL;
                login();
                break;

            case '4':
                op = NULL;
                sair();
                break;

            default:
                op = NULL;
                system("color 0C");
                printf("\n\t\t\t\t\t\t Opção não encontrada. Tente novamente!\n\n\n");
                system("pause");
                system ("color 0A");
                system("cls");

                 menu_principal();
                break;
        }

        }

void cadastro()
    {
        novoPaciente();
        menu_principal();
    }


    void novoPaciente()
        {
            system("cls");
            printf("\n\t\t\t\t CADASTRO DE PACIENTES \n\n\n");
            char filename[100], nome[50]="", sobrenome[100]="", cpf[30], telefone[11], email[50];

            char endereco[100], numero[10], complemento[100], bairro[100], cidade[100], estado[2], pais[50], cep[8];

            char comorbidade[100];
            int  comorbi_booleano;
            rgData nasc,dataAtual;

            printf("\t\t\t ****PREENCHA A FICHA**** \n\n\n");
            printf("\n\tDigite a data de hoje\n");
            dataAtual = entrada("       ");

            printf("\n\tPrimeiro nome: ");
            scanf("%s",nome);

            printf("\n\tÚltimo Sobrenome: ");
            scanf("%s",sobrenome);

            printf("\n\tData de Nascimento: \n\t");
            nasc = entrada("Nascimento");
            int idade = dataAtual.ano - nasc.ano;

            printf("\n\tTelefone com DDD *SOMENTE NÚMEROS*: ");
            scanf("%s",telefone);

            printf("\n\tEmail: ");
            scanf("%s",email);

            FILE *file;
            sprintf(filename,"%s_%s.txt",nome, sobrenome);
            file = fopen(filename,"w");

            fprintf(file,"\n Data do Diagnóstico: %d/%d/%d \n\t\t\t",dataAtual.dia,dataAtual.mes,dataAtual.ano);

            fprintf(file,"\n Nome: %s ",nome);

            fprintf(file,"%s \n",sobrenome);

            fprintf(file," Idade: %i anos \n",idade);

            fprintf(file," Telefone: +55 %s \n",telefone);

            fprintf(file," Email: %s \n",email);

            printf("\n\tCPF: ");

            scanf("%s",cpf);

            fprintf(file," CPF: %s \n \n",cpf);

            fprintf(file,"");

            system("cls");

            printf("\n\t\t\t****Endereço**** \n\n");

            printf(" \n\tEndereço: ");

            fflush(stdin);

            fgets(endereco,100,stdin);

            fflush(stdin);

            fprintf(file," Endereço: %s",endereco);

            printf("\n\tNúmero: ");

            scanf("%s",numero);

            fprintf(file," Número: %s",numero);

            printf("\n\tComplemento (CASO NÃO TENHA DIGITE 0): ");

            fflush(stdin);

            fgets(complemento,100,stdin);

            fflush(stdin);

            fprintf(file," Complemento: %s",complemento);

            printf(" \n\tBairro: ");

            fflush(stdin);

            fgets(bairro,100,stdin);

            fflush(stdin);

            fprintf(file," Bairro: %s",bairro);

            printf("\n\tCidade: ");

            fflush(stdin);

            fgets(cidade,100,stdin);

            fflush(stdin);

            fprintf(file," Cidade: %s",cidade);

            printf("\n\tEstado *Ex: SP*: ");

            fflush(stdin);

            fgets(estado,50,stdin);

            fflush(stdin);

            fprintf(file," Estado: %s",estado);

            printf("\n\tPaís: ");

            fflush(stdin);

            fgets(pais,100,stdin);

            fflush(stdin);

            fprintf(file," País: %s",pais);

            printf("\n\tCEP: ");

            fflush(stdin);

            fgets(cep,100,stdin);

            fflush(stdin);

            fprintf(file," CEP: %s",cep);

            do{
            system("cls");
            printf("\n\tO paciente possui algum tipo de comorbidade? \n\t\t[1]SIM\t [2]NÃO \n");
            scanf("%i", & comorbi_booleano);
            }while(comorbi_booleano <= 0 || comorbi_booleano > 2);

            if(comorbi_booleano == 1){
                printf("\n\tQual comorbidade o paciente possui: ");
                fflush(stdin);
                fgets(comorbidade,100,stdin);
                fflush(stdin);
                fprintf(file," Comorbidades: %s",comorbidade);
                printf("\n Cadastro concluído com sucesso! \n ");
                fclose(file);
            }

            if(comorbi_booleano == 2){
                system("cls");
                printf("\tCadastro concluído com sucesso!");
                system("pause");
            }

            if(comorbi_booleano == 1 || idade >= 65)
              {
                  FILE *file;
                  sprintf(filename,"RISCO_%s_%s.txt",nome, sobrenome);
                  file = fopen(filename,"w");
                  fprintf(file,"\n Nome: %s ",nome);
                  fprintf(file,"%s \n",sobrenome);
                  fprintf(file," Idade: %i anos \n",idade);
                  fprintf(file," CEP: %s",cep);
                  fprintf(file," Comorbidades: %s",comorbidade);
                  fclose(file);
              }

           system("cls");
           printf("\n Cadastro concluído com sucesso! \n ");

        }



        void consulta()
                {
                       system("cls");
                        char nome[100];
                        char sobrenome[100];
                        char filename[100];

                          printf("\n\t\t\t *********  CONSULTA CADASTRO DOS PACIENTES  *************** \n");

                          printf("\n\t\t\t Nome do paciente: ");
                          scanf("%s",nome);
                          printf("\n\t\t\t Último sobrenome do paciente: ");
                          scanf("%s",sobrenome);

                          FILE *file;
                          sprintf(filename,"%s_%s.txt",nome, sobrenome);
                          file = fopen(filename,"r");
                          if(file == NULL)
                            {
                             system("cls");
                             system("color 0C");
                             printf("\n ERRO! Paciente não encontrado! \n ");
                             printf("\n Verifique se o nome do paciente está correto e tente novamente! \n");
                             system("pause");
                             system ("color 0A");
                             menu_principal();
                            }

                          char frase[100];
                          system("cls");
                          printf("\n\t\t\t *********  CONSULTA CADASTRO DOS PACIENTES  *************** \n");

                          while(fgets(frase,100,file) != NULL)
                               {
                                    printf("%s",frase);

                              }

                          fclose(file);
                          printf("\n\t\t\t Aperte ENTER para voltar ao menu. \n\n\n");
                          system("pause");
                          menu_principal();

                }

void sair()
    {
        system("exit");
    }
