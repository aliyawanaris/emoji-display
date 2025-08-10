#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// Definisi pin
// SPI: SCK (SCL) -> GPIO 4, MOSI (SDA) -> GPIO 7
// Pins for the 240x240 display.
#define TFT_CS    -1  // Chip Select tidak digunakan atau di-hardwire ke GND
#define TFT_DC    3   // Data/Command
#define TFT_RST   8   // Reset

// Inisialisasi library dengan pin yang Anda gunakan
Adafruit_ST7789 tft = Adafruit_ST7789(&SPI, TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(115200);

  // Inisialisasi display
  tft.init(240, 240); // Inisialisasi display 240x240
  tft.setRotation(2); // Atur orientasi layar

  tft.fillScreen(ST77XX_BLACK); // Kosongkan layar dengan warna hitam
  tft.setTextWrap(false);      // Matikan pembungkus teks
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);

  // Tampilkan teks
  tft.setCursor(10, 10);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println("Hello, ESP32!");

  // Tampilkan bentuk
  tft.drawRect(50, 50, 100, 50, ST77XX_RED);
  tft.drawCircle(120, 150, 40, ST77XX_BLUE);

  delay(2000); // Tahan selama 2 detik
}