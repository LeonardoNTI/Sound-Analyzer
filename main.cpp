#include "fix_fft.h" // Inkluderar en biblioteksfil för att utföra Fast fourier-transform (FFT)
#include <SPI.h> // Inkluderar SPI-biblioteket för att kommunicera med andra enheter via SPI-protokollet
#include <Wire.h>
#include <Adafruit_GFX.h> // Inkluderar Adafruit Graphics Library för att hantera grafik på OLED-skärmen
#include <Adafruit_SSD1306.h> 
#include <math.h> 

#define OLED_RESET 4 // Definierar reset-pin för OLED-skärmen
Adafruit_SSD1306 display(OLED_RESET); // Skapar ett objekt av typen Adafruit_SSD1306 för OLED-skärmen

char im[256], data[256]; // Skapar arrayer för indata och imaginärdelar av FFT-transformen
char x = 0, ylim = 32; // Definierar variabler för visningsparametrar
int i = 0, val; // Skapar variabler för loopindex och värden

// Definierar känslighetsfaktorernas intervall
float minSensitivityFactor = 0.1;
float maxSensitivityFactor = 2.0;

// Definierar parametrar för potentiometern
const int potPin = A1;

// Definierar notnamnen
const char *noteNames[] = {
  "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};

// Funktion för att konvertera frekvens till närmaste not
String frequencyToNote(float frequency) {
  if (frequency == 0) return "";
  
  // Konstanter för notberäkningar
  float A4 = 440.0;
  int numNotes = 12;
  float log2_ = log(2);
  
  // Beräknar antalet halvtoner från A4
  int n = round(numNotes * log(frequency / A4) / log2_);
  
  // Hittar oktaven och notindexet
  int noteIndex = (n + 69) % numNotes;
  int octave = (n + 69) / numNotes - 1;
  
  // Returnerar notnamn och oktav
  return String(noteNames[noteIndex]) + String(octave);
}

void setup() {
  delay(2000); // Väntar i 2 sekunder
  Serial.begin(9600); // Startar seriell kommunikation
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Startar OLED-skärmen med angivna parametrar
  display.setTextSize(1); // Anger textstorlek
  display.setTextColor(WHITE); // Anger textfärg
  display.clearDisplay(); // Rensar skärmen
  analogReference(DEFAULT); // Ställer in referens för analog mätning
}

void loop() {
  int min = 1024, max = 0; // Initialiserar variabler för att spåra min- och maxvärden
  int maxFrequencyIndex = 0; // Variabel för att spara index för dominerande frekvens
  int maxDB = 0; // Variabel för att spara max-amplituden i FFT-transformen
  
  // Läser av potentiometern
  int potValue = analogRead(potPin);
  
  // Kartlägger potentiometeravläsningen till känslighetsfaktorns intervall
  float sensitivityFactor = map(potValue, 0, 1023, minSensitivityFactor * 10, maxSensitivityFactor * 10) / 10.0;

  for (i = 0; i < 256; i++) { // Loopar igenom 256 värden för att sampla ljudsignalen
    val = analogRead(A0); // Läser av analogt värde från ljudsignalen
    // Justerar känsligheten för ljudsignalen
    data[i] = (val / 4 - 128) * sensitivityFactor;
    im[i] = 0; // Nollställer imaginärdelen
    if (val > max) max = val; // Uppdaterar max-värdet vid behov
    if (val < min) min = val; // Uppdaterar min-värdet vid behov
  }

  fix_fft(data, im, 8, 0); // Utför snabb fourier-transform med 8 bitars upplösning

  display.clearDisplay(); // Rensar skärmen inför ny uppdatering
  for (i = 1; i < 128; i++) { // Loopar igenom FFT-resultatet för att rita diagram på skärmen
    int dat = sqrt(data[i] * data[i] + im[i] * im[i]); // Beräknar amplituden för varje frekvens
    display.drawLine(i * 2 + x, ylim, i * 2 + x, ylim - dat, WHITE); // Ritar en linje för varje frekvens
    if (dat > maxDB) { // Uppdaterar max-amplituden och frekvensindexet vid behov
      maxDB = dat;
      maxFrequencyIndex = i;
    }
  }
  
  // Beräknar frekvensen från indexet
  float frequency = maxFrequencyIndex * (1000.0 / 128.0);
  
  // Konverterar frekvensen till närmaste not
  String note = frequencyToNote(frequency);
  
  // Visar noten på OLED-skärmen
  display.setCursor(0, 0);
  display.print("Tone: ");
  display.print(note);
  
  // Skriver ut känslighetsfaktorn bredvid noten
  display.setCursor(70, 0);
  display.print("Sens: ");
  display.print(sensitivityFactor, 1); // Skriver ut med en decimal
  
  display.display(); 

  delay(250); // Lägger till en liten fördröjning för bättre display så att inte för många toner poppar upp
