#include <SPI.h>
#include <SD.h> 
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

#define SD_CS 10

File myFile;
#define FOLDERSIZE 100

//Raiz de la ruta de las imagenes
String FOLDERROOT = "Arduino/";

void setup() {
  Serial.begin(9600);
  
  tft.begin(); // Begin ILI9341
  tft.fillScreen(BLUE);
  tft.setRotation(0);
  
  tft.setTextSize(2);
  tft.setTextColor(CYAN);
  
  // Para abrir los datos de la tarjeta solo hay que utilizar la funcion begin que acceda al Pin de comunicacion con la SD
  if (!SD.begin(SD_CS)) {
    
    progmemPrintln(PSTR("Card failed")); // Useful for SPI TFT Screens
    tft.println("Card Failed");
    return;
  }

  tft.println("Card Ready");
  tft.setCursor(0,30);

  File dataFile = SD.open("Arduino/arduino.txt");
  
  if (dataFile) {
    tft.println("Succes: File Found ");
    while (dataFile.available()) {
      Serial.print("\t");
      //peek() lee el caracter disponible pero no desplaza el puntero
      Serial.print(dataFile.peek());
      
      //En cambio read() si que desplaza el puntero
      tft.print((char)dataFile.read());

      //Hay diferencia al leerlo como un caracter, a leerlo como un dato no declarado. Por defecto nos aparecera su valor numerico
    }
    dataFile.close();
  }else{
    tft.println("File not found");
  }
}


void loop() {

}

void progmemPrint(const char *str) {
  char c;
  while(c = pgm_read_byte(str++)) Serial.print(c);
}

void progmemPrintln(const char *str) {
  progmemPrint(str);
  Serial.println();
}

