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

//Variables globales de TFT y de malla
int width, height;
  //Numero de filas, columnas, anchura y altura de subpixel
int w, h, col, row;

//Creamos una clase apropiada para acumular datos de pixel en la malla con 3 parametros x, y y el color
class Pixel {
 public:
  Pixel(void){
    x = y = 0;
  };
  
  Pixel(int16_t x0, int16_t y0){
    x = x0;
    y = y0;
    color = BLACK;
  };
  
  Pixel(int16_t x0, int16_t y0, uint16_t color0){
    x = x0;
    y = y0;
    color = color0;
  };

  int16_t x, y;
  uint16_t color;
};


void setup() {
  Serial.begin(9600);
  tft.begin(); // Begin ILI9341

  tft.setRotation(0); 
  tft.fillScreen(GREEN);

  width = tft.width();
  height = tft.height();

  //Ahora vamos a rellenar las filas y columnas mediante el uso de un vector en el que guardaremos en cada espacio del vector, cada una de las coordenadas a dibujar 

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

  //En lugar de utilizar un pixel de forma individual vamos a crear un vector de pixeles para dibujar
  Pixel pixelVector[] = {
   Pixel(2,18,YELLOW),
   Pixel(2,17,YELLOW),
   Pixel(3,16,RED),
   Pixel(4,15, BLUE),
   Pixel(4,14, BLUE),
   Pixel(4,13, BLUE),
   Pixel(4,12, BLUE),
   Pixel(4,11, BLUE),
   Pixel(5,10, BLACK),
   Pixel(5,9, BLACK),
   Pixel(6,8, YELLOW),
   Pixel(7,9, BLACK),
   Pixel(7,10, BLACK),
   Pixel(8,11, BLUE),
   Pixel(8,12, BLUE),
   Pixel(8,13, BLUE),
   Pixel(8,14, BLUE),
   Pixel(8,15, BLUE),
   Pixel(9,16,RED),
   Pixel(10,17,YELLOW),
   Pixel(10,18,YELLOW),    
  };

  //Con un control en bucle podemos hacer que se dibujen todos ellos
  for (int n; n < sizeof(pixelVector); n++){
    drawPixelGrid(pixelVector[n].x, pixelVector[n].y, pixelVector[n].color);
  }
}

void loop() {

}

void drawPixelGrid(int row, int col, uint16_t color){
  
  int rowpos = row-1;
  int colpos = col-1;

  tft.fillRect(rowpos*w, colpos*h, w, h, color);
  
}
