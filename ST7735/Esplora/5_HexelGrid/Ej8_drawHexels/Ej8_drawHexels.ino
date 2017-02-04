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
int columns;

void setup() {
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2)

  tft.setRotation(1); 
  tft.fillScreen(WHITE);

  width = tft.width();
  height = tft.height();

  columns = 4;
  
  drawSubHexel(0,0,ROSE);
  drawSubHexel(1,1,YELLOW);
  drawSubHexel(1,0,ROSE);
  drawSubHexel(0,1,YELLOW);
  drawSubHexel(0,2,BLUE);
  drawSubHexel(1,2,BLUE);

  drawSubHexel(3,2,ROSE);
  drawSubHexel(4,3,YELLOW);
  drawSubHexel(3,3,ROSE);
  drawSubHexel(5,2,BLUE);
  drawSubHexel(4,2,YELLOW);
  drawSubHexel(5,3,BLUE);
  
  subhexelgrid(columns, BLACK);
}

void loop() {

}

//Esta funcion debe ser capaz de dibujar uno de los triangulos de la mall, especificando la fila y la columna dado por el convenio definido en https://github.com/blascarr/TFTCourse
void drawSubHexel(int row, int col, uint16_t color){
    float w = width/columns;
    float h = w*sqrt(4/3);

    //Absolut Displacement width and height
    int d_w=(col)/6;
    int d_h=(row)/6;
    float plus_w,plus_h;
    bool inv, inv_x, inv_y;

    int mode = 0;

    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    float x3 = 0;
    float y3 = 0;
      
      //Desplazamiento entre cuadriculas
      plus_w = (col)/6*2*w;
      plus_h = (row)/4*h;

      if ((col%6) >= 3){
        plus_w = plus_w + w;
      } 

      if (row%4 >=2){
        plus_h = plus_h + h/2;
      }

      //Identificacion del modo de la cuadricula
      if ((col%6 >= 3)^(row%4 >=2)){
          inv = true;
          //Serial.println("Mode 2");
          if ((2*(col%3)+row%2) <= 2){
            row++;
          }else{
            row--;
          }
      }else{
          inv = false;
          //Serial.println("Mode 1");
      }

      //Identificación de la mitad a la que pertenece
      if ((2*(col%3)+row%2)>=2){
          inv_x = true;

      }else{
          inv_x = false;
      }

      //Inicializacion de la referencia
      x1 = 0;
      x2 = 0;
      //Identificacion del triangulo al que pertenece
      switch ((col%3+2*(row%2))%4){

        //Case for parameters [0,0] & [2,1]
        case 0:
          x2 = w/2;
          y2 = h/4;
          x3 = 2*w/3;
          y3 = 0;

        break;

        //Case for parameters [1,0] 
        case 1:
          x2 = w/3;
          y2 = h/2;
          x3 = w/2;
          y3 = h/4;
        break;

        //Case for parameters [0,1] & [2,0] 
        case 2:
            x2 = 0;
            y2 = h/2;
            x3 = w/3;
            y3 = h/2;
        break;

        //Case for parameters [1,1] 
        case 3:
          x1 = w;
          y1 = h/2;
          x2 = 2*w/3;
          y2 = 0;
          x3 = w/2;
          y3 = h/4;

        break;
      }


      if(inv){
        y1 = h/2 - y1;
        y2 = h/2 - y2;
        y3 = h/2 - y3;
      }  

      if(inv_x){
        x1 = w-x1;
        x2 = w-x2;
        x3 = w-x3;
        y1 = h/2-y1;
        y2 = h/2-y2;
        y3 = h/2-y3;
      }

      //Debug
      /*Serial.print("Col, Row: ");
      Serial.print(col%3);
      Serial.print(" : ");
      Serial.println(row%2);
      Serial.print("Punto 1: ");
      Serial.print(x1);
      Serial.print(" , ");
      Serial.println(y1);
      Serial.print("Punto 2: ");
      Serial.print(x2);
      Serial.print(" , ");
      Serial.println(y2);
      Serial.print("Punto 3: ");
      Serial.print(x3);
      Serial.print(" , ");
      Serial.println(y3);
      Serial.println(2*(col%3)+row%2);
      Serial.println((col%3+2*(row%2))%4);*/

      tft.fillTriangle(   x1 + plus_w, y1 + plus_h, x2 + plus_w, y2 + plus_h,   x3 + plus_w, y3 + plus_h, color);
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
