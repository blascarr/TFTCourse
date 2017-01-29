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

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(YELLOW);

  width = tft.width();
  height = tft.height();

  //La malla será en este momento triangular con unas dimensiones definidas 
  // y una disposición que nos permita acceder a cada uno de estos triangulos mediante la definicion de la fila y la columna que queremos dibujar.

  //Dibujo de malla
  // 12 columnas y 20 filas
  col = 12;
  row = 20;

  // Dividimos la anchura y la altura para determinar cuanto medira cada cuadrado
  w = width/col;
  h = height/row;
  
  hexelgrid(col, row, BLACK);
}

void loop() {

}

void hexelgrid(int8_t col, int8_t row, uint16_t color){
    float w = width/col;
    float h = w*sqrt(4/3);
    int n_rows = height/h;

    tft.drawTriangle(   0,0 , 2*w/3,0,   w/2, h/4, color);
    tft.drawTriangle(   0,0 , w/2, h/4,  w/3,h/2, color);
    tft.drawTriangle(   0,0 , w/3,h/2,   0, h/2, color);

    tft.drawTriangle(   2*w/3,0 , w,0,   w, h/2, color);
    tft.drawTriangle(   w/2, h/4 , w,h/2,   w/3, h/2, color);
    tft.drawTriangle(   w/2, h/4 , w, h/2,   w/3,h/2, color);
    
    
    for (int i = 0; i <= col+1; ++i)
    {
        //hexel::drawTriangle(   w*(i-1), 0, w*i, 0 , w*(i-1), h/2, color);
      for (int j = 0; j <= n_rows+1; ++j)
      {
        //hexel::drawTriangle(   0, h/2+h*(j-1), w, h*j , 0, h/2+h*j, color);
        //hexel::drawTriangle(   w, h+h*(j-1), 2*w, h*j+h/2 , w, h+h*j, color);
        //hexel::drawTriangle(   2*w, h/2+h*(j-1), 3*w, h*j , 2*w, h/2+h*j, color);
        //------
        //hexel::drawTriangle(   w*(i-1), h/2+h*(j-1), w*i, h*j , w*(i-1), h/2+h*j, color);

        tft.drawTriangle(   w*(i-1), h/2*(i%2+1)+h*(j-1), w*i, h/2*(i%2)+h*j , w*(i-1), h/2*(i%2+1)+h*j, color);
        tft.drawTriangle(   w*(i-1), h/2*(i%2+1)+h*(j-1), w*i, h/2*(i%2)+h*j , w*(i-1), h/2*(i%2+1)+h*j, color);
        //Border Correction
        tft.drawFastHLine(-2, -1, width,  color);
        tft.drawFastVLine(-2, -1, height,  color);
        tft.drawFastVLine(-1, -1, height,  color);

      }
    }
  }

