# Mapeamento de Pinos (Pinout) - ESP32 DevKit V1 (30 Pinos)

Este documento contém o mapeamento detalhado de todos os 30 pinos da placa ESP32 DevKit V1 (Módulo ESP32-WROOM-32 / Placa HW-394), organizado conforme a disposição física na placa.

---

## 1. Disposição dos Pinos

```
                     +-------------------+
                     |  ANTENA PCB (top) |
                     +-------------------+
             EN  [1] |                   | [30] D23 (GPIO 23 / VSPI_MOSI)
   VP (GPIO 36)  [2] |                   | [29] D22 (GPIO 22 / I2C SCL)
   VN (GPIO 39)  [3] |                   | [28] TX0 (GPIO 1 / UART0 TX)
  D34 (GPIO 34)  [4] |                   | [27] RX0 (GPIO 3 / UART0 RX)
  D35 (GPIO 35)  [5] |                   | [26] D21 (GPIO 21 / I2C SDA)
  D32 (GPIO 32)  [6] |    ESP32-WROOM-32 | [25] D19 (GPIO 19 / VSPI_MISO)
  D33 (GPIO 33)  [7] |                   | [24] D18 (GPIO 18 / VSPI_SCK)
  D25 (GPIO 25)  [8] |                   | [23] D5  (GPIO 5  / VSPI_CS)
  D26 (GPIO 26)  [9] |                   | [22] D17 (GPIO 17 / UART2 TX)
  D27 (GPIO 27) [10] |                   | [21] D16 (GPIO 16 / UART2 RX)
  D14 (GPIO 14) [11] |                   | [20] D4  (GPIO 4  / ADC2_CH0)
  D12 (GPIO 12) [12] |                   | [19] D2  (GPIO 2  / LED Onboard)
  D13 (GPIO 13) [13] |                   | [18] D15 (GPIO 15 / HSPI_CS)
            GND [14] |                   | [17] GND
            VIN [15] |                   | [16] 3V3
                     +-------------------+
                     |     [MICRO-USB]   |
                     |  [EN]       [BOOT]|
                     +-------------------+
```

---

## 2. Tabela Detalhada do Barramento Esquerdo

| Pino | Silk na Placa | GPIO | ADC / Touch / DAC | Barramentos / Alt Func. | Tipo | Observações Gerais |
| :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **1** | **EN** | - | - | Enable / Reset | Input | Reset do microcontrolador (Pull-up interno). |
| **2** | **VP** | GPIO 36 | ADC1_CH0 / RTC_GPIO0 | - | Input Only | Sem resistores internos de pull-up/pull-down. |
| **3** | **VN** | GPIO 39 | ADC1_CH3 / RTC_GPIO3 | - | Input Only | Sem resistores internos de pull-up/pull-down. |
| **4** | **D34** | GPIO 34 | ADC1_CH6 | - | Input Only | Apenas entrada. Não pode ser usado como saída. |
| **5** | **D35** | GPIO 35 | ADC1_CH7 | - | Input Only | Apenas entrada. Não pode ser usado como saída. |
| **6** | **D32** | GPIO 32 | ADC1_CH4 / TOUCH9 | RTC_GPIO9 | I/O | Suporta despertar do Deep Sleep (RTC GPIO). |
| **7** | **D33** | GPIO 33 | ADC1_CH5 / TOUCH8 | RTC_GPIO8 | I/O | Suporta despertar do Deep Sleep (RTC GPIO). |
| **8** | **D25** | GPIO 25 | ADC2_CH8 / DAC_1 | RTC_GPIO6 | I/O | Conversores Digital-para-Analógico (DAC). |
| **9** | **D26** | GPIO 26 | ADC2_CH9 / DAC_2 | RTC_GPIO7 | I/O | Conversores Digital-para-Analógico (DAC). |
| **10** | **D27** | GPIO 27 | ADC2_CH1 / TOUCH7 | RTC_GPIO17 | I/O | Excelente para interrupções externas. |
| **11** | **D14** | GPIO 14 | ADC2_CH6 / TOUCH6 | HSPI_CLK | I/O | Barramento HSPI Clock. |
| **12** | **D12** | GPIO 12 | ADC2_CH5 / TOUCH5 | HSPI_MISO | I/O | *Strapping Pin*: Falha o boot se puxado para HIGH no start. |
| **13** | **D13** | GPIO 13 | ADC2_CH4 / TOUCH4 | HSPI_MOSI | I/O | Barramento HSPI MOSI. |
| **14** | **GND** | - | - | Terra ($0\text{ V}$) | Power | Referência do circuito. |
| **15** | **VIN** | - | - | Entrada $5\text{ V}$ – $9\text{ V}$ | Power | Entrada alimentada pelo regulador AMS1117-3.3. |

---

## 3. Tabela Detalhada do Barramento Direito

| Pino | Silk na Placa | GPIO | ADC / Touch | Barramentos / Alt Func. | Tipo | Observações Gerais |
| :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **16** | **3V3** | - | - | Alimentação $3.3\text{ V}$ | Power | Saída $3.3\text{ V}$ do regulador interno (Máx. $250\text{ mA}$). |
| **17** | **GND** | - | - | Terra ($0\text{ V}$) | Power | Referência do circuito. |
| **18** | **D15** | GPIO 15 | ADC2_CH3 / TOUCH3 | HSPI_CS | I/O | *Strapping Pin*: Emite sinal PWM no boot. |
| **19** | **D2** | GPIO 2 | ADC2_CH2 / TOUCH2 | Onboard LED | I/O | *Strapping Pin*: Conectado ao LED azul da placa. |
| **20** | **D4** | GPIO 4 | ADC2_CH0 / TOUCH0 | - | I/O | Possa ser usado para Touch Capacitivo. |
| **21** | **D16** | GPIO 16 | - | UART2_RX | I/O | Recepção Serial 2 (Hardware UART). |
| **22** | **D17** | GPIO 17 | - | UART2_TX | I/O | Transmissão Serial 2 (Hardware UART). |
| **23** | **D5** | GPIO 5 | - | VSPI_CS | I/O | *Strapping Pin*: Chip Select padrão da SPI. |
| **24** | **D18** | GPIO 18 | - | VSPI_CLK | I/O | Clock padrão da SPI. |
| **25** | **D19** | GPIO 19 | - | VSPI_MISO | I/O | MISO padrão da SPI. |
| **26** | **D21** | GPIO 21 | - | I2C_SDA | I/O | Dados padrão do I2C. |
| **27** | **RX0** | GPIO 3 | - | UART0_RX | I/O | Reservado para programação e Serial Monitor (USB). |
| **28** | **TX0** | GPIO 1 | - | UART0_TX | I/O | Reservado para programação e Serial Monitor (USB). |
| **29** | **D22** | GPIO 22 | - | I2C_SCL | I/O | Clock padrão do I2C. |
| **30** | **D23** | GPIO 23 | - | VSPI_MOSI | I/O | MOSI padrão da SPI. |

---

## 4. Agrupamento por Categoria de Uso

### A. Barramentos de Comunicação Padrão
* **I2C Padrão:**
  * `SCL`: GPIO 22
  * `SDA`: GPIO 21
* **SPI Padrão (VSPI):**
  * `MOSI`: GPIO 23
  * `MISO`: GPIO 19
  * `SCK`: GPIO 18
  * `CS`: GPIO 5
* **UART Serial Secundaria (Hardware UART2):**
  * `TX`: GPIO 17
  * `RX`: GPIO 16

### B. Pinos Apenas de Entrada (Input-Only)
Estes pinos **não** possuem circuito de saída e **não possuem resistores internos** de Pull-up/Pull-down:
* **GPIO 34**
* **GPIO 35**
* **GPIO 36 (VP)**
* **GPIO 39 (VN)**

### C. Pinos de Configuração no Boot (Strapping Pins)
Evite colocar resistores externos fortes conectando estes pinos ao $3.3\text{ V}$ ou $0\text{ V}$ no momento da inicialização:
* **GPIO 0** (Geralmente interno)
* **GPIO 2**
* **GPIO 5**
* **GPIO 12**
* **GPIO 15**

### D. Conversores ADC e Restrições do Wi-Fi
* **ADC1:** GPIO 32, 33, 34, 35, 36 (VP), 39 (VN). *Podem ser lidos mesmo com Wi-Fi ativo.*
* **ADC2:** GPIO 0, 2, 4, 12, 13, 14, 15, 25, 26, 27. ***Não* podem ser usados para leitura analógica enquanto o Wi-Fi estiver transmitindo.**