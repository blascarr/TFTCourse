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
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2);

  tft.setRotation(0); 
  tft.fillScreen(YELLOW);

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

  //En lugar de utilizar un pixel de forma individual vamos a crear una matriz de valores que contengan la informacion como si de una imagen real se tratara
  //Dentro de cada elemento de la matriz vamos a guardar la informacion del color que queremos dibujar

  //Para crear una matriz es necesario conocer a priori cuantos elementos en filas y en columnas se van a contener
  // En este caso vamos a crear una matriz de 3 filas y 3 columnas y las rellenaremos con colores
  uint16_t pixelMatrix [3][4]={
    {RED, GREEN, BLUE,CYAN}, 
    {GREEN, BLUE, CYAN, RED}, 
    {BLUE, CYAN, RED, GREEN},
  };

  // sizeof Multidimensional Array Analysis
  
  Serial.print("Size of Matrix: ");
  Serial.println(sizeof(pixelMatrix));
  
  Serial.print("Size of array [0]: ");
  Serial.println(sizeof(pixelMatrix[0]));

  Serial.print("Size of each Matrix element [0][0]: ");
  Serial.println(sizeof(pixelMatrix[0][0]));
  Serial.println();

  //------------------//
  
  Serial.print("Matrix Rows: ");
  int matrixRow = sizeof(pixelMatrix)/sizeof(pixelMatrix[0]);
  Serial.println(matrixRow);
  
  Serial.print("Matrix Columns: ");
  int matrixColumn = sizeof(pixelMatrix[0])/sizeof(pixelMatrix[0][0]);
  Serial.println(matrixColumn);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < matrixRow ; ++i){
    for (int j = 0; j < matrixColumn; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect(j*w, i*h, w, h, pixelMatrix[i][j]);
    }  
  }
}

void loop() {

}

