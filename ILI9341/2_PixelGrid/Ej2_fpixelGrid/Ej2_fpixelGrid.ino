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
int w, h, col, row;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(GREEN);

  width = tft.width();
  height = tft.height();

  //Un rectangulo requiere de 5 parametros. Posicion --> Esquina superior izquierda
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Anchura --> Distancia en pixeles
  // Altura --> Distancia en pixeles
  // Color --> En hexadecimal

  //Dibujar una malla con un numero de filas y columnas definido y dibujar un cuadrado eligiendo el numero de fila y columna correspondiente

  //Dibujo de malla
  // 12 columnas y 20 filas
  col = 12;
  row = 20;

  // Dividimos la anchura y la altura para determinar cuanto medira cada cuadrado
  w = width/col;
  h = height/row;
  
  for(int i = 0; i < col; ++i){
      for(int j=0; j< row; j++){

          tft.drawRect(i*w, j*h, w, h, BLACK);
      }
  }
  
  drawPixelGrid(7,12);
}

void loop() {

}

void drawPixelGrid(int row, int col){
  
  int rowpos = row-1;
  int colpos = col-1;

  tft.fillRect(rowpos*w, colpos*h, w, h, BLACK);
  
}
