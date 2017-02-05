#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ILI9341.h> // Hardware-specific library

#define TFT_CS   7
#define TFT_DC   6

// Assign human-readable names to some common 16-bit color values:
#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define PINK        0xF81F

//Declaracion objeto TFT
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int width, height;

void setup() {
  Serial.begin(9600);
  tft.begin(); // Begin ILI9341

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
  tft.fillTriangle(X1,Y1,X2,Y2,CX,CY,GREEN);
  tft.fillTriangle(X2,Y2,X3,Y3,CX,CY,BLUE);
  tft.fillTriangle(X3,Y3,X4,Y4,CX,CY,RED);
  tft.fillTriangle(X4,Y4,X1,Y1,CX,CY,YELLOW);
  
}


void loop() {

}
