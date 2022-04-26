/*							        	PROJETO 1( individual )
		Tarefa   : Connect4 game
		Elemento : Saturnino Moreira Mendes nº 10937
		Prazo	 : 10/04/2022, 23:59	
												*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <locale.h>
#include <stdbool.h>         


char tabuleiro [6][7];
char winner,game='X',player1[30],player2[30];
int contX = 0 , contO=0,contPART=0,contEMPAT=0 ,idade1,idade2,  total=0 ,achou1,achou2; 
bool estar1=false , estar2 = false; 

int n1[100],n2[100], ida[100],n3[100];
char dav,dav2,name[50][100], aux[50];
void Help();
void INTRO();
void menu();
void venceu();
void start_game();
void choose_first(){
	   	
		
}
void start_game(){
 int l,m;
	
	for(l = 0; l <6 ; l++){
		for(m = 0; m <7 ; m++){
			tabuleiro[l][m]= ' ';
		}
	}	
	
}

void show_tab(){
int i,j;
	system("cls");
	printf("\n  ============ > CONNECT 4 < ============\n");
    printf("  %s joga com => X\n  %s joga com => O",player1,player2); 
		if(game=='X'){
			printf("\n\n  === =Vez de [ %s ] jogar= ====\n",player1);
		}else{
			printf("\n\n  === =Vez de [ %s ] jogar= ====\n",player2);	
		}
   		
   printf("\033[0;35m  PONTOS  \n  %s	-> %i   \n  %s	-> %i   \033[0m",player1,contX,player2,contO);
   
		
	printf("\n\n\n\n\t");
	for(i = 0; i <6 ; i++){
		for(j = 0; j <7 ; j++){ 	   
		printf("|");	
			  	if(tabuleiro[i][j]=='X'){
				printf("\033[0;31m");
				printf(" %c ",tabuleiro[i][j]);
				printf("\033[0m");	
			}else{
				printf("\033[0;33m");
				printf(" %c ",tabuleiro[i][j]);
				printf("\033[0m");
			}		   
						   
		}	printf("|\n\t");
	}printf("+---+---+---+---+---+---+---+\n");
	
	
}

void certify_winner(){
int i,j,encher = 0;	
	
	for(i = 0; i < 6; i++){
		for(j = 0; j < 7; j++){   ////   Linha 1
	
			if(tabuleiro[i][j]=='X' && tabuleiro[i-1][j]=='X' && tabuleiro[i-2][j]=='X' && tabuleiro[i-3][j]=='X'){
				    contX++;
					venceu();						 
					
			}else if(tabuleiro[i][j]=='O' && tabuleiro[i-1][j]=='O' && tabuleiro[i-2][j]=='O' && tabuleiro[i-3][j]=='O'){
					contO++;
					venceu();
					
			}else if(tabuleiro[i][j]=='X' && tabuleiro[i][j-1]=='X' && tabuleiro[i][j-2]=='X' && tabuleiro[i][j-3]=='X'){
					contX++;
					venceu();
					
			}else if(tabuleiro[i][j]=='O' && tabuleiro[i][j-1]=='O' && tabuleiro[i][j-2]=='O' && tabuleiro[i][j-3]=='O'){
					contO++;
					venceu();
					
			}else if(tabuleiro[i][j]=='O' && tabuleiro[i+1][j+1]=='O' && tabuleiro[i+2][j+2]=='O' && tabuleiro[i+3][j+3]=='O' ){
				    contO++;
					venceu();
					
			}else if(tabuleiro[i][j]=='X' && tabuleiro[i+1][j+1]=='X' && tabuleiro[i+2][j+2]=='X' && tabuleiro[i+3][j+3]=='X' ){
				    contX++;
					venceu();
			//		
			}else if(tabuleiro[i][j]=='O' && tabuleiro[i+1][j-1]=='O' && tabuleiro[i+2][j-2]=='O' && tabuleiro[i+3][j-3]=='O' ){
				    contO++;
					venceu();
					
			}else if(tabuleiro[i][j]=='X' && tabuleiro[i+1][j-1]=='X' && tabuleiro[i+2][j-2]=='X' && tabuleiro[i+3][j-3]=='X' ){
				    contX++;
					venceu();
					
			} 
			int op; 
			if(tabuleiro[i][j] != ' '){    // Caso todo tabuleiro estiver todo preenchido e não houve vitoria declarar EMPATE 
				encher++;			
				if(encher == 42){	
						contEMPAT++;
						printf("\n\n\a Houve um empate!\n\n");
						printf("\n\t1-Desempatar o Jogo\n\t2-Voltar ao menu\n\t--> ");
							scanf("%d",&op);
							switch(op){
								case 1: 
								INTRO();	
									break;
								case 2:		
								menu();	
									break;
								default:
								    fflush(stdin); 
									system("cls");  
									printf("\n\tOpção inválida\n");
									system("pause");	
									break;
							}
                }	
		    }
    	}
	}
	
}

void venceu(){
	contPART++;
	int op;
	if(game=='O'){
		show_tab();
		printf("\n\n\a [ %s ] Ganhooouuu!\n\n",player1);
		printf("\n\t1-Novamente\n\t2-Voltar ao menu\n\t--> ");
			scanf("%d",&op);
			switch(op){
				case 1: 
				             // Faz com que quem vencer seja o primeiro a jogar
						 game='X';
					 		
				INTRO();	
					break;
				case 2:	
					
				menu();	
					break;
				default:
				    fflush(stdin);
				   
					printf("\n\tOpção inválida\n");
					system("pause");
					system("cls");
					venceu();	
					break;
			}	
	}else{
		show_tab();
	    
		printf("\n\n\a [ %s ] Ganhooouuu!\n\n",player2);
		printf("\n\t1-Novamente\n\t2-Voltar ao menu\n\t--> ");
			scanf("%d",&op);
			switch(op){
			case 1:
				
			   game='O';           // Faz com que quem vencer seja o primeiro a jogar
					
			INTRO();	
				break;
			case 2:	
				
			menu();	
				break;
			default:
			    fflush(stdin);
				printf("\n\tOpção inválida\n");
				system("pause");
				system("cls");
				venceu();	
				break;
			}
	}

	
}


void play(){
	 int i,tipo; 
	 
	printf("\n   Escolha um lugar de [1-7] para jogar: ");
	scanf("%d", &tipo);
	fflush(stdin);		// Limpar espaço na memória caso degitem um caractere não interrompa o jogo

			if((tipo>=1)&&(tipo<8)){	
				for(i = 6; i >= 0; i--){		
					if(tabuleiro[i][tipo-1]==' '){
						tabuleiro[i][tipo-1] = game;			
						break;
					}else if(tabuleiro[0][tipo-1] != ' '){ 
						printf("\n\tJogada invalida, {tabuleiro na posição %d está cheio} \n",tipo);
						system("pause");
							if(game=='X'){	//Dar chance ao jogador que fez jogada invalida a voltar a jogar numa opcao válida
								game='O';
							}else{
								game='X';
							}
						break;
					}
				}
			}else{
				printf("\n\tJogada invalida! {tende numero de 1-7}\n\n");
				system("pause");
				//system("cls");
				//menu();
					if(game=='X'){
						game='O';
					}else{
						game='X';
					}	
			}
}


void INTRO(){
	//	system("color 70");
	
	int stop=0,a=3;//,i=0,nada=0,aux;  char vencedor,op;	
	start_game();
	
		do{		
			a++;
			system("cls"); //system("clear");
			stop++;
			show_tab();
			
			play();
		 		if(game=='X'){
					 game='O';
				 }else{
					 game='X';
				 }
			show_tab();
		certify_winner();
		}while(stop< a);
	
}

void registrar(){   
system("cls");	

int i,opt;

			printf("Player#1: ");
				scanf("%s", player1); 
			printf("Idade: ");
				scanf("%d", &idade1);
				
					  	for( i = 0; i < total; i++){
							if((strcmp(name[i],player1)==0)){
								achou1 = i;
								estar1 = true;
								//break;			printf("\n\nOKAAAAAAAAAYYYyyy\n\n");exit(0);
							}	
						}
			if( estar1 == true){
				printf("\t    ATENÇÃO!! já existe esse nome no nosso banco de dados!\n"
				"\n  (*) Se nao for voce, aperte a tecla ['1'] para escolher um novo nome "
				"\n  (*) Se for voce, aperte ['QUAQUER TECLA'] para continuar\n--> ");
					scanf("%d",&opt);
					fflush(stdin);
					switch(opt){
					case 1:		registrar();	break;	// Se não for ele q já jogou antes, pode escrever um novo nome diferente
					default:					break;
						
					}
			}										
			printf("\nPlayer#2: ");
				scanf("%s", player2);
			printf("Idade: ");
			    scanf("%d",&idade2);		
	  			for( i = 0; i < total; i++){
							if((strcmp(name[i],player2)==0)){
								achou2 = i;
								estar2 = true;
								//break;			
							}	
					}
			if(estar2 == true){ 									// Caso nome do jogador2 tenha existido no ficheiro
				printf("\t    ATENÇÃO!! já existe esse nome no nosso banco de dados."
				"\n  (*) Se nao for voce, aperte a tecla ['1'] para escolher um novo nome "
				"\n  (*) Se for voce, aperte ['QUAQUER TECLA'] para continuar\n--> ");
					scanf("%d",&opt);
					fflush(stdin);
					switch(opt){
					case 1:
						registrar();	// Se não for ele q já jogou antes, pode escrever um novo nome diferente
						break;
					default:
						break;
					}
			}		    
		
system("pause");
INTRO();
}



void sair(){
	system("cls");
	if(player1[0] == '\0'){                               // Caso nao tenha jogado ainda 
		printf("\n\n\n\t\tNada registrado!...\n\n");     //  vai sair do jogo sem guadar nada
		exit(0);										//   e poupar execução de codigo desnecessariamente
	}
	
FILE *p,*a,*X_O;
int i;
																		
	if(estar1==false && estar2 == true){ 					             // Caso apenas o jogador2 já tinha jogado 									
			p = fopen("DATABASE\\game_DB.txt","w");					
				n1[achou2] += contO; n2[achou2] += contPART; n3[achou2]+=contEMPAT; //Somar novos pontos com os anteriores
				for(i = 0; i < total; i++){
					fprintf(p,"%s\t%d\t%d\t%d\n",name[i],n1[i],n2[i],n3[i]);	 	
				} 
				fprintf(p,"%s\t%d\t%d\t%d\n",player1,contX,contPART,contEMPAT);// E adicionar os dados do jogador1
		              
	    fclose(p); 
	    a = fopen("DATABASE\\AGES.txt","a");   // Guardar as idades em um ficheiro separado
		  	fprintf(a,"%d\n",idade1);		   
	    fclose(a);	
		
		X_O = fopen("DATABASE\\jogo-tipo.txt","a");	// Guardar a jogada de cada jogador  	
				fprintf(X_O,"X\n");
		fclose(X_O);  
	
	
	}else if(estar1 == true && estar2 == false){
		   	n1[achou1] += contX; n2[achou1] += contPART; n3[achou1]+=contEMPAT;
			p = fopen("DATABASE\\game_DB.txt","w"); 
				for(i = 0; i < total; i++){
					fprintf(p,"%s\t%d\t%d\t%d\n",name[i],n1[i],n2[i],n3[i]);
				} 
		  	fprintf(p,"%s\t%d\t%d\t%d\n",player2,contO,contPART,contPART); 
		  	
	    fclose(p); 
	    a = fopen("DATABASE\\AGES.txt","a"); 
		  	fprintf(a,"%d\n",idade2);
	    fclose(a);	
		
		X_O = fopen("DATABASE\\jogo-tipo.txt","a");		
				fprintf(X_O,"O\n");
		fclose(X_O);  
	
		
	}
	else if(estar1 == true && estar2 == true){   // Caso os dois jogadores já tiveram jogados antes 
		n1[achou1] += contX, n2[achou1] += contPART, n3[achou1]+=contEMPAT; // Somar os dados de vitoria,jogadas e empates
		n1[achou2] += contO; n2[achou2] += contPART; n3[achou2]+=contEMPAT; // com os atuias e limpar imprimí-los no ficheiro
			p = fopen("DATABASE\\game_DB.txt","w"); 						// 
				for(i = 0; i < total; i++){
					fprintf(p,"%s\t%d\t%d\t%d\n",name[i],n1[i],n2[i],n3[i]);
				} 
	       fclose(p);
		
		
	}else if (estar1 == false && estar2 == false){	  // Caso nenhum dos jogadores tinham jogado antes
		p = fopen("DATABASE\\game_DB.txt","a"); 
			fprintf(p,"%s\t%d\t%d\t%d\n%s\t%d\t%d\t%d\n",player1,contX,contPART,contEMPAT,player2,contO,contPART,contEMPAT);
													// Só acrescentar os seus dados aos outros já registrados sem mexer
	    fclose(p); 
	    a = fopen("DATABASE\\AGES.txt","a"); 
		  	fprintf(a,"%d\n",idade1);
		  	fprintf(a,"%d\n",idade2);
	    fclose(a);	
		
		X_O = fopen("DATABASE\\jogo-tipo.txt","a");		
				fprintf(X_O,"X\nO\n");
		fclose(X_O);  
	}																				
 
	printf("\n\n\n\t\tDados guardado com sucesso!...\n\n");
	exit(0);
		
}



void score(){	
int aux1,aux2,aux3,r,s, j, aux4;	    	    
    float res[100];	    
    for(j=0;j<total;j++){		// Aqui é onde relaciono numero de vitorias com as partidas para ter um ranking
		res[j] = n2[j] - n1[j];
	}	    
     /***************  Processo de Ordenação de acordo com pontuações no jogo  **************************/                   
		for(r = 0; r < total; r++){
			for(s = r; s < total; s++){
				if(res[r]<res[s]){
					strcpy(aux, name[r]);
					aux1 	= ida[r];				
					aux2  	= n1[r];
					aux3    = n2[r];
					aux4    = n3[r];
					strcpy(name[r], name[s]); 
					ida[r]	= ida[s];      
					n1[r]	= n1[s];       
					n2[r]	= n2[s];
					n3[r]	= n3[s];
					strcpy(name[s],aux);
					ida[s]	= aux1;
					n1[s]	= aux2;
					n2[s]	= aux3;
					n3[s]	= aux4;	
				}		
			}
		}	
    printf("\n\t=================  MELHORES CLASSIFICAÇÕES  =======================\n");
		//  **************** Aqui vai mostrar os dados na tela já devidamente ordenados ***************8		 
	printf("\t+------------------------+---------+----------+----------+");    	
    printf("\n\t| NOMES  	 	 |  Idade  | Vitórias | Jogadas  |\n"); 
    printf("\t+------------------------+---------+----------+----------+");		        
    for(j = 0; j < total; j++){
    	    printf("\n\t|%s		  	 |    %2d   |    %2d    |    %2d    |",name[j],ida[j],n1[j],n2[j]);
    	    printf("\n\t+------------------------+---------+----------+----------+");
    	    if(j>8){
				break;
			}
	}	printf("\n\n\n");		
system("pause");
system("cls");
menu();			
}


void estatistica(){
	system("cls");
	
	int   empCRI=0,empADOL=0,empADU=0,empJOV=0,empOUTR=0,   empGERAL=0;		// variáveis para contar EMPATES
	float winJOV=0,winCRI=0,winADOL=0,winADU=0,winOUTR=0,   winGERAL=0;		// variáveis para contar VITORIAS
	float roundCRI=0,roundADOL=0,roundJOV=0,roundADU=0,roundOUTR=0,   roundGERAL=0; //variáveis para contar ROUNDS
	int i;	
		printf("\n");
		for(i = 0; i < total; i++){
			roundGERAL += n2[i]; 
			winGERAL += n1[i];
			empGERAL += n3[i];
		/*	printf("  %s  -> age: %d  vit: %d   %d:  \n",name[i],ida[i],n1[i],n2[i]); */
				if(ida[i]>=6 && ida[i]<12){		// Caso seja uma criança :
					winCRI+= n1[i];				// fazer somatório das vitórias das crianças
					roundCRI += n2[i];			// fazer somatório do nº de jogadas das crianças
					empCRI += n3[i];			// fazer somatório dos empates obtidas pelas crianças
				}else if(ida[i]>=12 && ida[i]<18){
					winADOL+= n1[i];
					roundADOL+= n2[i];
					empADOL+= n3[i];
				}else if(ida[i]>=18 && ida[i]<=25){
					winJOV+= n1[i];
					roundJOV += n2[i];
					empJOV+= n3[i];
				}else if(ida[i]>25 && ida[i]<60){
					winADU+= n1[i];
					roundADU+= n2[i];
					empADU+= n3[i];
				}else if (ida[i] >= 60){
					winOUTR+= n1[i];
					roundOUTR += n2[i];
					empOUTR+= n3[i];
				}															
		}
		
			// Estaística do jogo de acordo com as respetivas idades
				
printf("\n\n");  
    printf("\n\t=================  ESTAÍSTICAS DO JOGO  =======================\n");			
	printf("            +---------------+--------------+------------+--------------+\n");
	printf("            | Jogadas total | Vitórias(%%)  | Empates    |   Derrotas   |\n");
	printf("+-----------+---------------+--------------+------------+--------------+\n");
	printf("|Crianças   |       %2g      |    %.1f      |   %2d       |       %2g     |\n",roundCRI,winCRI*100/roundCRI,empCRI,roundCRI-winCRI);
	printf("|Adolescente|       %2g      |    %.1f      |   %2d       |       %2g     |\n", roundADOL,winADOL*100/roundADOL, empADOL, roundADOL-winADOL);
	printf("|Jovens	    |       %2g      |    %.1f      |   %2d       |       %2g     |\n", roundJOV, winJOV*100/roundJOV, empJOV, roundJOV-winJOV);
	printf("|Adultos    |       %2g      |    %.1f      |   %2d       |       %2g     |\n", roundADU, winADU*100/roundADU, empADU, roundADU-winADU);
	printf("|Outros	    |       %2g      |     %.1f      |   %2d       |       %2g     |\n", roundOUTR, winOUTR*100/roundOUTR, empOUTR, roundOUTR-winOUTR);
	printf("+-----------+---------------+--------------+------------+--------------+\n");
	printf("| GERAL	    |       %2g      |	  %.1f     |	%2d      |       %2g     |\n",roundGERAL,winGERAL*100/roundGERAL,empGERAL,roundGERAL-winGERAL);
	printf("+-----------+---------------+--------------+------------+--------------+\n");
	printf("\n\n\n\n");

int  j;
int aux2,aux3,aux4,r,s;
 /***************  Processo de Ordenação de acordo com pontuações no jogo  **************************/ 		    	    
 
		for(r = 0; r < total; r++){
			for(s = r; s < total; s++){
				if(n2[r] < n2[s]){
					aux4 = n3[r];
					aux3 = n2[r];
					aux2 = n1[r];
					strcpy(aux, name[r]);
					n3[r] = n3[s];
					n2[r] = n2[s];
					n1[r] = n1[s];				
					strcpy(name[r], name[s]); 
					n3[s] = aux4;     
					n2[s] = aux3;
					n1[s] = aux2;
					strcpy(name[s],aux);	
				}
			}
		}	system("pause");
		//  **************** Aqui vai mostrar jogadores com mais partidas ***************
	    printf("\n\t=================  MAIORES NÚMEROS DE PARTIDA  =======================\n");			 
	printf("\t+------------------------+-----------+");    	
    printf("\n\t| NOMES  	 	 |  Partidas |\n"); 
    printf("\t+------------------------+-----------+");		        
    for(j = 0; j < total; j++){
    	    printf("\n\t|%s		  	 |    %2d     |",name[j],n2[j]);
    	    printf("\n\t+------------------------+-----------+");
    	    if(j>8){
				break;
			}              
	}	printf("\n\n\n");     
		
//   Esse trexo de codigo é para ordenação de jogadores de acordo com as que possuem maiores numeros de vitorias

	for(r = 0; r < total; r++){
			for(s = r; s < total; s++){
				if(n1[r]<n1[s]){
					aux4 = n3[r];
					aux3 = n2[r];
					aux2 = n1[r];
					strcpy(aux, name[r]);
					n3[r] = n3[s];
					n2[r] = n2[s];
					n1[r] = n1[s];				
					strcpy(name[r], name[s]); 
					n3[s] = aux4;     
					n2[s] = aux3;
					n1[s] = aux2;
					strcpy(name[s],aux);	
				}
					
			}
		}	system("pause");
		//  **************** Aqui vai mostrar jogadores com mais Vitorrias ***************
	    printf("\n\t=================  COM MAIS VITÓRIAS  =======================\n");			 
	printf("\t+------------------------+-----------+");    	
    printf("\n\t| NOMES  	 	 |  Vitorias |\n"); 
    printf("\t+------------------------+-----------+");		        
    for(j = 0; j < total; j++){
    	    printf("\n\t|%s		  	 |    %2d     |",name[j],n1[j]);
    	    printf("\n\t+------------------------+-----------+");

    	    if(j==4){
				break;
			} 
	}printf("\n\n\n");
	
	//   Esse trexo de codigo é para ordenação de jogadores de acordo com as que possuem maiores numeros de partidas
	for(r = 0; r < total; r++){
			for(s = r; s < total; s++){
				if(n2[r]-n1[r]< n2[s]-n1[s]){
					aux4 = n3[r];
					aux3 = n2[r];
					aux2 = n1[r];
					strcpy(aux, name[r]);
					n3[r] = n3[s];
					n2[r] = n2[s];
					n1[r] = n1[s];				
					strcpy(name[r], name[s]); 
					n3[s] = aux4;     
					n2[s] = aux3;
					n1[s] = aux2;
					strcpy(name[s],aux);
				}
					
			}
		}system("pause");	
		//  **************** Aqui vai mostrar jogadores com mais Derotas ***************
	    printf("\n\t=================  COM MAIS DERROTAS  =======================\n");			 
	printf("\t+------------------------+-----------+");    	
    printf("\n\t| NOMES  	 	 |  DERROTAS |\n"); 
    printf("\t+------------------------+-----------+");		        
    for(j = 0; j < total; j++){
    	    printf("\n\t|%s		  	 |    %2d     |",name[j],n2[j]-n1[j]);
    	    printf("\n\t+------------------------+-----------+");
    	    if(j==4){
				break;
	
			}
	
	}
	
		printf("\n\n\n");
	//   Esse trexo de codigo é para ordenação de jogadores de acordo com as que possuem maiores numeros de partidas
	for(r = 0; r < total; r++){
			for(s = r; s < total; s++){
				if(n3[r]<n3[s]){
					strcpy(aux, name[r]);				
					aux2 	= n3[r];
					strcpy(name[r], name[s]);       
					n3[r]	= n3[s];
					strcpy(name[s],aux);
					n3[s]	= aux2;
				}
					
			}
		}	system("pause");
		//  **************** Aqui vai mostrar jogadores com mais Vitorrias ***************
	    printf("\n\t=================  COM MAIS EMPATES  =======================\n");			 
	printf("\t+------------------------+-----------+");    	
    printf("\n\t| NOMES  	 	 |  EMPATES  |\n"); 
    printf("\t+------------------------+-----------+");		        
    for(j = 0; j < total; j++){
    	    printf("\n\t|%s		  	 |    %2d     |",name[j],n3[j]);
    	    printf("\n\t+------------------------+-----------+");

    	    if(j==4){
				break;
			} 
	}printf("\n\n\n");
	
	
system("pause");
system("cls");
menu();		
	
}


  /// **************** Instruções do jogo para quem nao sabe jogar ********************************************
void Help(){
	system("cls");
	printf("\n\n\n\tO jogo CONNECT4 como alguns conhecem por 'quadrix', é bem prático e fácil de aprender!\n");
	printf("\nO principal objectivo do jogo é formar uma sessão de quatro peças da mesma cor seja, na horizonta, vertical ou oblíqua\n");
	printf("\nO tabuleiro do jogo é preenchido sempre de baixo para cima;\n\n");
system("pause");
menu();		
}

void menu(){
	system("cls");
	printf("\n\n");       //  Apenas Iustrações para o DASHBOARD 
	printf("\033[0;32m +--------+ +--------+ +--+   +--+ +--+   +--+ +-----+ +------+ +--------+                                     \n");
	printf("\033[0;32m |        | |        | |   \\  |  | |   \\  |  | |  +--+ |   ___+ |__    __+ \033[0;31m   +-+  +-+ \033[0m	     \n");
	printf("\033[0;32m |   +----+ |  +--+  | |    \\ |  | |    \\ |  | |  |__  |  |        |  |     \033[0;31m  |*|  |*| \033[0m    	 \n");
	printf("\033[0;32m |   |      |  |  |  | |  +  \\|  | |  +  \\|  | |   __| |  |        |  |     \033[0;31m  |*+--+*| \033[0m      \n");
	printf("\033[0;32m |   +----+ |  +--+  | |  |\\     | |  |\\     | |  |    |  |___     |  |     \033[0;31m  +---+ *| \033[0m   	 \n");   
	printf("\033[0;32m |        | |        | |  | \\    | |  | \\    | |  +--+ |      |    |  |     \033[0;31m       |*| \033[0m      \n");
	printf("\033[0;32m +--------+ +--------+ +--+  \\+--+ +--+  \\+--+ +-----+ +------+    +--+     \033[0;31m       +-+ \033[0m      \n");
	printf("  \033[0m \n\n");
	
	int op;
	printf("\n\t1-Help\n\t2-Nova partida\n\t3-Score\n\t4-Estatistica\n\t5-Sair\n\n\t--->");
	scanf("%d",&op);
	switch(op)
	{
	case 1:
		Help();    // Adicionei essa função para dar instruções a quem nunca jogou
		break;
	case 2:
		registrar();// Vai alocar na memória RAM dados dos jogadores e depois desse processo ele mesmo chama a função de jogar 
		break;
	case 3:
		score(); // O hight score
		break;
	case 4:
		estatistica();
		break;
	case 5:
		sair();
		break;
	default:
		fflush(stdin);
		printf("\n\tOpção inválida\n");
		system("pause");
		menu();
		break;
	}
}

int main(){
setlocale(LC_ALL,"Portuguese_Portugal");
int i,j;
FILE *p=NULL,*p1, *a = NULL;	char  dav;

	p = fopen("DATABASE\\game_DB.txt","r"); // Todo esse processo é para saber quantas pessoas estão registradas no ficheiro
		dav = fgetc(p);						// O número total de arquivos serão guardados na variável 'total'
		while(dav != EOF){ 					// Assim quando pretender percorer todo o ficheiro saberei que o fim ciclo será
			dav = fgetc(p);
			if(dav=='\n'){					// Será incrementado 1 a variável 'total' sempre que houver quebra de linha
				total++;
			}								// aquele valor guardado na variável 'total'
			
		}   	
    fclose(p);
//Carregar todos os dados no ficheiro e guardá-los em vetores que foram declarados glabal 
    p1 = fopen("DATABASE\\game_DB.txt","r");
 
  //  printf("%d",total);   
    	for(j = 0; j < total; j++){
		   	fscanf(p1,"%s\t%d\t%d\t%d\n", name[j], &n1[j], &n2[j],&n3[j]);
		}	
    fclose(p1);		

		a = fopen("DATABASE\\AGES.txt","r");
			for(i = 0; i < total; i++){
				fscanf(a,"%d\n",&ida[i]);        	 
			}
		fclose(a);
// Chamar o menú principal
	menu();
	
	return 0;
}
	