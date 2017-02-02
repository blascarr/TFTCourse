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

  // Una linea requiere de 5 parametros. Posicion inicial y posicion final
  // Posicion inicial X0 --> Direccion horizontal (De izquierda a derecha)
  // Posicion inicial Y0 --> Direccion vertical (De arriba a abajo)
  // Posicion inicial Xf --> Direccion horizontal (De izquierda a derecha)
  // Posicion inicial Yf --> Direccion vertical (De arriba a abajo)
  // Color --> En hexadecimal

  // Hay que dibujar un cuadrado de lado 100 pixeles en el centro con una cruz en su interior que conecte sus esquinas

  // Definimos las coordenadoas de los 4 puntos que definen el cuadrado

  // Hay que dibujar 6 lineas. 4 para realizar un cuadrado y 2 para la cruz
  int length = 100;
  
  int X1 = (width-length)/2;
  int Y1 = (height-length)/2;
  int X2 = (width+length)/2;
  int Y2 = (height-length)/2;
  int X3 = (width+length)/2;
  int Y3 = (height+length)/2;
  int X4 = (width-length)/2;
  int Y4 = (height+length)/2;

  //Lineas de aristas
  tft.drawLine(X1,Y1,X2,Y2,BLACK);
  tft.drawLine(X2,Y2,X3,Y3,BLUE);
  tft.drawLine(X3,Y3,X4,Y4,ROSE);
  tft.drawLine(X4,Y4,X1,Y1,YELLOW);

  //Lineas diagonales
  tft.drawLine(X1,Y1,X3,Y3,BLACK);
  tft.drawLine(X2,Y2,X4,Y4,BLACK);
  
}


void loop() {

}
