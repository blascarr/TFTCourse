#include <SD.h>

// *** SPFD5408 change -- Begin
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

// *** SPFD5408 change -- End

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
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

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define SD_CS 10

File myFile;
#define FOLDERSIZE 100

//Raiz de la ruta de las imagenes
String FOLDERROOT = "Arduino/";

void setup() {
  Serial.begin(9600);
  
  tft.begin(0x9341); // SDFP5408
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

