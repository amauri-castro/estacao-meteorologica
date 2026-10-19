# Documentação Técnica: ESP32 DevKit V1 (30 Pinos)
**Projeto:** Estação Meteorológica Inteligente  
**Módulo:** ESP32-WROOM-32 (Modelo Board: HW-394)  
**Chip USB-Serial:** CH340C  

---

## 1. Visão Geral e Especificações Técnicas

A placa de desenvolvimento **ESP32 DevKit V1 (30 pinos)** baseada no módulo **ESP32-WROOM-32** é uma solução robusta e de baixo consumo de energia para projetos de Internet das Coisas (IoT), como estações meteorológicas.

### Especificações Principais:
- **Microcontrolador:** Tensilica LX6 Dual-Core 32-bit (frequência até 240 MHz).
- **Memória Flash:** 4 MB (32 Mbits).
- **SRAM:** 520 KB.
- **Conectividade:**
  - Wi-Fi 802.11 b/g/n (até 150 Mbps).
  - Bluetooth v4.2 BR/EDR e BLE (Bluetooth Low Energy).
- **Tensão de Operação dos GPIOs:** $3.3\text{ V}$ (Atenção: Os pinos **NÃO** são tolerantes a $5\text{ V}$).
- **Alimentação da Placa:**
  - Entrada USB (Micro-USB / USB-C a depender do conector montado): $5\text{ V DC}$.
  - Pino `VIN`: $5\text{ V}$ a $9\text{ V DC}$ (Regulador interno AMS1117-3.3v).
  - Pino `3V3`: Entrada regulada de $3.3\text{ V}$ ou saída para alimentação de sensores.
- **Periféricos Integrados:**
  - Regulador LDO AMS1117 3.3V.
  - Conversor USB-UART CH340C.
  - LEDs indicadores: `PWR` (Power/Alimentação) e `D2` (LED do usuário conectado à GPIO 2).
  - Botões: `EN` (Reset) e `BOOT` (Modo de gravação).

---

## 2. Mapeamento de Pinos (Pinout)

A placa possui 30 pinos dispostos em dois barramentos (Esquerdo e Direito, considerando a foto na orientação vertical com a antena Wi-Fi no topo).

### Lado Esquerdo (Top-to-Bottom)
| Serigrafia na Placa | Função Principal / GPIO | Funções Secundárias / Observações | Uso Recomendado na Estação |
| :--- | :--- | :--- | :--- |
| **EN** | Enable / Reset | Reset da placa (Pull-up interno) | Botão físico / Não conectar sensores |
| **VP** | GPIO 36 | ADC1_CH0, RTC_GPIO0 (Apenas Entrada) | Sensor Analógico (ex: Sensor de UV / Chuva) |
| **VN** | GPIO 39 | ADC1_CH3, RTC_GPIO3 (Apenas Entrada) | Sensor Analógico (ex: Anemômetro analógico) |
| **D34** | GPIO 34 | ADC1_CH6 (Apenas Entrada, Sem Pull-up/Down) | Sensor Analógico / Digital (Apenas Entrada) |
| **D35** | GPIO 35 | ADC1_CH7 (Apenas Entrada, Sem Pull-up/Down) | Sensor Analógico / Digital (Apenas Entrada) |
| **D32** | GPIO 32 | ADC1_CH4, TOUCH9, RTC_GPIO9 | Sensor de Umidade de Solo / Sensor de Chuva |
| **D33** | GPIO 33 | ADC1_CH5, TOUCH8, RTC_GPIO8 | Barômetro / Sensor de Pressão Analógico |
| **D25** | GPIO 25 | DAC_1, ADC2_CH8, RTC_GPIO6 | Saída Analógica / Sensor Geral |
| **D26** | GPIO 26 | DAC_2, ADC2_CH9, RTC_GPIO7 | Sensor Geral / Comunicação |
| **D27** | GPIO 27 | ADC2_CH1, TOUCH7, RTC_GPIO17 | Sensor Digital (ex: Anemômetro por pulsos) |
| **D14** | GPIO 14 | HSPI_CLK, ADC2_CH6, TOUCH6 | Sensor Pluviômetro (Contador de Pulsos/Interrupção) |
| **D12** | GPIO 12 | HSPI_MISO, ADC2_CH5, TOUCH5 (*Strapping pin*) | Sensor Digital Geral (Evitar resistor Pull-up alto no boot) |
| **D13** | GPIO 13 | HSPI_MOSI, ADC2_CH4, TOUCH4 | Sensor de Temperatura/Umidade (DHT22 / DS18B20) |
| **GND** | Ground | Terra do Circuito ($0\text{ V}$) | Referência para Sensores e Módulos |
| **VIN** | Power Input | Entrada $5\text{ V}$ – $9\text{ V DC}$ | Entrada de alimentação via fonte externa ou painel solar com regulador |

---

### Lado Direito (Top-to-Bottom)
| Serigrafia na Placa | Função Principal / GPIO | Funções Secundárias / Observações | Uso Recomendado na Estação |
| :--- | :--- | :--- | :--- |
| **D23** | GPIO 23 | VSPI_MOSI | Sensor SPI (ex: Leitor SD Card para datalogger) |
| **D22** | GPIO 22 | I2C SCL (Padrão) | Barramento I2C - Clock (`SCL` do BME280 / BMP280 / Display OLED) |
| **TX0** | GPIO 1 | UART0_TX (*Pino de Gravação*) | Comunicação Serial com PC (Evitar uso) |
| **RX0** | GPIO 3 | UART0_RX (*Pino de Gravação*) | Comunicação Serial com PC (Evitar uso) |
| **D21** | GPIO 21 | I2C SDA (Padrão) | Barramento I2C - Dados (`SDA` do BME280 / BMP280 / Display OLED) |
| **D19** | GPIO 19 | VSPI_MISO | Sensor SPI (MISO - Cartão SD) |
| **D18** | GPIO 18 | VSPI_CLK | Sensor SPI (CLK - Cartão SD) |
| **D5** | GPIO 5 | VSPI_CS (*Strapping pin*) | Chip Select para SPI (Cartão SD) |
| **D17** | GPIO 17 | UART2_TX | Comunicação Serial Secundária (ex: Módulo LoRa / GPS) |
| **D16** | GPIO 16 | UART2_RX | Comunicação Serial Secundária (ex: Módulo LoRa / GPS) |
| **D4** | GPIO 4 | ADC2_CH0, TOUCH0 | Sensor de Luz LDR / Sensor de Iluminação BH1750 |
| **D2** | GPIO 2 | Conectado ao LED onboard (*Strapping pin*) | LED de Status da Estação (Pisca na transmissão Wi-Fi) |
| **D15** | GPIO 15 | HSPI_CS, ADC2_CH3 (*Strapping pin*) | Uso Geral |
| **GND** | Ground | Terra do Circuito ($0\text{ V}$) | Referência para Sensores |
| **3V3** | Power Output | Saída Regulada de $3.3\text{ V}$ (Máx. $\sim250\text{ mA}$) | Alimentação de Sensores $3.3\text{ V}$ (BME280, OLED, etc.) |

---

## 3. Considerações Críticas para o Projeto da Estação Meteorológica

### A. Regulagem e Consumo de Energia
1. **Modo Deep Sleep:** Para operação com painel solar e bateria (ex: 18650), coloque o ESP32 em modo *Deep Sleep*.
2. **Pinos RTC:** Apenas os pinos com suporte a **RTC** (ex: GPIO 32, 33, 27, 14, etc.) conseguem acordar o ESP32 por interrupção externa de sensores (como a bascula do pluviômetro) durante o *Deep Sleep*.
3. **Sensores de Apenas Entrada (Input-Only):**
   - Os pinos **GPIO 36 (VP), 39 (VN), 34 e 35** **não** possuem resistores internos de *pull-up* ou *pull-down* e **não podem ser configurados como saídas**. Use-os exclusivamente para leitura de sensores analógicos ou digitais com resistores externos.

### B. Barramentos e Conexões Típicas
- **Barramento I2C (I2C Standard):**
  - **SCL:** GPIO 22
  - **SDA:** GPIO 21
  - *Dispositivos sugeridos:* Sensor BME280 (Pressão, Temperatura, Umidade), Display OLED SSD1306, Sensor de Luz BH1750.
- **Barramento SPI (SD Card Datalogger):**
  - **MOSI:** GPIO 23
  - **MISO:** GPIO 19
  - **CLK:** GPIO 18
  - **CS:** GPIO 5
- **Sensores de Pulso (Anemômetro e Pluviômetro):**
  - **Pluviômetro (Chuva):** GPIO 14 ou GPIO 27 (Com interrupção externa habilitada).
  - **Anemômetro (Vento):** GPIO 32 ou GPIO 12.

### C. Cuidados com Pinos de Boot (Strapping Pins)
- **GPIO 0, GPIO 2, GPIO 5, GPIO 12 e GPIO 15** são pinos de configuração no momento da inicialização (*boot*). Evite colocar resistores de *pull-up* ou *pull-down* externos forte nesses pinos para não impedir a inicialização correta do microcontrolador.