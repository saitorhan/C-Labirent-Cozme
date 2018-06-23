// Sait ORHAN
// 1030515650
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUVAR 1
#define GIDILDI 2
#define CIKIS 3
#define BOYUT 30

enum sonuc {false, true};
typedef enum sonuc sonuc;

sonuc yolbul(int *[][BOYUT],int,int);
void labirent_uret(int *[][BOYUT], int);
void labirent_tahtasi_uret(int *[][BOYUT]);
void labirent_sifirla(int *[][BOYUT]);
void dosyaya_yaz(int *[][BOYUT]);
void rastgele_bosluklar(int *[][BOYUT]);


int main()
{
    // Rastgele labirent üretme satýrlarý baþlangýcý
      srand(time(NULL));
      int labirent[BOYUT][BOYUT];
      int giris, girisi[3];
      int secim;
      // Çıkış garantili giriş noktaları
      girisi[0] = rand()%9;
      girisi[1] = 10+rand()%9;
      girisi[2] = 20+rand()%9;
     labirent_tahtasi_uret(labirent);
      for(giris=0; giris<3; giris++)
          labirent_uret(labirent, girisi[giris]);
          rastgele_bosluklar(labirent);
    printf("maze is OK.\n");
    printf("FOR SAVE it to .txt file press 1.\n");
    printf("without saving press 2.\n\nyour choose: \n\n");
    scanf("%d", &secim);
    switch(secim){
           case 1: dosyaya_yaz(labirent);
           default:
                  printf("you choosed without saving for solve it.\n\n"); }

// Rastgele labirent üretme satýrlarý sonu

      int i,j;
// Labirenti yazdir
      for(i=0; i<BOYUT; i++){
            for(j=0; j<BOYUT; j++)
            printf("%d",labirent[i][j]);
        printf("\n");}
// Çýkýþ olabilecek noktalarý iþaretle
// Son sütundaki her 0 bir çýkýþ olabilir
        for(i=0; i<BOYUT; i++){
          if(labirent[i][29]==0)
        labirent[i][29] = CIKIS;}
// Labirenti çözücüye gönder
// Ýlk sütundaki her 0 bir giriþtir.
        j=0;
      for(i=0; i<BOYUT; i++){
          if(labirent[i][0] == 0){
             if(yolbul(labirent,i,j)){  labirent_sifirla(labirent);
                printf("%c%c%c%c%c maze solved %c%c%c%c%c (%2d,%2d)'from here entered...\n",223,223,223,223,223,223,223,223,223,223,i,j);  system("PAUSE");}
            else
                printf("%c%c%c%c%c last of this way %c%c%c%c%c (%2d,%2d)'from here entered...\n",223,223,223,223,223,223,223,223,223,223,i,j);  }
      }
    system("PAUSE");
    return 0;

}

sonuc yolbul(int *labirent[][BOYUT],int i, int j)
{
    if(i<0 || i>=BOYUT)
        return false;
    if(j<0 || j>=BOYUT)
        return false;
    if(labirent[i][j] == DUVAR)
        return false;
    if(labirent[i][j] == GIDILDI)
        return false;
    if(labirent[i][j]==CIKIS)
        return true;

    labirent[i][j]=GIDILDI;
    if(yolbul(labirent,i,j-1))        {printf(" (%2d , %2d) down\n",i,j-1);     return true;}
    else if(yolbul(labirent,i,j+1))   {printf(" (%2d , %2d) up\n",i,j+1);    return true;}
    else if(yolbul(labirent,i+1, j))  {printf(" (%2d , %2d) right\n",i+1,j);       return true;}
    else if(yolbul(labirent,i-1, j))  {printf(" (%2d , %2d) left\n",i-1,j);    return true;}
    return false;

}

// Rastgele labirent üretme fonksiyonu
void labirent_uret(int *labirent[][BOYUT], int i)
{
    srand(time(NULL));
    int j=1;
    int hangi_yon;
    labirent[i][0]=0;
    labirent[i][1]=0;
    while(j<BOYUT){
        hangi_yon = rand()%3;
        switch(hangi_yon){
               case 0:   labirent[i][j+1]=0;
                         j++;
                         break;

               case 1:  if(i<29)    {labirent[i+1][j]=0;   i++;}
                        break;

               case 2:  if(i>0)     {labirent[i-1][j]=0;   i--;}
                        break;
        }
    }
}

// Dizilerde atanmayan her eleman 0 olarak atandýðýndan
// öncelikle tamamen duvarlardan oluþan bir alan oluþturuldu
void labirent_tahtasi_uret(int *labirent[][BOYUT])
{
    int i,j;
    for(i=0; i<BOYUT; i++)
        for(j=0; j<BOYUT; j++)
            labirent[i][j] = 1;
}

// Her giriþten sonra gidilen yerleri iþaretlediðinden
// bir sonraki giriþe geçmeden önce labirent ilk haline getirildi
void labirent_sifirla(int *labirent[][BOYUT])
{
    int i,j;
    for(i=0; i<BOYUT; i++)
        for(j=0; j<BOYUT; j++)
            if(labirent[i][j]==GIDILDI)
                labirent[i][j]=0;
}

//Labirenti .txt dosyasına kaydetme fonksiyonu
void dosyaya_yaz(int *labirent[][BOYUT])
{
    int i,j;
    FILE *olusturulan_labirent;
    olusturulan_labirent = fopen("labirent.txt","a");
    if(olusturulan_labirent != NULL){
        fprintf(olusturulan_labirent,"-----------------------------------------\n\n\n");
        fprintf(olusturulan_labirent,"{");
        for(i=0; i<BOYUT;i++){
            fprintf(olusturulan_labirent,"{");
           for(j=0; j<BOYUT; j++){
               if(j!=29)
               fprintf(olusturulan_labirent,"%d,",labirent[i][j]);
               else
               fprintf(olusturulan_labirent,"%d",labirent[i][j]);
                }
                if(i!=29)
                fprintf(olusturulan_labirent,"},\n");
                else
                fprintf(olusturulan_labirent,"}");
            }
            fprintf(olusturulan_labirent,"}\n");
            fprintf(olusturulan_labirent,"\n\n-----------------------------------------\n\n\n");
            fclose(olusturulan_labirent);
        }
}

void rastgele_bosluklar(int *labirent[][BOYUT])
{
    srand(time(NULL));
    int i,j,giris;
    for(giris=0; giris<5; giris++){
        i= rand()%29;
        labirent[i][0]=0;}
    for(i=1; i<BOYUT; i++)
        for(j=1; j<BOYUT-1; j++)
            if(labirent[i][j]==1)
            labirent[i][j]= rand()%2;
}
