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

  //Una linea requiere de 4 parametros. Posicion inicial --> Esquina superior izquierda
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Longitud --> Distancia en pixeles
  // Color --> En hexadecimal

  // Hay que crear una malla con un offset de 50 pixeles en x y 45 pixeles en y
  // Un offset es una ligera separacion de el origen que sirve para compensar un error de desplazamiento 
  // Las filas y columnas se desplazan demasiado con respecto a la zona visible de la pantalla.
  // Plantea una solucion para que sigan apareciendo el numero de filas y columnas definido a pesar de el offset excesivo
  int offset_x = 50;
  int offset_y = 45;

  // Hay un numero de filas y columnas definido con las funciones drawFastHLine y drawFastVLine

  // Numero de filas 8 y numero de columnas 8
  
  int rows = 8;
  int columns = 8;

  //La relacion de separacion de columnas se define como la separacion de anchura entre columna y columna
  //La relacion de separacion de filas se define como la separacion de altura entre fila y fila
  int w = width/columns;
  int h = height/rows;
  
  if(offset_x > w){
  //Escribir la solucion al desplazamiento en x en una linea
    
  }

  if(offset_y > h ){
  //Escribir la solucion al desplazamiento en y en una linea
  
  }
  
  //Dibujar las lineas horizontales
  for (int i; i <rows; i++){
    tft.drawFastHLine(0, offset_y + i*h, width, BLACK);
  }

  //Dibujar las lineas horizontales
  for (int i; i <columns; i++){
    tft.drawFastVLine( offset_x + i*w, 0, height, BLACK);
  }
}


void loop() {

}
