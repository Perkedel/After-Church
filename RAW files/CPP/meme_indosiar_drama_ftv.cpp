#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int bulan, angka;
	char nama;
	
	
	
	scanf("%d %d %c", &bulan, &angka, &nama);
	
	switch(bulan){
		case 1:
		printf("Penebar Hoax ");
		break;
		
		case 2:
		printf("Pedagan Kikir ");
		break;
		
		case 3:
		printf("Pelakor ");
		break;
		
		case 4:
		printf("Tukang Bohong ");
		break;
		
		case 5:
		printf("Pencuri ");
		break;
		
		case 6:
		printf("Pencopet ");
		break;
		
		case 7:
		printf("Anak Durhaka ");
		break;
		
		case 8:
		printf("Tukang Ngutang ");
		break;
		
		case 9:
		printf("Koruptor ");
		break;
		
		case 10:
		printf("Penipu ");
		break;
		
		case 11:
		printf("Penjudi ");
		break;
		
		case 12:
		printf("Lintah Darat ");
		break;
		
		default:
		printf("Cocor Bebek ");
		break;
	}
	
	switch(angka){
		case 1:
		printf("Kejatuhan ");
		break;
		case 2:
		printf("Kelilipan ");
		break;
		case 3:
		printf("Ditimpuki ");
		break;
		case 4:
		printf("Ketindihan ");
		break;
		case 5:
		printf("Tersedak ");
		break;
		case 6:
		printf("Kecanduan ");
		break;
		case 7:
		printf("Keracunan ");
		break;
		case 8:
		printf("Kesandung ");
		break;
		case 9:
		printf("Tertimbun ");
		break;
		case 0:
		printf("Dilempari ");
		break;
		
		default:
		printf("Kena");
		break;
	}
	
	if(nama == 'A' || nama == 'a'){
		printf("Spanduk Pecel Lele");
	} else if(nama == 'B' || nama == 'b'){
		printf("Ubin Bengkel");
	} else if(nama == 'C' || nama == 'c'){
		printf("Mangkok Mie Ayam");
	}else if(nama == 'D' || nama == 'd'){
		printf("Jok Sepeda");
	}else if(nama == 'E' || nama == 'e'){
		printf("Kulkas 3 Pintu");
	}else if(nama == 'f' || nama == 'f'){
		printf("Koran Bekas");
	}else if(nama == 'G' || nama == 'g'){
		printf("Karung Semen");
	}else if(nama == 'H' || nama == 'h'){
		printf("Kaleng Sarden");
	}else if(nama == 'I' || nama == 'i'){
		printf("Garpu Somay");
	}else if(nama == 'J' || nama == 'j'){
		printf("Petasan Cabe");
	}else if(nama == 'K' || nama == 'k'){
		printf("Sapu Lidi");
	}else if(nama == 'L' || nama == 'l'){
		printf("Gorden Warteg");
	}else if(nama == 'M' || nama == 'm'){
		printf("Kulit Lontong");
	}else if(nama == 'N' || nama == 'n'){
		printf("Kertas Bakpao");
	}else if(nama == 'O' || nama == 'o'){
		printf("Pensil 2B");
	}else if(nama == 'P' || nama == 'p'){
		printf("Biji Duren");
	}else if(nama == 'Q' || nama == 'q'){
		printf("Pelg Becak");
	}else if(nama == 'R' || nama == 'r'){
		printf("Serpihan Meteor");
	}else if(nama == 'S' || nama == 's'){
		printf("Bungkus Puyer");
	}else if(nama == 'T' || nama == 't'){
		printf("Oli Bekas");
	}else if(nama == 'U' || nama == 'u'){
		printf("Paku Payung");
	}else if(nama == 'V' || nama == 'v'){
		printf("Toples Nastar");
	}else if(nama == 'W' || nama == 'w'){
		printf("Ember Bocor");
	}else if(nama == 'X' || nama == 'x'){
		printf("Tempe");
	}else if(nama == 'Y' || nama == 'y'){
		printf("Kulit Kacang");
	}else if(nama == 'Z' || nama == 'z'){
		printf("Lampu Taman");
	}else {
		printf("Kanker");
	}
	
	
	//by JOELwindows7
	//Perkedel Technologies
	//GNU GPL v3
	//Based on someone's meme about this Indosiar FTV overbusively specific drama title, unknown copyright!
	//Stdin example:
	//2 9 J
	return 0;
}