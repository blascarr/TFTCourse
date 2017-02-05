#include <SD.h>

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

#define SD_CS 8

File myFile;
#define FOLDERSIZE 100

//Raiz de la ruta de las imagenes
String FOLDERROOT = "Arduino/";

void setup() {
  Serial.begin(9600);
  
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2);

  tft.fillScreen(BLUE);
  tft.setRotation(0);
  
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  
  // Para abrir los datos de la tarjeta solo hay que utilizar la funcion begin que acceda al Pin de comunicacion con la SD
  if (!SD.begin(SD_CS)) {
    
    progmemPrintln(PSTR("Card failed")); // Useful for SPI TFT Screens
    tft.println("Card Failed");
    return;
  }

  tft.println("Card Ready");
  tft.setCursor(0,30);

  File dataFile = SD.open("Arduino/grid.csv");
  
  if (dataFile) {
    tft.println("Succes: File Found ");
    int countCR;
    int countLF;
    while (dataFile.available()) {
      Serial.print("\t");
      //peek() lee el caracter disponible pero no desplaza el puntero
      //En cambio read() si que desplaza el puntero
      Serial.print(dataFile.peek());  //Los valores de CR y LF no aparecen escritos en el monitor serie, pero existen en el fichero.

      //Hay diferencia al leerlo como un caracter, a leerlo como un dato no declarado. Por defecto nos aparecera su valor numerico.
      int data = dataFile.read();

      //Cada linea en el fichero termina con un retorno de carro CR y un fin de linea LF.
      //El numero 13 corresponde con el retorno de carro, tambien se representa con "\r".
      if (data== 13){
        tft.print("CR: ");tft.println(countCR);
        countCR++;
      }
      
      //El numero 10 corresponde con el fin de linea, tambien se representa con "\n"
      //A partir de este momento, el proximo valor leido es el dato de comienzo de la siguiente linea 
      if (data== 10){
        tft.print("LF: ");tft.println(countLF);
        countLF++;
      }
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

