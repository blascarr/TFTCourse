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

  // Un triangulo requiere de 7 parametros. Posicion del punto P1, P2, P3 y el color
  // Posicion inicial X1 --> Direccion horizontal (De izquierda a derecha)
  // Posicion inicial Y1 --> Direccion vertical (De arriba a abajo)
  // Posicion inicial X2 --> Direccion horizontal (De izquierda a derecha)
  // Posicion inicial Y2 --> Direccion vertical (De arriba a abajo)
  // Posicion inicial X3 --> Direccion horizontal (De izquierda a derecha)
  // Posicion inicial Y3 --> Direccion vertical (De arriba a abajo)
  // Color --> En hexadecimal

  // Hay que dibujar un cuadrado de lado 100 pixeles en el centro con una cruz en su interior que conecte sus esquinas
  // Pero esta vez vamos a realizar este ejercicio con 4 triangulos que subdividen el cuadrado en 4 partes

  // Hay que dibujar 4 triangulos que conecten todos con su centro
  int length = 100;

  // Definimos las coordenadoas de los 4 puntos que definen el cuadrado mas su centro
  int X1 = (width-length)/2;
  int Y1 = (height-length)/2;
  int X2 = (width+length)/2;
  int Y2 = (height-length)/2;
  int X3 = (width+length)/2;
  int Y3 = (height+length)/2;
  int X4 = (width-length)/2;
  int Y4 = (height+length)/2;

  //Coordenadas del centro del cuadrado
  int CX = width/2;
  int CY = height/2; 
   
  //Triangulos
  tft.drawTriangle(X1,Y1,X2,Y2,CX,CY,GREEN);
  tft.drawTriangle(X2,Y2,X3,Y3,CX,CY,BLUE);
  tft.drawTriangle(X3,Y3,X4,Y4,CX,CY,RED);
  tft.drawTriangle(X4,Y4,X1,Y1,CX,CY,YELLOW);
  
}


void loop() {

}
