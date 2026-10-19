#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_ADDRESS 0x3C
#define OLED_RESET -1

#define BME_280_ADDRESS 0x76

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme;

void setup()
{
  Serial.begin(115200);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("[ERRO] Falha ao inicializar o display OLED");
    while (true) {
      delay(1000);
    }
  }

  if (!bme.begin(BME_280_ADDRESS, &Wire)) {
    Serial.println("[ERRO] BME280 nao encontrado! Verifique o endereco I2C ou as conexoes.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Perifericos inicializados com sucesso.");
}

void loop()
{

  float temp = bme.readTemperature();
  float umid = bme.readHumidity();
  float pressao = bme.readPressure() / 100.0F;
  float altitude_simples = bme.readAltitude(SEALEVELPRESSURE_HPA);

  Serial.printf("Temp: %.1f C | Umid: %.1f %% | Pressao: %.1f hPa\n", temp, umid, pressao);

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("AC WEATHER STATION");

  display.setCursor(0, 18);
  display.printf("Temp: %.1f ", temp);
  display.drawCircle(68, 20, 2, SSD1306_WHITE);
  display.println(" C");

  display.setCursor(90,18);
  display.printf("%.0fM", altitude_simples);

  display.setCursor(0, 32);
  display.printf("Umid: %.1f %%", umid);

  display.setCursor(90, 32);
  display.print("Altd.");

  display.setCursor(0, 46);
  display.printf("Pressao: %.0f hPa", pressao);

  display.display();

  delay(5000);
}
