#include "Nokia_5110.h"



const unsigned char tablo1 [240] = {        
                                                0x00,0x00,0x00,0x00,0x00,        // 20 space
                                                0x00,0x00,0x5f,0x00,0x00,        // 21 !
                                                0x00,0x07,0x00,0x07,0x00,        // 22 "
                                                0x14,0x7f,0x14,0x7f,0x14,        // 23 #
                                                0x24,0x2a,0x7f,0x2a,0x12,        // 24 $
                                                0x23,0x13,0x08,0x64,0x62,        // 25 %
                                                0x36,0x49,0x55,0x22,0x50,        // 26 &
                                                0x00,0x05,0x03,0x00,0x00,        // 27 '
                                                0x00,0x1c,0x22,0x41,0x00,        // 28 (
                                                0x00,0x41,0x22,0x1c,0x00,        // 29 )
                                                0x14,0x08,0x3e,0x08,0x14,        // 2a *
                                                0x08,0x08,0x3e,0x08,0x08,        // 2b +
                                                0x00,0x50,0x30,0x00,0x00,        // 2c ,
                                                0x08,0x08,0x08,0x08,0x08,        // 2d -
                                                0x00,0x60,0x60,0x00,0x00,        // 2e .
                                                0x20,0x10,0x08,0x04,0x02,        // 2f /
                                                0x3e,0x51,0x49,0x45,0x3e,        // 30 0
                                                0x00,0x42,0x7f,0x40,0x00,        // 31 1
                                                0x42,0x61,0x51,0x49,0x46,        // 32 2
                                                0x21,0x41,0x45,0x4b,0x31,        // 33 3
                                                0x18,0x14,0x12,0x7f,0x10,        // 34 4
                                                0x27,0x45,0x45,0x45,0x39,        // 35 5
                                                0x3c,0x4a,0x49,0x49,0x30,        // 36 6
                                                0x01,0x71,0x09,0x05,0x03,        // 37 7
                                                0x36,0x49,0x49,0x49,0x36,        // 38 8
                                                0x06,0x49,0x49,0x29,0x1e,        // 39 9
                                                0x00,0x36,0x36,0x00,0x00,        // 3a :
                                                0x00,0x56,0x36,0x00,0x00,        // 3b ;
                                                0x08,0x14,0x22,0x41,0x00,        // 3c <
                                                0x14,0x14,0x14,0x14,0x14,        // 3d =
                                                0x00,0x41,0x22,0x14,0x08,        // 3e >
                                                0x02,0x01,0x51,0x09,0x06,        // 3f ?
                                                0x32,0x49,0x79,0x41,0x3e,        // 40 @
                                                0x7e,0x11,0x11,0x11,0x7e,        // 41 A
                                                0x7f,0x49,0x49,0x49,0x36,        // 42 B
                                                0x3e,0x41,0x41,0x41,0x22,        // 43 C
                                                0x7f,0x41,0x41,0x22,0x1c,        // 44 D
                                                0x7f,0x49,0x49,0x49,0x41,        // 45 E
                                                0x7f,0x09,0x09,0x09,0x01,        // 46 F
                                                0x3e,0x41,0x49,0x49,0x7a,        // 47 G
                                                0x7f,0x08,0x08,0x08,0x7f,        // 48 H
                                                0x00,0x41,0x7f,0x41,0x00,        // 49 I
                                                0x20,0x40,0x41,0x3f,0x01,        // 4a J
                                                0x7f,0x08,0x14,0x22,0x41,        // 4b K
                                                0x7f,0x40,0x40,0x40,0x40,        // 4c L
                                                0x7f,0x02,0x0c,0x02,0x7f,        // 4d M
                                                0x7f,0x04,0x08,0x10,0x7f,        // 4e N
                                                0x3e,0x41,0x41,0x41,0x3e};        // 4f O

const unsigned char tablo2 [241] = {
                                  0x7f,0x09,0x09,0x09,0x06,        // 50 P
                                                0x3e,0x41,0x51,0x21,0x5e,        // 51 Q
                                                0x7f,0x09,0x19,0x29,0x46,        // 52 R
                                                0x46,0x49,0x49,0x49,0x31,        // 53 S
                                                0x01,0x01,0x7f,0x01,0x01,        // 54 T
                                                0x3f,0x40,0x40,0x40,0x3f,        // 55 U
                                                0x1f,0x20,0x40,0x20,0x1f,        // 56 V
                                                0x3f,0x40,0x38,0x40,0x3f,        // 57 W
                                                0x63,0x14,0x08,0x14,0x63,        // 58 X
                                                0x07,0x08,0x70,0x08,0x07,        // 59 Y
                                                0x61,0x51,0x49,0x45,0x43,        // 5a Z
                                                0x00,0x7f,0x41,0x41,0x00,        // 5b [
                                                0x02,0x04,0x08,0x10,0x20,        // 5c //
                                                0x00,0x41,0x41,0x7f,0x00,        // 5d ñ
                                                0x04,0x02,0x01,0x02,0x04,        // 5e ^
                                                0x40,0x40,0x40,0x40,0x40,        // 5f _
                                                0x00,0x01,0x02,0x04,0x00,        // 60 `
                                                0x20,0x54,0x54,0x54,0x78,        // 61 a
                                                0x7f,0x48,0x44,0x44,0x38,        // 62 b
                                                0x38,0x44,0x44,0x44,0x20,        // 63 c
                                                0x38,0x44,0x44,0x48,0x7f,        // 64 d
                                                0x38,0x54,0x54,0x54,0x18,        // 65 e
                                                0x08,0x7e,0x09,0x01,0x02,        // 66 f
                                                0x0c,0x52,0x52,0x52,0x3e,        // 67 g
                                                0x7f,0x08,0x04,0x04,0x78,        // 68 h
                                                0x00,0x44,0x7d,0x40,0x00,        // 69 i
                                                0x20,0x40,0x44,0x3d,0x00,        // 6a j
                                                0x7f,0x10,0x28,0x44,0x00,        // 6b k
                                                0x00,0x41,0x7f,0x40,0x00,        // 6c l
                                                0x7c,0x04,0x18,0x04,0x78,        // 6d m
                                                0x7c,0x08,0x04,0x04,0x78,        // 6e n
                                                0x38,0x44,0x44,0x44,0x38,        // 6f o
                                                0x7c,0x14,0x14,0x14,0x08,        // 70 p
                                                0x08,0x14,0x14,0x18,0x7c,        // 71 q
                                                0x7c,0x08,0x04,0x04,0x08,        // 72 r
                                                0x48,0x54,0x54,0x54,0x20,        // 73 s
                                                0x04,0x3f,0x44,0x40,0x20,        // 74 t
                                                0x3c,0x40,0x40,0x20,0x7c,        // 75 u
                                                0x1c,0x20,0x40,0x20,0x1c,        // 76 v
                                                0x3c,0x40,0x30,0x40,0x3c,        // 77 w
                                                0x44,0x28,0x10,0x28,0x44,        // 78 x
                                                0x0c,0x50,0x50,0x50,0x3c,        // 79 y
                                                0x44,0x64,0x54,0x4c,0x44,        // 7a z
                                                0x00,0x08,0x36,0x41,0x00,        // 7b {
                                                0x00,0x00,0x7f,0x00,0x00,        // 7c |
                                                0x00,0x41,0x36,0x08,0x00,        // 7d }
                                                0x10,0x08,0x08,0x10,0x08,        // 7e ~
                                                0x78,0x46,0x41,0x46,0x78};        // 7f ¦



																								
void NOKIA_Write_Byte(char byteforNOKIA)        
{
        char i;
        for(i=8;i>0;i--)
        {
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
								DWT_Delay(2);
                if((byteforNOKIA & 0x80)==0x00)
                        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
                else
                        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
                DWT_Delay(2);
                byteforNOKIA = byteforNOKIA << 1;
           }
}

void NOKIA_Write_Data(char NOKIA_data)
{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);        // Data gönderimi için D/C=1
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);       // Chip aktif
        NOKIA_Write_Byte(NOKIA_data);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);        // Chip pasif
}
                                                


void NOKIA_Write_Command(char NOKIA_command)
{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);        // Komut gönderimi için D/C=0;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);        // Chip aktif
        NOKIA_Write_Byte(NOKIA_command);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);        // Chip pasif
}


void NOKIA_Goto_xy(char xNOKIA,char yNOKIA)                        // Ýstenilen bölgeye ulaþma fonksiyonu
{
        NOKIA_Write_Command(0x40|(xNOKIA & 0x07));                // Y bu þekilde hareket ediyor: 0100 0yyy
        NOKIA_Write_Command(0x80|(yNOKIA & 0x7F));                // X bu þekilde hareket ediyor: 1xxx xxxx
}
                                                
void NOKIA_Clear(void)
{
        int ddram,i;
        NOKIA_Goto_xy(0,0);                                        // 84*6=504bit Dram alaný temizleniyor
        for(ddram=0; ddram<504; ddram++)
        NOKIA_Write_Data(0x00);
}

void NOKIA_Image(const char *image)
{
 int i=0;
 NOKIA_Goto_xy(0,0);
 for(i=0;i<504;i++)
 {
  NOKIA_Write_Data(image[i]);
 }
}

 
                                                


void NOKIA_Init(void)
{
/*nok_res_dir =0;
        nok_sce_dir =0;
        nok_dc_dir  =0;
        nok_sdin_dir=0;
        nok_sclk_dir=0;*/
				
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
				
				DWT_Init();
        
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);        // Bilgiler DDRAM'de tutuluyor, Address counter ise otomatik artacak
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);      // Chip pasif
				DWT_Delay(200);
	
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);  //Baþlangýçta res=0 olmak zoruna, aksi halde LCD'ye zarar gelebilir
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);

        NOKIA_Write_Command(0x21);        // LCD'ye komut yazýlýyor.
				// Indicator koy
        NOKIA_Write_Command(0xC8);        // Vop  V: 0xC8 (for 3V)
        NOKIA_Write_Command(0x13);        // LCD (1:48) modunda (bias)
        NOKIA_Write_Command(0x20);        // Soldan saða x birer artýrýlarak yazýlýyor
                                                                // 0x22 kullanýlsaydý, yukarýdan aþaðý yazýcaktý.
        NOKIA_Write_Command(0x09);        // Displayi aktif hale getir
        HAL_Delay(50);

        NOKIA_Clear();                // DDRAM temizleniyor, aksi halde eski yazýlmýþ karekterlerle karýþtýrýlabilinir
        HAL_Delay(10);

        NOKIA_Write_Command(0x08);        // Display temizleniyor
        HAL_Delay(10);

        NOKIA_Write_Command(0x0C);        // Display normal moda dönüyor
}



void NOKIA_Chr(char xNOKIA,char yNOKIA, char charsel)                        // ASCII tablosunu kullanarak yazý yazdýrmaya yarayan fonksiyon
{
        char char_row,charpos,chardata;
        if(xNOKIA>0) xNOKIA-=1;
        if(yNOKIA>0) yNOKIA-=1;
        yNOKIA*=6;
        NOKIA_Goto_xy(xNOKIA,yNOKIA);

        if (charsel<0x20) return;
        if (charsel>0x7f) return;

        for(char_row=0;char_row<5;char_row++)
        {
                if(charsel<0x50)                // Seçilen karekterin ASCII kodu 50h'tan ufaksa
                {
                        charpos=(((charsel&0xff)-0x20)*5);
                        chardata=tablo1[(charpos+char_row)];
                }
                if(charsel>0x4f)                // Seçilen karekterin ASCII kodu 50h'tan büyükse
                {
                        charpos=(((charsel&0xff)-0x50)*5);
                        chardata=tablo2[(charpos+char_row)];
                }

                NOKIA_Write_Data(chardata);        // Datayý gönder
        }
        NOKIA_Write_Data(0x00);                        // Her zaman 1 bytelýk son alan boþ olacak
}

void NOKIA_Chr_for_NOKIA_out(char xNOKIA,char yNOKIA, char charsel)                        // ASCII tablosunu kullanarak yazý yazdýrmaya yarayan fonksiyon
{
        char char_row,charpos,chardata;
        NOKIA_Goto_xy(xNOKIA,yNOKIA);

        if (charsel<0x20) return;
        if (charsel>0x7f) return;

        for(char_row=0;char_row<5;char_row++)
        {
                if(charsel<0x50)                // Seçilen karekterin ASCII kodu 50h'tan ufaksa
                {
                        charpos=(((charsel&0xff)-0x20)*5);
                        chardata=tablo1[(charpos+char_row)];
                }
                if(charsel>0x4f)                // Seçilen karekterin ASCII kodu 50h'tan büyükse
                {
                        charpos=(((charsel&0xff)-0x50)*5);
                        chardata=tablo2[(charpos+char_row)];
                }

                NOKIA_Write_Data(chardata);        // Datayý gönder
        }
        NOKIA_Write_Data(0x00);                        // Her zaman 1 bytelýk son alan boþ olacak
}





void NOKIA_Contrast(char contrast)
{
    NOKIA_Write_Command(0x21);                  // LCD'ye komut veriliyor
    NOKIA_Write_Command(0x80 | contrast);       // Kontrast ayarý
    NOKIA_Write_Command(0x20);                  // Yatay adresleme modu, X birer otomatik artar.
}



void NOKIA_Out(char xNOKIA,char yNOKIA, const char *s)
{
        if(xNOKIA>0) xNOKIA-=1;
        if(yNOKIA>0) yNOKIA-=1;
        NOKIA_Goto_xy(xNOKIA,  yNOKIA);
        yNOKIA*=6;
        while(*s)
                {
                 NOKIA_Chr_for_NOKIA_out( xNOKIA , yNOKIA, *s++);
                 yNOKIA+=6;
                }
                
}


//void NOKIA_Goto_pixel(char xNOKIA,char yNOKIA)                        // Ýstenilen bölgeye ulaþma fonksiyonu
//{
//        NOKIA_Write_Command(0x40|(yNOKIA & 0x07));                // Y bu þekilde hareket ediyor: 0100 0yyy
//        NOKIA_Write_Command(0x80|(xNOKIA & 0x7F));                // X bu þekilde hareket ediyor: 1xxx xxxx
//}

void NOKIA_Dot (char xNOKIA, char yNOKIA)
{
        char offset,datar;

        if (xNOKIA > 84) return;
        if (yNOKIA > 48) return;

        offset = yNOKIA - ((yNOKIA / 8) * 8);
        datar = (0x01 << offset);
        NOKIA_Goto_pixel(xNOKIA, (yNOKIA/8)); //Hata olursa bakilacak GotoPixel kullan
        NOKIA_Write_Data(datar);
}

void NOKIA_Goto_pixel(char xNOKIA,char yNOKIA)                        // Ýstenilen bölgeye ulaþma fonksiyonu
{
        NOKIA_Write_Command(0x40|(yNOKIA & 0x07));                // Y bu þekilde hareket ediyor: 0100 0yyy
        NOKIA_Write_Command(0x80|(xNOKIA & 0x7F));                // X bu þekilde hareket ediyor: 1xxx xxxx
}

void NOKIA_Partial_Image(char xNOKIA, char yNOKIA, char xImage, char array_length, const char *image)
{
    char j=0,sayac=0;
    NOKIA_Goto_xy(xNOKIA,yNOKIA);
    for(sayac=0;sayac<array_length;sayac++)
    {
     if(sayac > xImage     && sayac < (2*xImage))NOKIA_Goto_xy((xNOKIA+1),(yNOKIA+(sayac-xImage)));
     if(sayac > (2*xImage) && sayac < (3*xImage))NOKIA_Goto_xy((xNOKIA+2),(yNOKIA+(sayac-2*xImage)));
     if(sayac > (3*xImage) && sayac < (4*xImage))NOKIA_Goto_xy((xNOKIA+3),(yNOKIA+(sayac-3*xImage)));
     if(sayac > (4*xImage) && sayac < (5*xImage))NOKIA_Goto_xy((xNOKIA+4),(yNOKIA+(sayac-4*xImage)));
     if(sayac > (5*xImage) && sayac < (6*xImage))NOKIA_Goto_xy((xNOKIA+5),(yNOKIA+(sayac-5*xImage)));
     if(sayac > (6*xImage) && sayac < (7*xImage))NOKIA_Goto_xy((xNOKIA+6),(yNOKIA+(sayac-6*xImage)));
     NOKIA_Write_Data(image[sayac]);
    }
}

//HAL_GPIO_WritePin(GPIOA, SDIN_Pin, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, SCLK_Pin, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, SCE_Pin, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, RES_Pin, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, DC_Pin, GPIO_PIN_RESET);
