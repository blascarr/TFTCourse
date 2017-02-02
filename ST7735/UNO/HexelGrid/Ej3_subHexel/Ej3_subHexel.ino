#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

// These definitions map display functions to the Adduino UNO display header pins
#define sclk 15
#define mosi 16
#define cs   7
#define dc   6
#define rst  5
    
// Assign human-readable names to some common 16-bit color values:
  #define BLACK 0x0000
  #define WHITE 0xFFFF
  #define BLUE 0x001F
  #define GREEN   0x07E0
  #define YELLOW 0xFFE0 
  #define RED     0xF800
  #define BROWN 0x99AA66
  #define CYAN    0x07FF
  #define MAGENTA 0xF81F

//Declaracion objeto TFT
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);


//Variables globales de TFT y de malla
int width, height;
  //Numero de filas, columnas, anchura y altura de subpixel
int col, row;

void setup() {
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2)

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
    
    tft.drawTriangle(   0, 0, w/3, h , 0, h, color);
    tft.drawTriangle(   0, 0, w/2, h/2 , w/3, h, color);
    tft.drawTriangle(   0, 0, 2*w/3, 0 , w/2, h/2, color);
    
    tft.drawTriangle(   w, h, 2*w/3, 0, w, 0 , color);
    tft.drawTriangle(   w, h, w/2, h/2, 2*w/3, 0 , color);
    tft.drawTriangle(   w, h, w/3, h , w/2, h/2 , color);
    
    //borderCorrection();
}

void borderCorrection(){
  tft.drawFastHLine(-2, -1, width,  BLACK);
  tft.drawFastVLine(-2, -1, height,  BLACK);
  tft.drawFastVLine(-1, -1, height,  BLACK);
}
