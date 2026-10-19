# Weather Station - Estação Metereológica

Projeto de estação meteorológica desenvolvido como projeto pessoal de portfólio e laboratório de estudos.

O sistema tem como objetivo coletar dados meteorológicos através de um **ESP32**, processá-los em um **backend Java/Spring Boot**, armazená-los em **PostgreSQL** e disponibilizá-los através de uma aplicação **Angular**. O foco principal desta versão é a entrega de um Produto Mínimo Viável (MVP) simples e funcional de ponta a ponta.

## Objetivos

* Desenvolver uma estação meteorológica funcional.
* Implementar uma arquitetura backend monolítica limpa e objetiva (padrão `Controller -> Service -> Repository`).
* Trabalhar com persistência de dados no PostgreSQL e consultas simples para o histórico.
* Aprofundar conhecimentos em Angular integrando com a API.
* Aplicar conceitos de Docker com `docker-compose` para subir o ambiente local de forma prática.

*(Nota: Tópicos complexos como deploy em nuvem e segurança avançada foram movidos para um roadmap futuro, garantindo o foco na finalização do escopo principal).*

## Escopo inicial

A primeira versão do projeto contempla:

* Coleta de temperatura, umidade e pressão atmosférica através do BME280.
* Coleta de precipitação através de pluviômetro.
* Envio periódico das medições pelo ESP32 (via requisições HTTP REST).
* API para ingestão e listagem das telemetrias.
* Persistência das medições no banco de dados.
* Consulta do histórico das condições meteorológicas (ex: últimas 24h).
* Dashboard web simples (tela única) para visualização dos dados.

Funcionalidades adicionais poderão ser incorporadas conforme a evolução do projeto.

## Arquitetura

O sistema será desenvolvido como um monólito com separação simples em camadas de aplicação, executado como uma única aplicação backend para facilitar o desenvolvimento e manutenção.

Visão simplificada:

```text
┌──────────────┐
│    Sensores  │
│ BME280 +     │
│ Pluviômetro  │
└──────┬───────┘
       │
       ▼
┌──────────────┐
│    ESP32     │
└──────┬───────┘
       │
       │ HTTP POST (JSON)
       ▼
┌──────────────┐
│ Spring Boot  │
│     API      │
└──────┬───────┘
       │
       ▼
┌──────────────┐
│  PostgreSQL  │
└──────────────┘
       ▲
       │
┌──────┴───────┐
│   Angular    │
│   Dashboard  │
└──────────────┘
```

A arquitetura e suas decisões são documentadas em [`docs/`](docs/).

## Tecnologias

### Hardware

* ESP32
* BME280
* Pluviômetro

### Backend

* Java
* Spring Boot
* PostgreSQL
* Flyway

### Frontend

* Angular
* PrimeNG

### Infraestrutura

* Docker (com Docker Compose)


## Documentação

* [DOCS](docs/)

## Status

Em desenvolvimento.

---

Projeto desenvolvido por **Amauri Castro** como projeto pessoal de portfólio e laboratório de estudos.