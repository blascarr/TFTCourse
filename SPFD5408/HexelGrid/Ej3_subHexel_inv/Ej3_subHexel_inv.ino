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

  //Numero de columnas *Solo necesitamos conocer las columnas, ya que las filas las calcularemos mediante una formula trigonometricae base a este numero.
  col = 17;
  
  subhexel(BLACK);
}

void loop() {

}

void subhexel(uint16_t color){

    float w = width;
    float h = height;
    //w*sqrt(4/3);
    //Vamos a crear 6 subtriangulos dentro de un area determinada 
    
    tft.drawTriangle(   0, h, w/3, 0 , 0, 0, color);
    tft.drawTriangle(   0, h, w/2, h/2 , w/3, 0, color);
    tft.drawTriangle(   0, h, 2*w/3, h , w/2, h/2, color);
    tft.drawTriangle(   w, 0, 2*w/3, h, w, h , color);
    tft.drawTriangle(   w, 0, w/2, h/2, 2*w/3, h , color);
    tft.drawTriangle(   w, 0, w/3, 0 , w/2, h/2 , color);
    
    //borderCorrection();
}

void borderCorrection(){
  tft.drawFastHLine(-2, -1, width,  BLACK);
  tft.drawFastVLine(-2, -1, height,  BLACK);
  tft.drawFastVLine(-1, -1, height,  BLACK);
}
