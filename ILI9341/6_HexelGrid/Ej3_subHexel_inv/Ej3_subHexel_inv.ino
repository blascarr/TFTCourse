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
int col, row;

void setup() {
  Serial.begin(9600);
  tft.begin(); // Begin ILI9341
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
    
    tft.drawTriangle(   0, h, w/3, 0 , 0, 0, color);
    tft.drawTriangle(   0, h, w/2, h/2 , w/3, 0, color);
    tft.drawTriangle(   0, h, 2*w/3, h , w/2, h/2, color);
    tft.drawTriangle(   w, 0, 2*w/3, h, w, h , color);
    tft.drawTriangle(   w, 0, w/2, h/2, 2*w/3, h , color);
    tft.drawTriangle(   w, 0, w/3, 0 , w/2, h/2 , color);
    
    //borderCorrection();
}

void borderCorrection(){
  tft.drawFastHLine(-2, -1, width,  BLACK);
  tft.drawFastVLine(-2, -1, height,  BLACK);
  tft.drawFastVLine(-1, -1, height,  BLACK);
}
