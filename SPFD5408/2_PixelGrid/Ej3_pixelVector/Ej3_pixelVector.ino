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

//Creamos una clase apropiada para acumular datos de pixel en la malla con dos parametros x e y
class Pixel {
 public:
  Pixel(void){
    x = y = 0;
  };
  
  Pixel(int16_t x0, int16_t y0){
    x = x0;
    y = y0;
  };

  int16_t x, y;
};


void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

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
   Pixel(2,18),
   Pixel(2,17),
   Pixel(3,16),
   Pixel(4,15),
   Pixel(4,14),
   Pixel(4,13),
   Pixel(4,12),
   Pixel(4,11),
   Pixel(5,10),
   Pixel(5,9),
   Pixel(6,8),
   Pixel(7,9),
   Pixel(7,10),
   Pixel(8,11),
   Pixel(8,12),
   Pixel(8,13),
   Pixel(8,14),
   Pixel(8,15),
   Pixel(9,16),
   Pixel(10,17),
   Pixel(10,18),    
  };

  //Con un control en bucle podemos hacer que se dibujen todos ellos
  for (int n; n < sizeof(pixelVector); n++){
    drawPixelGrid(pixelVector[n].x, pixelVector[n].y);
  }
}

void loop() {

}

void drawPixelGrid(int row, int col){
  
  int rowpos = row-1;
  int colpos = col-1;

  tft.fillRect(rowpos*w, colpos*h, w, h, BLACK);
  
}
