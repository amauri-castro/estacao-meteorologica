#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <env.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_ADDRESS 0x3C
#define OLED_RESET -1

#define BME_280_ADDRESS 0x76

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme;

void setupWiFi() {
  Serial.print("Conectando-se ao Wi-Fi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Trava o sistema aqui até conseguir conectar
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n[SUCESSO] Wi-Fi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

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

  setupWiFi();
}

void loop()
{

  float temp = bme.readTemperature();
  float umid = bme.readHumidity();
  float pressao = bme.readPressure() / 100.0F;
  float altitude_simples = bme.readAltitude(SEALEVELPRESSURE_HPA);


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

  /*
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(serverUrl);
    
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{";
    jsonPayload += "\"temperatura\":" + String(temp) + ",";
    jsonPayload += "\"umidade\":" + String(umid) + ",";
    jsonPayload += "\"pressao\":" + String(pressao);
    jsonPayload += "}";

    Serial.println("\nEnviando requisição POST...");
    Serial.println("Payload: " + jsonPayload);

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      Serial.printf("Resposta do Servidor (Código HTTP): %d\n", httpResponseCode);
    } else {
      Serial.printf("Erro na requisição HTTP: %s\n", http.errorToString(httpResponseCode).c_str());
    }

    http.end(); 
  } else {
    Serial.println("\nWi-Fi desconectado. Tentando reconectar...");
    WiFi.reconnect();
  }
  */


  delay(5000);
}
