#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;

class Map {
	
	private:
		int en = 10;
		int boy = 10;
		
	public:
		int su_X;
		int su_Y;
		int yemek_X;
		int yemek_Y;
	
		void random_water() {
		
		su_X = rand()%en;
		su_Y = rand()%boy;
		cout<<"Su Konumu: ["<<su_X<<"]["<<su_Y<<"]"<<endl;
	
		}
		
		void random_food() {

			yemek_X = rand()%en;
			yemek_Y = rand()%boy;
			cout<<"Yemek Konumu: ["<<yemek_X<<"]["<<yemek_Y<<"]"<<endl;

		}	

};
	
class Player {
	
	private:
		int id = 100 + rand()%200; // 100 ile 200 arasýnda rastgele bir id olusturur
		
	public:
		string yon;
		string kullaniciadi;
		int birim;
		int skor = 0;
		int uyku_istegi = 0;
		int su_seviyesi = 100;
		int tokluk_seviyesi = 100;
		int para = 100;
		int playerX = 0; //Oyuncunun x konumu
		int playerY = 0; // Oyuncunun y konumu
		int gun=1;
		int calisma_siniri = 1; //Gunluk sadece 1 iste calisabilir
		
		
		void gun_goster() {
			
			cout<<"\t  |GUN: "<<gun<<"|"<<endl;
						
		}
		
		void calisma_siniri_sifirla() {
			
			calisma_siniri = 0;
		}
	
		void hareket_et() {
			
			while(birim!=0)
			{
				cout<<endl;
				cout<<"Simdiki Konum:["<<playerX<<"]["<<playerY<<"]"<<endl;
				cout<<"Yonler => a:Sol / d:Sag / w:Yukari / s:Asagi"<<endl;
				cout<<"Hangi yone gitmek istersiniz(cikmak icin 'x' tuslayin): ";
				cin>>yon;
				
				if(yon == "x")
				{
					cout<<endl;
					cout<<"Hareket et menusunden ciktiniz!"<<endl;
					break;
				}
				
				cout<<"Kac br gitmek istersiniz: ";
				cin>>birim;
				
				if(yon == "a")
				{
					playerX -= birim;
				}
				else if(yon == "d")
				{
					playerX += birim;
				}
				else if(yon == "w")
				{
					playerY += birim;
				}
				else if(yon == "s")
				{
					playerY -= birim;
				}
				else
				{
					cout<<"Hatali bir veri girisi yaptiniz!"<<endl;
				}
				
				cout<<"Guncellenen Konum:["<<playerX<<"]["<<playerY<<"]"<<endl;
				}
				
		} 
		void konum_goster() {
			
			cout<<"Guncel Konum:["<<playerX<<"]["<<playerY<<"]"<<endl;
		}
		
		void market() {
			
			int islem2=0;
			
			while(islem2!=5)
			{
				cout<<endl;
				cout<<"*** Market ***"<<endl;
				cout<<"1-Hamburger(30 TL)(+15 Tokluk)"<<endl;
				cout<<"2-Pizza(35 TL)(+20 Tokluk)"<<endl;
				cout<<"3-Salata(20 TL)(+10 Tokluk)"<<endl;
				cout<<"4-Su(5 TL)(+10 Susuzluk)"<<endl;
				cout<<"5-Cikis Yap"<<endl<<endl;
				cout<<"*Guncel Bakiyeniz: "<<para<<" TL"<<endl;
				cout<<"*Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
				cout<<"*Su Seviyesi: "<<su_seviyesi<<"/100"<<endl<<endl;
				
				cout<<"Bir secim yapiniz: ";
				cin>>islem2;
				
				switch(islem2)
				{
					case 1: if(para>=30 and tokluk_seviyesi<=85)
							{
								para -= 30;
								tokluk_seviyesi += 15;
								break;
							}
							else if(para<30)
							{
								cout<<endl;
								cout<<"Bakiye: "<<para<<" TL"<<endl;
								cout<<"--> Maalesef paraniz hamburger almaya yetmiyor!"<<endl;
								break;
							}
							else
							{
								cout<<endl;
								cout<<"--> Tokluk limitine ulasildi. Hamburger yiyemezsiniz."<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								break;
							}
					
					case 2: if(para>=35 and tokluk_seviyesi<=80)
							{
								para -= 35;
								tokluk_seviyesi += 20;
								break;
							}
							else if(para<35)
							{
								cout<<endl;
								cout<<"Bakiye: "<<para<<" TL"<<endl;
								cout<<"--> Maalesef paraniz pizza almaya yetmiyor!"<<endl;
								break;
							}
							else
							{
								cout<<endl;
								cout<<"--> Tokluk limitine ulasildi. Pizza yiyemezsiniz."<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								break;
							}
						
					case 3: if(para>=20 and tokluk_seviyesi<=90)
							{
								para -= 20;
								tokluk_seviyesi += 10;
								break;
							}
							else if(para<20)
							{
								cout<<endl;
								cout<<"Bakiye: "<<para<<" TL"<<endl;
								cout<<"--> Maalesef paraniz salata almaya yetmiyor!"<<endl;
								break;
							}
							else
							{
								cout<<endl;
								cout<<"--> Tokluk limitine ulasildi. Salata yiyemezsiniz."<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								break;
							}
							
					case 4: if(para>=5 and su_seviyesi<=90)
							{
								para -= 5;
								su_seviyesi += 10;
								break;
							}
							else if(para<5)
							{
								cout<<endl;
								cout<<"Bakiye: "<<para<<" TL"<<endl;
								cout<<"--> Maalesef paraniz su almaya yetmiyor!"<<endl;
								break;
							}
							else
							{
								cout<<endl;
								cout<<"--> Su limitine ulasildi. Su icemezsiniz."<<endl;
								cout<<"Su Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								break;
							}
						
					case 5: cout<<endl;
							cout<<"--> Marketten Cikildi!";
							break;
						
					default: cout<<endl;
							 cout<<"Boyle bir islem bulunamadi!"<<endl;
							 break;
				}
			}	
		}
			
		void bilgi_goster() {
			
			cout<<"-----------------------------------"<<endl;
			cout<<"*** Karakter Bilgileri ***"<<endl;
			cout<<"ID:"<<id<<endl;
			cout<<"Kullanici Adi: "<<kullaniciadi<<endl;
			cout<<"Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
			cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
			cout<<"Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
			cout<<"Guncel Konum:["<<playerX<<"]["<<playerY<<"]"<<endl;
			cout<<"Para: "<<para<<" TL";
			
		}
		
		void skor_goster() {
			
			cout<<endl;
			cout<<"SKOR: "<<skor<<endl;
		}
		
		void uyku_planla() {
			
			int islem_uyku=0;
			
			while(islem_uyku!=6)
				{
					cout<<endl;
					cout<<"*** Uyku Saatleri ***"<<endl;
					cout<<"1- 1 Saat Uyu(+15 Uyku, -10 Tokluk, -10 Su Seviyesi)"<<endl;
					cout<<"2- 3 Saat Uyu(+30 Uyku, -15 Tokluk, -15 Su Seviyesi)"<<endl;
					cout<<"3- 5 Saat Uyu(+45 Uyku, -20 Tokluk, -20 Su Seviyesi)"<<endl;
					cout<<"4- 7 Saat Uyu(+60 Uyku, -25 Tokluk, -25 Su Seviyesi)"<<endl;
					cout<<"5- 9 Saat Uyu(+75 Uyku, -30 Tokluk, -30 Su Seviyesi)"<<endl;
					cout<<"6- Yataktan Cik"<<endl<<endl;
					cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl<<endl;
					
					cout<<"Bir secim yapiniz: ";
					cin>>islem_uyku;
					
					switch(islem_uyku)
					{
						case 1: if(uyku_istegi>15)
								{
									uyku_istegi -= 15;
									tokluk_seviyesi -=  10;
									su_seviyesi -= 10;
									gun++;
									calisma_siniri = 1;
									
									cout<<"Uyuyorsun..."<<endl;
									Sleep(3000);
									
									cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
									cout<<"Guncel Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
									cout<<"Guncel Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
									break;
									
								}
								else
								{
									cout<<endl;
									cout<<"Daha fazla uyuyamazsiniz."<<endl;
									cout<<"Uyku Istegi: "<<uyku_istegi<<endl;
									break;
								}
							
						case 2: if(uyku_istegi>30)
								{
									uyku_istegi -= 30;
									tokluk_seviyesi -=  15;
									su_seviyesi -= 15;
									gun++;
									calisma_siniri = 1;
									
									cout<<"Uyuyorsun..."<<endl;
									Sleep(3000);
									
									cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
									cout<<"Guncel Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
									cout<<"Guncel Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
									break;
									
								}
								else
								{
									cout<<endl;
									cout<<"Daha fazla uyuyamazsiniz."<<endl;
									cout<<"Uyku Istegi: "<<uyku_istegi<<endl;
									break;
								}
							
						case 3: if(uyku_istegi>45)
								{
									uyku_istegi -= 45;
									tokluk_seviyesi -=  20;
									su_seviyesi -= 20;
									gun++;
									calisma_siniri = 1;
									
									cout<<"Uyuyorsun..."<<endl;
									Sleep(3000);
									
									cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
									cout<<"Guncel Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
									cout<<"Guncel Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
									break;
									
								}
								else
								{
									cout<<endl;
									cout<<"Daha fazla uyuyamazsiniz."<<endl;
									cout<<"Uyku Istegi: "<<uyku_istegi<<endl;
									break;
								}
							
						case 4: if(uyku_istegi>60)
								{
									uyku_istegi -= 15;
									tokluk_seviyesi -=  25;
									su_seviyesi -= 25;
									gun++;
									calisma_siniri = 1;
									
									cout<<"Uyuyorsun..."<<endl;
									Sleep(3000);
									
									cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
									cout<<"Guncel Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
									cout<<"Guncel Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
									break;
									
								}
								else
								{
									cout<<endl;
									cout<<"Daha fazla uyuyamazsiniz."<<endl;
									cout<<"Uyku Istegi: "<<uyku_istegi<<endl;
									break;
								}
							
						case 5: if(uyku_istegi>75)
								{
									uyku_istegi -= 15;
									tokluk_seviyesi -=  25;
									su_seviyesi -= 25;
									gun++;
									
									cout<<"Uyuyorsun..."<<endl;
									Sleep(3000);
									
									cout<<"Guncel Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
									cout<<"Guncel Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
									cout<<"Guncel Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
									break;
									
								}
								else
								{
									cout<<endl;
									cout<<"Daha fazla uyuyamazsiniz."<<endl;
									cout<<"Uyku Istegi: "<<uyku_istegi<<endl;
									break;
								}
							
						case 6: cout<<"--> Yataktan ciktiniz!"<<endl;
								break;
							
						default: cout<<"Boyle bir islem bulunamadi."<<endl;
								 break;
					}
				}
		}
		
		void para_kazan() {
					
			int secim_para=0;
			
			while(secim_para!=5)
			{
				cout<<endl;
				cout<<"*** Para Kazan ***"<<endl;
				cout<<"1-Taksi Sur(+80 TL) (-20 Tokluk,-20 Su Seviyesi, +20 Uyku Istegi)"<<endl;
				cout<<"2-Garsonluk Yap (+60 TL) (-15 Tokluk,-15 Su Seviyesi, +15 Uyku Istegi)"<<endl;
				cout<<"3-Fotografcilik Yap (+50 TL) (-10 Tokluk,-10 Su Seviyesi, +10 Uyku Istegi)"<<endl;
				cout<<"4-Temizlik Yap(+40 TL) (-15 Tokluk,-5 Su Seviyesi, +15 Uyku Istegi)"<<endl;
				cout<<"5-Cikis Yap"<<endl<<endl;
				
				cout<<"Bir is sec: ";
				cin>>secim_para;
				
				switch(secim_para)
				{
					case 1: if(calisma_siniri==1)
							{
								cout<<"Taksi suruyorsun..."<<endl;
								Sleep(3000);
								cout<<"--> ISIN BITTI, 80 TL KAZANDIN!"<<endl;
								para += 80;
								tokluk_seviyesi -=20;
								su_seviyesi -= 20;
								uyku_istegi += 20;
							
								cout<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								cout<<"Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								cout<<"Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
								calisma_siniri_sifirla();
								break;
							}
							else
							{
								cout<<"--> Gunluk sadece 1 kere calisabilirsin."<<endl;
								break;
							}
							
					case 2: if(calisma_siniri==1)
							{
								cout<<"Garsonluk yapiyorsun..."<<endl;
								Sleep(3000);
								cout<<"--> ISIN BITTI, 60 TL KAZANDIN!"<<endl;
								para += 60;
								tokluk_seviyesi -=15;
								su_seviyesi -= 15;
								uyku_istegi += 15;
							
								cout<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								cout<<"Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								cout<<"Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								calisma_siniri_sifirla();
								break;
							}
							else
							{
								cout<<"--> Gunluk sadece 1 kere calisabilirsin."<<endl;
								break;
							}
						
					case 3: if(calisma_siniri==1)
							{
								cout<<"Fotografcilik yapiyorsun..."<<endl;
								Sleep(3000);
								cout<<"-->ISIN BITTI, 50 TL KAZANDIN!"<<endl;
								para += 50;
								tokluk_seviyesi -=10;
								su_seviyesi -= 10;
								uyku_istegi += 10;

								cout<<endl;							
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								cout<<"Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								cout<<"Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								calisma_siniri_sifirla();
								break;
							}
							else
							{
								cout<<"--> Gunluk sadece 1 kere calisabilirsin."<<endl;
								break;
							}
						 
					case 4: if(calisma_siniri==1)
							{
								cout<<"Temizlik yapiyorsun..."<<endl;
								Sleep(3000);
								cout<<"-->ISIN BITTI, 40 TL KAZANDIN!"<<endl;
								para += 40;
								tokluk_seviyesi -=5;
								su_seviyesi -= 5;
								uyku_istegi += 5;
							
								cout<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								cout<<"Uyku Istegi: "<<uyku_istegi<<"/100"<<endl;
								cout<<"Tokluk Seviyesi: "<<tokluk_seviyesi<<"/100"<<endl;
								cout<<"Su Seviyesi: "<<su_seviyesi<<"/100"<<endl;
								cout<<"*Guncel Bakiye: "<<para<<" TL"<<endl;
								calisma_siniri_sifirla();
								break;
							}
							else
							{
								cout<<"--> Gunluk sadece 1 kere calisabilirsin."<<endl;
								break;
							}
						
					case 5: cout<<"Para kazanma menusunden ciktiniz!"<<endl;
							break;
						
					default: cout<<"Boyle bir islem bulunamadi."<<endl;
							 break;
				}
			}		
		}
};

int main() {
	Map map;
	Player player1,player2,player3;
	int islem1=0;
	int islem3=0;
	int tutar1,tutar2;
	int i;
	
	player2.kullaniciadi = "Yasir";
	player2.para = 200;
	player3.kullaniciadi = "Semih";
	player3.para = 150;
	
	cout<<"Oyuna baslamadan bir kullanici adi giriniz: ";
	cin>>player1.kullaniciadi;
	
	cout<<"--> Sayin "<<player1.kullaniciadi<<", 'Real Life Simulator' oyununa hos geldiniz!"<<endl<<endl;
	cout<<"Oyun Nasil Oynanir?"<<endl;
	cout<<"* Kullanici adini belirlediginiz bir karakter olusturulur."<<endl;
	cout<<"* Bu karakterin uyku istegi, su istegi ve tokluk seviyesi gibi fonksiyonlari vardir."<<endl;
	cout<<"* Bu 3 ozellik, sizin secimlerinizle sekillenecektir."<<endl;
	cout<<"* Bu 3 ana ozelligi dengede tutarak karakterinizi hayatta kalmaya calismalisiniz."<<endl;
	cout<<"* Bu 3 ana ozellikten herhangi biri 0 oldugunda oyun sonlanir."<<endl;
	cout<<"* Her uyudugunuzda yeni bir gunle uyanacaksiniz."<<endl;
	cout<<"* Hayatta kaldiginiz gun boyunca 50 Puan kazanacaksiniz."<<endl;
	cout<<"--> Bol Sans "<<player1.kullaniciadi<<", Umarim Yuksek Skorlar Elde Edersin!"<<endl<<endl;

	while(islem1!=8)
	{
		etiket_1:
		
		cout<<endl;
		cout<<"----------------------------------"<<endl;
		player1.gun_goster();
		cout<<"----------------------------------"<<endl;
		cout<<"*** Islemler ***"<<endl;
		cout<<"1-Hareket Et"<<endl;
		cout<<"2-Haritadaki Nesnelerin Koordinatlarini Goster"<<endl;
		cout<<"3-Tum Bilgileri Goster"<<endl;
		cout<<"4-Market"<<endl;
		cout<<"5-Para Kazan"<<endl;
		cout<<"6-Para Transferi Yap"<<endl;
		cout<<"7-Uyu"<<endl;
		cout<<"8-Oyundan Cik"<<endl;
		cout<<"-----------------------------------"<<endl;
		
		cout<<"Bir islem seciniz: ";
		cin>>islem1;
		cout<<endl;
	
	switch(islem1)
	{
		case 1: if(player1.tokluk_seviyesi <= 15 or player1.su_seviyesi <= 15 or player1.uyku_istegi>=85)
				{
					cout<<"--> Hareket etmek icin gerekli enerjiye sahip degilsiniz!"<<endl;
					cout<<"Tokluk Seviyesi: "<<player1.tokluk_seviyesi<<"/100"<<endl;
					cout<<"Su Seviyesi: "<<player1.su_seviyesi<<"/100"<<endl;
					cout<<"Uyku Istegi: "<<player1.uyku_istegi<<"/100"<<endl;
					break;
				}
				else
				{
					player1.hareket_et();
					cout<<"Enerji Tuketildi --> -10 Tokluk Seviyesi, -10 Su Seviyesi, +10 Uyku Istegi"<<endl;
					player1.tokluk_seviyesi -= 10;
					player1.su_seviyesi -= 10;
					player1.uyku_istegi += 10;
					cout<<"Tokluk Seviyesi: "<<player1.tokluk_seviyesi<<"/100"<<endl;
					cout<<"Su Seviyesi: "<<player1.su_seviyesi<<"/100"<<endl;
					cout<<"Uyku Istegi: "<<player1.uyku_istegi<<"/100"<<endl;
					cout<<endl;
					
					if(player1.playerX == map.su_X and player1.playerY == map.su_Y)
					{
						cout<<"--> TEBRIKLER, SUYU ALDINIZ! Su SEVIYENIZ 10 ARTTI."<<endl;
						player1.su_seviyesi += 10;
						cout<<"*Guncel Su Seviyesi: "<<player1.su_seviyesi<<"/100"<<endl;
						break;
					}
					
					if(player1.playerX == map.yemek_X and player1.playerY == map.yemek_Y)
					{
						cout<<"--> TEBRIKLER, YEMEGI ALDINIZ! TOKLUK SEVIYENIZ 10 ARTTI."<<endl;
						player1.tokluk_seviyesi += 10;
						cout<<"*Guncel Tokluk Seviyesi: "<<player1.tokluk_seviyesi<<"/100"<<endl;
						break;
					}
					
					break;
				}
				
		case 2: cout<<"*** Haritadaki Nesneler ve Konumlari ***"<<endl;
				map.random_food();
				map.random_water();
				break;
			
		case 3: player1.bilgi_goster();
				goto etiket_1;
				
			
		case 4: player1.market();
				break;
			
		case 5: player1.para_kazan();
				break;
			
		case 6: while(islem3!=3)
				{
					cout<<endl;
					cout<<"*** Para Transfer Merkezi ***"<<endl<<endl;
					cout<<"1-Yasir"<<endl;
					cout<<"2-Semih"<<endl;
					cout<<"3-Cikis Yap"<<endl;
					cout<<"Guncel Bakiyeniz: "<<player1.para<<" TL"<<endl<<endl;
					
					cout<<"Bir kisi seciniz: ";
					cin>>islem3;
					cout<<endl;
					
					switch(islem3)
					{
						case 1: cout<<"Guncel Bakiyeniz: "<<player1.para<<" TL"<<endl;
								cout<<"Yasir'in Guncel Bakiyesi: "<<player2.para<<endl;
								cout<<endl;
								cout<<"Yasir'e atmak istediginiz TL tutarini giriniz: ";
								cin>>tutar1;
								
								if(tutar1>player1.para)
								{
									cout<<endl;
									cout<<"--> Para limitinizden fazla para yollayamazsiniz!"<<endl;
									break;
									
								}
								else
								{
									player2.para += tutar1;
									player1.para -= tutar1;
									
									cout<<player1.kullaniciadi<<" adli kullanici, "<<player2.kullaniciadi<<" adli kullaniciya "<<tutar1<<" TL yolladi!"<<endl;
									cout<<"Kalan Bakiye: "<<player1.para<<" TL"<<endl;
									cout<<"Yasir'in Kalan Bakiyesi: "<<player2.para<<" TL"<<endl;
									break;
								}	
							
						case 2: cout<<"Guncel Bakiyeniz: "<<player1.para<<" TL"<<endl;
								cout<<"Semih'in Guncel Bakiyesi: "<<player3.para<<endl;
								
								cout<<"Semih'e atmak istediginiz TL tutarini giriniz: ";
								cin>>tutar2;
								
								if(tutar2>player1.para)
								{
									cout<<endl;
									cout<<"--> Para limitinizden fazla para yollayamazsiniz!"<<endl;
									break;
									
								}
								else
								{
									player3.para += tutar2;
									player1.para -= tutar2;
									
									cout<<player1.kullaniciadi<<" adli kullanici, "<<player3.kullaniciadi<<"adli kullaniciya "<<tutar2<<" TL yolladi!"<<endl;
									cout<<"Kalan Bakiye: "<<player1.para<<" TL"<<endl;
									cout<<"Semih'in Kalan Bakiyesi: "<<player3.para<<" TL"<<endl;
									break;
								}
								
						case 3: cout<<"Para Transfer Merkezinden Cikis Yapildi!"<<endl;
								break;
							
						default: cout<<"Boyle bir islem bulunamadi!"<<endl;
								 break;
					}
					
					}
					break;
			
		case 7: player1.uyku_planla();
				break;
	
		case 8: cout<<"Sayin "<<player1.kullaniciadi<<", Oyundan Cikis Yaptiniz!"<<endl;
				player1.skor_goster();
				return 0;
				
		default: cout<<"--> Boyle bir islem bulunamadi."<<endl;
				 break;
	}
	
		player1.su_seviyesi-=5;
		player1.tokluk_seviyesi-=5;
		player1.uyku_istegi +=5;
		player1.skor += 50;
		
		cout<<endl;
		
		if(player1.uyku_istegi == 100)
		{
			cout<<endl;
			cout<<"--> Cok uzun sure uyumadiginiz icin oldunuz, OYUN BITTI."<<endl;
			player1.skor_goster();
			return 0;
		}
		
		if(player1.su_seviyesi == 0)
		{
			cout<<endl;
			cout<<"-->Cok uzun sure su icmediginiz icin oldunuz, OYUN BITTI."<<endl;
			player1.skor_goster();
			return 0;
		}
		
		if(player1.tokluk_seviyesi == 0)
		{
			cout<<endl;
			cout<<"--> Cok uzun sure yemek yemediginiz icin oldunuz, OYUN BITTI."<<endl;
			player1.skor_goster();
			return 0;
		}
	
		if(player1.su_seviyesi <50)
		{
			cout<<endl;
			cout<<"Su seviyen %50'nin altina dustu! Su icmen gerek!"<<endl;
			cout<<"Su Seviyesi: "<<player1.su_seviyesi<<endl<<endl;
		}
		
		if(player1.tokluk_seviyesi < 50)
		{
			cout<<endl;
			cout<<"Tokluk seviyen %50'nin altina dustu! Yemek yemen gerek!"<<endl;
			cout<<"Tokluk Seviyesi: "<<player1.tokluk_seviyesi<<endl;
		}
		
		if(player1.uyku_istegi > 50)
		{
			cout<<endl;
			cout<<"Uykuya ihtiyacin var. Uyuman gerek!"<<endl;
			cout<<"Uyku Seviyesi: "<<player1.uyku_istegi<<endl;
		}
		
	}
	
	system("pause");
}
