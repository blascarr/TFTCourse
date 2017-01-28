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

int width, height;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

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
