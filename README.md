# Weather Station - Estação Metereológica

Projeto de estação meteorológica desenvolvido como projeto pessoal de portfólio e laboratório de estudos.

O sistema tem como objetivo coletar dados meteorológicos através de um **ESP32**, processá-los em um **backend Java/Spring Boot**, armazená-los em **PostgreSQL** e disponibilizá-los através de uma aplicação **Angular**.

## Objetivos

* Desenvolver uma estação meteorológica funcional.
* Praticar desenvolvimento backend com Java e Spring Boot.
* Aprofundar conhecimentos em Angular.
* Trabalhar com persistência de dados e séries temporais.
* Praticar testes automatizados e segurança de aplicações.
* Aplicar conceitos de Docker e infraestrutura.
* Realizar o deploy do sistema em uma infraestrutura de nuvem.

## Escopo inicial

A primeira versão do projeto contempla:

* Coleta de temperatura, umidade e pressão atmosférica através do BME280.
* Coleta de precipitação através de pluviômetro.
* Envio periódico das medições pelo ESP32.
* API para ingestão das telemetrias.
* Persistência das medições.
* Consulta do histórico das condições meteorológicas.
* Dashboard web para visualização dos dados.

Funcionalidades adicionais poderão ser incorporadas conforme a evolução do projeto.

## Arquitetura

O sistema será desenvolvido inicialmente como um monólito, organizado por módulos e executado como uma única aplicação backend.

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
       │ Telemetria
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

* Docker
* Nginx
* Oracle Cloud Infrastructure (OCI)

## Roadmap

O desenvolvimento do projeto é acompanhado através de um roadmap em formato de checklist:

[`docs/roadmap.md`](docs/roadmap.md)

## Documentação

* [Roadmap](docs/roadmap.md)
* [Decisões arquiteturais](docs/ADR/)
* [Arquitetura](docs/architecture/)

## Status

Em desenvolvimento.

---

Projeto desenvolvido por **Amauri Castro** como projeto pessoal de portfólio e laboratório de estudos.
