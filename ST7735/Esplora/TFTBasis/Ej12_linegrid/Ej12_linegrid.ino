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
  tft.fillScreen(WHITE);

  width = tft.width();
  height = tft.height();

  //Una linea recta requiere de 4 parametros. Posicion inicial, longitud y color
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Longitud --> Distancia en pixeles
  // Color --> En hexadecimal

  // Hay que crear una malla con un numero de filas y columnas definido con las funciones drawFastHLine y drawFastVLine

  // Numero de filas 20 y numero de columnas 12
  
  int rows = 20;
  int columns = 12;

  //La relacion de separacion de columnas se define como la separacion de anchura entre columna y columna
  //La relacion de separacion de filas se define como la separacion de altura entre fila y fila
  int w = width/columns;
  int h = height/rows;
  
  //Dibujar las lineas horizontales
  for (int i; i <rows; i++){
    tft.drawFastHLine(0, i*h, width, BLACK);
  }

  //Dibujar las lineas horizontales
  for (int i; i <columns; i++){
    tft.drawFastVLine( i*w, 0, height, BLACK);
  }
}

void loop() {

}
