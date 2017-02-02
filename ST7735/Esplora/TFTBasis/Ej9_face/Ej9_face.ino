#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

// These definitions map display functions to the Adduino UNO display header pins
#define sclk 15
#define mosi 16
#define cs   7
#define dc   0
#define rst  1
    
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


int width, height;

void setup() {
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2);

  tft.setRotation(0); 
  tft.fillScreen(BLUE);

  width = tft.width();
  height = tft.height();

  //Un rectangulo requiere de 5 parametros. Posicion --> Esquina superior izquierda
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Anchura --> Distancia en pixeles
  // Altura --> Distancia en pixeles
  // Color --> En hexadecimal

  //Dibujar una cara con dos cuadrados y un rectangulo debajo
  
    //Dibujar dos cuadrados en linea en el centro de la pantalla de 50 pixeles de lado con una separacion de 30 pixeles
  
    // Dimensiones del rectangulo
    int lsize = 60;
    int space = 50;
    
    // Posicion del primer cuadrado
    int x1 = width/2 - lsize - space/2;
    int y1 = height/2 - lsize /2;
  
    uint16_t color1 = ROSE;
    
    tft.fillRect(x1, y1, lsize, lsize, color1);
  
    // Posicion del segundo cuadrado
    int x2 = width/2 +space/2;
    int y2 = height/2 - lsize /2;
  
    uint16_t color2 = YELLOW;
    
    tft.fillRect(x2, y2, lsize, lsize, color2);

   // Dibujar rectangulo debajo de 150 pixeles de largo y 30 de ancho a una distancia de 40 pixeles de los ojos

   tft.fillRect(width/2-150/2, y1+lsize+40, 150, 30, color2);
}

void loop() {

}
