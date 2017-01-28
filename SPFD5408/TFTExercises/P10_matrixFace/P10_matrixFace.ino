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
uint16_t BCKG = YELLOW;
int width, height;
bool gridDebug = true;

  //Numero de filas, columnas, anchura y altura de subpixel
int w, h, col, row;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(1); 
  
  tft.fillScreen(BCKG);

  width = tft.width();
  height = tft.height();

  //Ahora vamos a rellenar las filas y columnas mediante el uso de un vector en el que guardaremos en cada espacio del vector, cada una de las coordenadas a dibujar 

  //Dibujo de malla
  // 16 columnas y 20 filas
  col = 20;
  row = 16;

  // Dividimos la anchura y la altura para determinar cuanto medira cada cuadrado
  w = width/col;
  h = height/row;

  if (gridDebug){
    for(int i = 0; i < col; ++i){
        for(int j=0; j< row; j++){
  
           tft.drawRect(i*w, j*h, w, h, BLACK);
        }
    }
  }
  //En lugar de utilizar un pixel de forma individual vamos a crear una matriz de valores que contengan la informacion como si de una imagen real se tratara
  //Dentro de cada elemento de la matriz vamos a guardar la informacion del color que queremos dibujar

  //Para crear una matriz es necesario conocer a priori cuantos elementos en filas y en columnas se van a contener
  // En este caso vamos a crear una matriz de 3 filas y 3 columnas y las rellenaremos con colores
  
  // Rellena las matrices para crear diferentes caras
  uint16_t eye_i [5][5]={
    {                               }, 
    {                               },  
    {                               },  
    {                               },  
    {                               },  
  };
  
  uint16_t eye_d [5][5]={
    {                               }, 
    {                               },  
    {                               },  
    {                               },  
    {                               },  
  };
  uint16_t brow_i [5][5]={
    {                               }, 
    {                               },  
    {                               },  
    {                               },  
    {                               }, 
  };
  
  uint16_t brow_d [5][5]={
    {                               }, 
    {                               },  
    {                               },  
    {                               },  
    {                               }, 
  };

  uint16_t mouth [6][7]={
    {                                   }, 
    {                                   },  
    {                                   },  
    {                                   },  
    {                                   }, 
    {                                   }, 
  };

  //Draw Matrix on each position

  //DRAW Eye_I
  int eyei_x = 5;
  int eyei_y = 3;
  int eyei_r = sizeof(eye_i)/sizeof(eye_i[0]);
  int eyei_c = sizeof(eye_i[0])/sizeof(eye_i[0][0]);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < eyei_r ; ++i){
    for (int j = 0; j < eyei_c; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect( ( j+eyei_y  )*w, ( i+eyei_x )*h, w, h, eye_i[i][j]);
    }  
  }

  //DRAW Eye_D
  int eyed_x = 5;
  int eyed_y = 13;
  int eyed_r = sizeof(eye_d)/sizeof(eye_d[0]);
  int eyed_c = sizeof(eye_d[0])/sizeof(eye_d[0][0]);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < eyed_r ; ++i){
    for (int j = 0; j < eyed_c; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect( ( j+eyed_y  )*w, ( i+eyed_x )*h, w, h, eye_d[i][j]);
    }  
  }

  //DRAW Brow_I
  int browi_x = 0;
  int browi_y = 3;
  int browi_r = sizeof(brow_i)/sizeof(brow_i[0]);
  int browi_c = sizeof(brow_i[0])/sizeof(brow_i[0][0]);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < browi_r ; ++i){
    for (int j = 0; j < browi_c; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect( ( j+browi_y )*w, ( i+browi_x )*h, w, h, brow_i[i][j]);
    }  
  }
  
  //DRAW Brow_D
  int browd_x = 0;
  int browd_y = 13;
  int browd_r = sizeof(brow_d)/sizeof(brow_d[0]);
  int browd_c = sizeof(brow_d[0])/sizeof(brow_d[0][0]);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < browd_r ; ++i){
    for (int j = 0; j < browd_c; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect( ( j+browd_y )*w, ( i+browd_x )*h, w, h, brow_d[i][j]);
    }  
  }

  //MOUTH
  int mouth_x = 10;
  int mouth_y = 7;
  int mouth_r = sizeof(mouth)/sizeof(mouth[0]);
  int mouth_c = sizeof(mouth[0])/sizeof(mouth[0][0]);
  
  //Con un control en bucle podemos hacer que se dibujen todos los elemenentos de la matriz
  for (int i = 0; i < mouth_r ; ++i){
    for (int j = 0; j < mouth_c; ++j){
      //Orden de los contadores i y j corresponden con el desplazamiento en alto y ancho respectivamente
      tft.fillRect( ( j+mouth_y )*w, ( i+mouth_x )*h, w, h, mouth[i][j]);
    }  
  }
  
}

void loop() {

}

