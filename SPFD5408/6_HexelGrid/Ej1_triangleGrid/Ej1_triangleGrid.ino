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

  //La malla será en este momento triangular con unas dimensiones definidas 
  // y una disposición que nos permita acceder a cada uno de estos triangulos mediante la definicion de la fila y la columna que queremos dibujar.

  //Para ello, vamos a crear esta malla en función de las columnas que tenemos, ya que existe una relacion de dimension definida con las aristas de cada triangulo
  
  //Numero de columnas *Solo necesitamos conocer las columnas, ya que las filas las calcularemos mediante una formula trigonometricae base a este numero.
  col = 13;
  
  trianglegrid(col, row, BLACK);
}

void loop() {

}

void trianglegrid(int8_t col, int8_t row, uint16_t color){

    //Calculamos cuantos pixeles hay que dibujar de ancho para cada triangulo. 
    float w = width/col;
    
    //Conociendo el ancho de columna, establecemos la altura de cada triangulo con la siguiente formula. 
    float h = w*sqrt(4/3);
    
    //Sabiendo la altura total de la pantalla de cada triangulo, podemos calcular el numero de filas que vamos a dibujar dentro del bucle
    int n_rows = height/h;

    //Comenzamos dibujando las columnas
    for (int i = 0; i <= col; ++i){

      //Esta funcion sirve para crear un limite superior con la mitad de un triangulo. Esto sirve para establecer la referencia del primer triangulo.
      //tft.drawTriangle(   w*(i-1), 0, w*i, 0 , w*(i-1), h/2, color);
      
      for (int j = 0; j <= n_rows; ++j){
        //Para seguir un orden vamos a crear triangulos sucesivos para comprobar como evolucionan los parametros i, j con las variables w y h
        //Comenzamos a dibujar el primer triangulo desde el punto inicial (0,0)
        //tft.drawTriangle(   0, h*(j-1), w, h*j-h/2 , 0, h*j, color);
        //tft.drawTriangle(   w, h*(j-1), 2*w, h*j-h/2 , w, h*j, color);
        //tft.drawTriangle(   2*w, h*(j-1), 3*w, h*j-h/2 , 2*w, h*j, color);
        //------

        // P1_X, P1_Y , P2_X, P2_Y, P3_X, P3_Y
        tft.drawTriangle(   w*(i-1), h*(j-1), w*i, h*j-h/2 , w*(i-1), h*j, color);

        
        if(j== 0){
          Serial.print("Distancia de la malla triangular en X: ");
          Serial.println(w*(i-1));
          Serial.println("--------");
        }

      }
    }
    //Border Correction
    /*
    tft.drawFastHLine(-2, -1, width,  color);
    tft.drawFastVLine(-2, -1, height,  color);
    tft.drawFastVLine(-1, -1, height,  color);
    */
  }

