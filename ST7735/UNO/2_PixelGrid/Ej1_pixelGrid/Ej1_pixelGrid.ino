#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

// These definitions map display functions to the Adduino UNO display header pins
#define sclk 15
#define mosi 16
#define cs   7
#define dc   6
#define rst  5
    
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
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2)

  tft.setRotation(0); 
  tft.fillScreen(YELLOW);

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
