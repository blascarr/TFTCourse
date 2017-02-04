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
int col, row;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(YELLOW);

  width = tft.width();
  height = tft.height();

  //Con la funcion subHexel por sectores vamos a crear toda una malla completa 
  
  col = 7;
  
  subhexelgrid(col, BLACK);
  
}

void loop() {

}

void subhexelgrid(int8_t col, uint16_t color){

    //Calculamos cuantos pixeles hay que dibujar de ancho para cada triangulo. 
    float w = width/col;

    //Conociendo el ancho de columna, establecemos la altura de cada triangulo con la siguiente formula. 
    float h = w*sqrt(4/3);
    
    //Sabiendo la altura total de la pantalla de cada triangulo, podemos calcular el numero de filas que vamos a dibujar dentro del bucle
    int n_rows = height/h;

    int posx = 0;
    int posy = 0;
    Serial.println(col);
    Serial.println(n_rows);

    for (int i = 0; i < col; i++){
      for (int j = 0; j < n_rows; j++){

        //Control para pintar cada recuadro en su posicion y no dibujar en exceso
        if(!(i%2)) subhexel(w*i, h*j, w, h/2, 1, BLACK);
        if (i%2) subhexel(w*i, h*j, w, h/2, 0, BLACK);
        if (!(i%2)) subhexel(w*i, h*(j+1/2)+h/2, w, h/2, 0, BLACK);
        if (i%2) subhexel(w*i, h*(j+1/2)+h/2, w, h/2, 1, BLACK);
        
        /*Serial.print("i: ");
        Serial.print(i);
        Serial.print(" j: ");
        Serial.print(j);
        Serial.print(" Module i: ");
        Serial.print(i%2);
        Serial.print(" Module j: ");
        Serial.println(j%2);*/
        
      }
    }
}

void subhexel(float pos_x, float pos_y, int w , int h, bool sym, uint16_t color){

    float PX[] = {0 + pos_x ,w/3 + pos_x, w/2 + pos_x, 2*w/3 + pos_x, w + pos_x};
    float PY[]= {0 + pos_y, h/2+ pos_y, h+ pos_y};
    
    if (!sym){

      PY[0] = h + pos_y;
      PY[1] = h/2 + pos_y;
      PY[2] = 0 + pos_y;
    }

    //Vamos a crear 6 subtriangulos dentro de el area determinada 
    
    tft.drawTriangle(   PX[0], PY[0], PX[1], PY[2] , PX[0], PY[2], color);
    tft.drawTriangle(   PX[0], PY[0], PX[2], PY[1] , PX[1], PY[2], color);
    tft.drawTriangle(   PX[0], PY[0], PX[3], PY[0] , PX[2], PY[1], color);
    
    tft.drawTriangle(   PX[4], PY[2], PX[3], PY[0], PX[4], PY[0] , color);
    tft.drawTriangle(   PX[4], PY[2], PX[2], PY[1], PX[3], PY[0] , color);
    tft.drawTriangle(   PX[4], PY[2], PX[1], PY[2] , PX[2], PY[1] , color);
    
    //borderCorrection();
}

void borderCorrection(){
  tft.drawFastHLine(-2, -1, width,  BLACK);
  tft.drawFastVLine(-2, -1, height,  BLACK);
  tft.drawFastVLine(-1, -1, height,  BLACK);
}
