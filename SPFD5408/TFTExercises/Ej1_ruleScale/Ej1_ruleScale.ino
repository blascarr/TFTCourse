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

int width, height;

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(WHITE);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();
  
  //Una linea requiere de 4 parametros. Posicion inicial --> Esquina superior izquierda
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Longitud --> Distancia en pixeles
  // Color --> En hexadecimal

  // Crear una escala con intervalos cada 10 pixeles en las dos direcciones
  // Para ello, vamos a crear primero una cruz por toda la pantalla
  // Y encima de ellas unas marcas con unas lineas de 10 pixeles de longitud

  // Dibujamos la linea horizontal pasante
  tft.drawFastHLine(0, height/2 , width, BLACK);
  // Dibujamos la linea vertical pasante
  tft.drawFastVLine(width/2, 0 , height, BLACK);

  int interval = 10;
  int length = 10;
  int x = width/2 - length/2;
  int y = height/2 - length/2;

  //Se dibujan las lineas horizontales indicadores de cada intervalo
  for(int i ; i < height/interval; i++ ){
    
    tft.drawFastHLine(x, i*interval , length, BLACK);
    tft.setCursor(x+20, i*interval);

    //Escribir una formula para que aparezcan los numeros situados en el origen en el eje horizontal
    tft.println();    // Solo hay que modificar esta linea
  }
  
  //Se dibujan las lineas verticales indicadoras del intervalo
  for(int i ; i < width/interval; i++ ){
    
    tft.drawFastVLine(i*interval, y , length, BLACK);
    tft.setCursor(i*interval, y +20);

    //Escribir una formula para que aparezcan los numeros situados en el origen en el eje vertical
    tft.println();   // Solo hay que modificar esta linea
  }

}

void loop() {

}
