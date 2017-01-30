#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library

//Arduino UNO Pin Definition 
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//Declaracion objeto TFT
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//Variables globales de TFT y de malla
int width, height;
  //Numero de filas, columnas, anchura y altura de subpixel
int col, row;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(1); 
  tft.fillScreen(YELLOW);

  width = tft.width();
  height = tft.height();

  //Ahora subdiviremos los triangulos en otros subtriangulos con las coordenadas definidas para crear una subdivision denominada subhexel
  //Pero ahora que podemos definir si queremos dibujarlo de forma invertida vamos a desarrollar nuestra funcion para definir los sutriangulos en un conjunto de 4 zonas.

  //Estas zonas se denominan cuadrantes y tenemos que operar entre ellos para desarrollar una malla completa.
  //Al igual que la funcion drawRect, vamos a desarrollar 4 parametros adicionales para determinar la posicion de inicio en X y en Y, la anchura, la altura y una condicion de inversion para que se cree la malla
  
  int posx = 0;
  int posy=0;
  
  subhexel(posx, posy, width/2, height/2, 1, BLACK);
  subhexel(posx+width/2, posy, width/2, height/2, 0, BLACK);
  subhexel(posx, posy+height/2, width/2, height/2, 0, BLACK);
  subhexel(posx+width/2, posy+height/2, width/2, height/2, 1, BLACK);
  
}

void loop() {

}

void subhexel(float pos_x, float pos_y, int w , int h, bool sym, uint16_t color){

    float PX[] = {0 + pos_x ,w/3 + pos_x, w/2 + pos_x, 2*w/3 + pos_x, w + pos_x};
    float PY[]= {0 + pos_y, h/2+ pos_y, h+ pos_y};
    
    if (!sym){

      PY[0] = h + pos_y;
      PY[1] = h/2 + pos_y;
      PY[2] = 0 + pos_y;
    }

    //Vamos a crear 6 subtriangulos dentro de el area determinada 
    
    tft.drawTriangle(   PX[0], PY[0], PX[1], PY[2] , PX[0], PY[2], color);
    tft.drawTriangle(   PX[0], PY[0], PX[2], PY[1] , PX[1], PY[2], color);
    tft.drawTriangle(   PX[0], PY[0], PX[3], PY[0] , PX[2], PY[1], color);
    
    tft.drawTriangle(   PX[4], PY[2], PX[3], PY[0], PX[4], PY[0] , color);
    tft.drawTriangle(   PX[4], PY[2], PX[2], PY[1], PX[3], PY[0] , color);
    tft.drawTriangle(   PX[4], PY[2], PX[1], PY[2] , PX[2], PY[1] , color);
    
    //borderCorrection();
}

void borderCorrection(){
  tft.drawFastHLine(-2, -1, width,  BLACK);
  tft.drawFastVLine(-2, -1, height,  BLACK);
  tft.drawFastVLine(-1, -1, height,  BLACK);
}
