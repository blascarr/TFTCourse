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
