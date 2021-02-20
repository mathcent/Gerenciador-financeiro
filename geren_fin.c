#include <stdlib.h>
#include <stdio.h>
#define MAX 50

struct Data{
    int dia;
    int mes;
    int ano;
}Data;

struct Receita{
    struct Data data;
    float valor;
    int tipo;
}Receita;

struct Data criaData(int dia, int mes, int ano){
    struct Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}



//Nelson eh um amigo q ajudou no projeto :3
struct Nelson{
    struct Receita receitas[MAX];
    int n;
};

int menu(){

    puts("=======================================");
    puts("1 - Insere   ");
    puts("2 - Insere valor com parcelas");
    puts("3 - Relatorio especifo ");
    puts("4 - Relatorio ultimos 12 meses ");
    puts("5 - Porcentagem dos gastos");
    puts("6 - Previsao de gastos proximo mes ");
    puts("0 - Sai!    ");
    printf("opcao> ");
    int op;
    scanf("%d", &op);

    return op;

	
}
void cadastra(struct Nelson *j){
	printf("Valor: ");
	scanf("%f",&j->receitas[j->n].valor);
    printf("Tipo:(1-Moradia, 2-Estudos, 3-Transporte, 4-Alimentacao, 5-Trabalho) ");
    scanf("%d",&j->receitas[j->n].tipo);
    printf("Data:(dd/mm/aaaa) ");
    int d=0;
    int m=0;
    int a=0;
    scanf("%d",&d);
    scanf("%d",&m);
    scanf("%d",&a);
    j->receitas[j->n].data=criaData(d,m,a);
    j->n++;	
}

int conferi(struct Nelson j,int d, int m , int a,int i,int op){
    int A = j.receitas[i].data.ano;
    int M = j.receitas[i].data.mes;
    int D = j.receitas[i].data.dia;
    if (op==0){
       if ((a-A==1 && (m<M ||(m==M && d<=D)) ) || (a-A==0 && (m>M ||(m==M && d>=D))) ){
            return 0;      
       }
       else{
            return 1;
       }
    }else{
        if ( (a-A==0 && ((m-M==0 && d-D>=0) || (m-M==1 && d-D<=0)) ) ){        
            return 0;       
        }else{
            return 1;
        }        
    } 
};

void imprime12(struct Nelson j){
    int d=0;
    int m=0;
    int a=0;
    printf("Apartir de que dia? :");
    scanf("%d",&d);
    printf("\nEm qual mes? :");
    scanf("%d",&m);
    printf("\nEm qual ano? :");
    scanf("%d",&a);
    int i;
    int op=0;
	for (i = 0; i < j.n; i++){
        puts("_________");
        if(conferi(j,d,m,a,i,op)==0){
            if(j.receitas[i].tipo==1){
                printf(" Moradia: \n");
            }else if(j.receitas[i].tipo==2){
                printf(" Estudos: \n");
            }else if(j.receitas[i].tipo==3){
                printf(" Transporte: \n");
            }else if(j.receitas[i].tipo==4){
                printf(" Alimentacao: \n");
            }else if(j.receitas[i].tipo==5){
                printf(" Trabalho: \n");
            }
            printf(" Valor: %.2f \n",j.receitas[i].valor);
            printf(" Data: %d/%d/%d \n",j.receitas[i].data.dia,j.receitas[i].data.mes,j.receitas[i].data.ano);
            puts("_________");
        }        
    }    
}

void imprime1(struct Nelson j){
    int d=0;
    int m=0;
    int a=0;
    printf("Apartir de que dia? :");
    scanf("%d",&d);
    printf("\nEm qual mes? :");
    scanf("%d",&m);
    printf("\nEm qual ano? :");
    scanf("%d",&a);
    int i;
    int op=1;
	for (i = 0; i < j.n; i++){
        puts("_________");
        if(conferi(j,d,m,a,i,op)==0){
            if(j.receitas[i].tipo==1){
                printf("Moradia:\n");
            }else if(j.receitas[i].tipo==2){
                printf("Estudos:\n");
            }else if(j.receitas[i].tipo==3){
                printf("Transporte:\n");
            }else if(j.receitas[i].tipo==4){
                printf("Alimentacao:\n");
            }else if(j.receitas[i].tipo==5){
                printf("Trabalho:\n");
            }
            printf(" Valor: %.2f\n",j.receitas[i].valor);
            printf(" Data: %d/%d/%d\n",j.receitas[i].data.dia,j.receitas[i].data.mes,j.receitas[i].data.ano);
            puts("_________");
        }        
    }
}

float calc(float valor, float v){
    return (v*100)/valor;
}

void porcent(struct Nelson j){
    float Vm=0;
    float Ve=0;
    float Vb=0;
    float Va=0;
    float Vt=0;
    float valor=0;
    int i;
    for ( i = 0; i < j.n ; i++){
        if(j.receitas[i].tipo==1){
            Vm+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==2){
            Ve+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==3){
            Vb+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==4){
            Va+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==5){
            Vt+=j.receitas[i].valor;
        }
        valor+=j.receitas[i].valor;

    }
    
    printf("Moradia: %f\n",calc(valor,Vm));
    printf("Estudos: %f\n",calc(valor,Ve));
    printf("Transport: %f\n",calc(valor,Vb));
    printf("Alimentacao: %f\n",calc(valor,Va));
    printf("Trabalho: %f\n",calc(valor,Vt));
};

void parcela(struct Nelson *j){
    int parc=0;
    int d=0;
    int m=0;
    int a=0;
    int i;
    int tipo=0;
    float valor=0; 
    printf("Quantas parcelas? ");
    scanf("%d",&parc);
    printf("Valor Total: ");
	scanf("%f",&valor);
    printf("Tipo:(1-Moradia, 2-Estudos, 3-Transporte, 4-Alimentacao, 5-Trabalho) ");
    scanf("%d",&tipo);
    printf("Data da primera parcela:(dd/mm/aaaa) ");
    scanf("%d",&d);
    scanf("%d",&m);
    scanf("%d",&a);
    float valorP=valor/parc;
    for (i = 0; i < parc; i++){
        j->receitas[j->n].valor=valorP;
        j->receitas[j->n].tipo=tipo;
        if (i==0){
            j->receitas[j->n].data=criaData(d,m,a);

        }else{
            if (m==12){
                j->receitas[j->n].data=criaData(d,1,a+1);
                m=1;
                a+=1;
            }else{
                j->receitas[j->n].data=criaData(d,m+1,a);
                m+=1;
            }  
        }
       j->n++; 
    }
}



int main()
{
	struct Nelson j;
	j.n = 0;
	
    while(1){
        int op = menu();
        if(op == 1){
            cadastra(&j);
        }else if(op == 4){
            imprime12(j);
        }else if(op == 3){
            imprime1(j);
        }else if(op == 5){
            porcent(j);
        }else if(op == 2){
            parcela(&j);            
        }else if(op == 6){
            printf("\n...\n");            
        }else {
            break;
        }
    }
   
 
  return 0;
}
