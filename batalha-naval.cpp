//Author: Kevin Louis, Wendell Bianchi, Ronaldo Bianchi

#include <iostream>
#include <ctime>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>



using namespace std;

//Tamanho do mapa
#define tamanho 11

///////Variaveis

//Struct Do Conteudo do Mapa
struct str_celula{
	string user;
	string barco;
};
//Mapa
str_celula mapa[tamanho][tamanho];

string mapa_barcos[tamanho][tamanho];
string mapa_user[tamanho][tamanho];


//Arrays
string letras[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
string numero[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};


//String para aparecer quando acertar
string acerto = "X";
string erro = "-";

//Quantidades de acertos, MAX 10
int acertos = 0;


//Prototipacao
void implementa_barcos();
void implementa_mapa();
void mostrar_mapa();
void mostrar_mapa_barcos();



main(){
	string mostrar_barcos;
	cout << "Deseja mostrar o mapa dos Barcos? (y/n)"<<endl;
	cin >> mostrar_barcos; 
	
	
	implementa_mapa();
	implementa_barcos();

	while(acertos < 10){
		//Imputs para usuario
		int hori_user = 0;
		int ver_user = 0;
		string str_hori_user;
		// Limpar a Tela
		system("cls");
		
		//Mostrar Mapa
		if(mostrar_barcos == "y"){
			mostrar_mapa_barcos();
		}
		mostrar_mapa();
		

		//Pega os dados do usuario
		cout << "Digite a Letra: \n";
		cin >> str_hori_user;

		cout << "Digite o numero: \n";
		cin >> ver_user;


		//Tranforma minuscula em maiuscula
		transform(str_hori_user.begin(), str_hori_user.end(), str_hori_user.begin(), ::toupper);
		
		//Pega a posição da letra
		for(int x = 0; x < tamanho-1; x++){
			if(letras[x] == str_hori_user){
				hori_user = x+1;
			}
		}	

		//Tranforma valor para key
		ver_user++;
		
		//Verifica se acertou
		if(hori_user == 0 || ver_user >= 10 || ver_user < 0){
			cout << "Selecione um valor valido \n";
			system("pause");
			
		}else if(mapa[ver_user][hori_user].barco == acerto){
			cout << "Acertou Mizeravi \n";
			system("pause");
			
			//Troca o Valor 
			mapa[ver_user][hori_user].user = acerto;
			
			//Verificador de acertos
			acertos++;
			
		}else{
			cout << "Errou feio, Errou rude \n";
			system("pause");
			
			//Troca o Valor
			mapa[ver_user][hori_user].user = erro;
		}
	}
	
	cout << "Parabens, voce acertou todos";


}
void implementa_mapa(){
	int v = 0;
	for(int y = 0; y < tamanho; y++){
		for(int x = 0; x < tamanho; x++){
			if(y == 0 && x == 0){
				str_celula celula;
				celula.user = "*";
				celula.barco = "*";
				mapa[y][x] = celula;
			}else {
				if(y == 0){
					str_celula celula;
					celula.user = letras[x-1];
					celula.barco = letras[x-1];
					mapa[y][x] = celula;

				}else if(x == 0){
					str_celula celula;
					celula.user = numero[v];
					celula.barco = numero[v];
					mapa[y][x] = celula;		
					v++;
					
				}else{
					str_celula celula;
					celula.user = " ";
					celula.barco = " ";
					mapa[y][x] = celula;	
				}
			}		
		}
	}
	
}

void implementa_barcos(){
	
	srand(time(0));
	int verifica = 0;
	int y, x;
	
	for(int tipo_barco = 1; tipo_barco <= 4; tipo_barco++){
		while(verifica == 0){
		
			y = rand() % 9+1;
			x = rand() % 9+1;
		
			//direita
			for(int i = 0; i<tipo_barco; i++){
				if(mapa[y][x+i].barco == acerto || x+i >= 10){
					verifica = 0;
					break;
				}else{
					verifica = 1;
				}
			}
			
			//esquerda
			if(verifica == 0){
				for(int i = 0; i<tipo_barco; i++){
					if(mapa[y][x-i].barco == acerto || x-i <= 0){
						verifica = 0;
						break;
					}else{
						verifica = 2;
					}
				}
			}
			
			//cima
			if(verifica == 0){
				for(int i = 0; i<tipo_barco; i++){
					if(mapa[y+i][x].barco == acerto || y+i >= 10){
						verifica = 0;
						break;
					}else{
						verifica = 3;
					}
				}
			}
			
			//baixo
			if(verifica == 0){
				for(int i = 0; i<tipo_barco; i++){
					if(mapa[y-i][x].barco == acerto || y-i <= 0){
						verifica = 0;
						break;
					}else{
						verifica = 4;
					}
				}
			}
		}
		
		int i = 0;
	
		switch(verifica){
			//Se caso for pra direita
			case 1:
				while(i != tipo_barco){
					mapa[y][x+i].barco = acerto;
					i++;
				}
				break;
			//Se caso for pra esquerda
			case 2:
				while(i != tipo_barco){
					mapa[y][x-i].barco = acerto;

					i++;
				}
				break;
			//Se caso for pra cima
			case 3:
				while(i != tipo_barco){
					mapa[y+i][x].barco = acerto;

					i++;
				}
				break;
			//Se caso for pra baixo
			case 4:
				while(i != tipo_barco){
					mapa[y-i][x].barco = acerto;
					i++;
				}
				break;
		}
		verifica = 0;
	}
}


void mostrar_mapa(){
	for(int y = 0; y < tamanho; y++){
		for(int x = 0; x < tamanho; x++){
			if(y == 0 && x == 0){
				cout << mapa[y][x].user<< " |";
			}else{
			
				if(y == 0){
					cout <<" "<<mapa[y][x].user<<" |";
				}else if(x == 0){
					cout <<mapa[y][x].user;
				}else{
					if(x != tamanho-1){
						cout << " | "<<mapa[y][x].user;
					}else{
						cout << " | "<<mapa[y][x].user<< " |";
					}
					
				}
			}
		
		}	
		cout <<endl<< "-------------------------------------------"<<endl	;
	}
}

void mostrar_mapa_barcos(){
	for(int y = 0; y < tamanho; y++){
		for(int x = 0; x < tamanho; x++){
			if(y == 0 && x == 0){
				cout << mapa[y][x].barco<< " |";
			}else{
			
				if(y == 0){
					cout <<" "<<mapa[y][x].barco<<" |";
				}else if(x == 0){
					cout <<mapa[y][x].barco;
				}else{
					if(x != tamanho-1){
						cout << " | "<<mapa[y][x].barco;
					}else{
						cout << " | "<<mapa[y][x].barco<< " |";
					}
					
				}
			}
		
		}	
		cout <<endl<< "-------------------------------------------"<<endl;
	}
	cout <<endl;
}



