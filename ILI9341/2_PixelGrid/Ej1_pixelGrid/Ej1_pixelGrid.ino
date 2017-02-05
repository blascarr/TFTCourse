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
  int col = 12;
  int row = 20;

  // Dividimos la anchura y la altura para determinar cuanto medira cada cuadrado
  int w = width/col;
  int h = height/row;
  
  for(int i = 0; i < col; ++i){
      for(int j=0; j< row; j++){

          tft.drawRect(i*w, j*h, w, h, BLACK);
      }
  }

  //Dibujar un cuadrado en la fila 3 y columna 6
  int rowpos = 3;
  int colpos = 6;

  tft.fillRect(colpos*w, rowpos*h, w, h, BLACK);
  
  //La posicion no sera correcta debido a que se tiene en cuenta el 0, por lo que hay que restar una fila y una columna
  //Si modificamos la rotacion seguira estando bien, ya que hemos dispuesto de referencias
}

void loop() {

}
