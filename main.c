#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sair = 0; // Controle global menu principal 

void funcap (){
    //Edrey esteve aqui :)
    //Função para pegar os valores das teclas
}

void criarBaseDados(){

}

//Funções Módulo 1 -  Contas
int CPaddCont (int valorConta, int venc, char nomeConta[100]){
    printf("\n CPaddCont \n");
    return 0;
}

int CPeditCont (int idconta, int valorConta, char nomeConta[100], int venc){
    printf("\n CPeditCont \n");
    return 0;
}

int CPremoveCont (int idconta){
    printf("\n CPremoveCont \n");
    return 0;
}

void CPlistCont (int idConta){
    printf("\n CPlistCont \n");
}

// Funções Módulo 2 - Orçamento Mensal
void OMaddRenda(float valor, char origemRenda[100], int dataEntrada){
    printf("\nQMaddRenda\n");
}

int OMeditRenda(int idRenda, float valor, char origemRenda[100], int dataEntrada){
    printf("\nQMediteRenda\n");
    return 0;
}

int OMremove(int idRenda){
    printf("\nQMRemove\n");
    return 0;
}

void OMorcamentoTotal (int idRenda){
    printf("\nQMOrçamentoMensal\n");
}

//Funções Módulo 3 - Cofrinho
int COaddFundos (float guardarValor){
    printf("\nCOaddFundos\n");
    return 0;
}

int COremoveFundos (float removeValor){
    printf("\nCOremoverFundos\n");
    return 0;
}

float COrendFundos (int qtdMeses, float valorMes){
    printf("\nCOrendFundos\n");
    return 0;
}
float COsaldo(){
    printf("\nCOsaldo\n");
    return 0;
}

//Menu Principal
void menuPrincipal (){
    int MPcontrolMenu = 0; //Controle menu principal
    int CPcontrolMenu = 0; //Controle menu Contas a Pagar
    int OMcontrolMenu = 0; //Controle menu Orçamento mensal
    int COcontrolMenu = 0; //Controle menu Cofrinho
    
    do{
        printf("\nMenu principal\n");
        printf("\n1- Orçamento Mensal\n2- Contas a pagar\n3- Cofrinho\n0- Fechar a Aplicação\n");
        printf("\nSelecione a sua opção: ");
        scanf("%i", &MPcontrolMenu);
        
        //Menu Principal
        switch (MPcontrolMenu){
            
            //Fechar aplicativo
            case 0:
                printf("\nFechando a aplicação...\n");
                sair = 1;
                break;
            
            // Menu Orçamento Mensal
            case 1:     
                do{
                    printf("\nOrçamento Mensal\n");    
                    printf("\n1- Adicionar Renda\n2- Editar Renda \n3- Remover Renda\n4- Listar Renda\n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &OMcontrolMenu);
                    
                    switch(OMcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            OMaddRenda(2,"renda",12);
                            break;
                        case 2:
                            OMeditRenda(2,4,"reda",23);
                            break;
                        case 3:
                            OMremove(2);
                            break;
                        case 4:
                            OMorcamentoTotal(4);
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(OMcontrolMenu != 0);
                break;
            
            //Menu Contas a Pagar
            case 2:
                do{
                    printf("\nContas a Pagar\n");    
                    printf("\n1- Adicionar Conta\n2- Listar Contas \n3- Editar Contas\n4- Remover Contas\n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &CPcontrolMenu);
                    
                    switch(CPcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            CPaddCont (1000, 10, "Cartão de Credito");
                            break;
                        case 2:
                            CPlistCont (5);
                            break;
                        case 3:
                            CPeditCont (5, 500, "Coca-Cola", 6);
                            break;
                        case 4:
                            CPremoveCont (5);
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(CPcontrolMenu != 0);
                break;
            
            //Menu cofrinho 
            case 3:
                do{
                     printf("\nCofrinho\n");   
                    printf("\n1- Adicionar Fundos\n2- Remover Fundos\n3- Saldo\n4- Pespectiva de economia \n0- Voltar para o menu principal\n");
                    printf("\nSelecione a sua opção: ");
                    scanf("%i", &COcontrolMenu);
                    
                    switch(COcontrolMenu){
                        case 0:
                            menuPrincipal ();
                            break;
                        case 1:
                            COaddFundos(12);
                            break;
                        case 2:
                            COremoveFundos(1);
                            break;
                        case 3:
                            COsaldo();
                            break;
                        case 4:
                            COrendFundos(2,34);
                            break;
                        default:    
                            printf("\nOpção Inválida.\n");
                            break;
                        }

                }while(COcontrolMenu != 0);
                break;
            
            //Opção invalida 
            default:
                printf("\nOpção inválida! Tente novamente...\n");
                break;
        }
    } while (sair != 1);
}

int main (){
    setlocale(LC_ALL, "Portuguese");
    void menuPrincipal ();
    
    do{
        menuPrincipal ();
    }while(sair != 1);
        
    return 0;
}