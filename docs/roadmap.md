# Roadmap

## Fase 0 — Planejamento
- [x] Definir escopo inicial
- [x] Definir arquitetura inicial
- [ ] Definir contrato de telemetria

## Fase 1 — Estação meteorológica
- [ ] Configurar ESP32
- [ ] Integrar BME280
- [ ] Integrar pluviômetro
- [ ] Implementar leitura dos sensores
- [ ] Implementar conexão Wi-Fi
- [ ] Definir formato da telemetria
- [ ] Enviar telemetria

## Fase 2 — Backend
- [ ] Criar aplicação Spring Boot
- [ ] Implementar API de ingestão
- [ ] Validar telemetria
- [ ] Persistir medições
- [ ] Implementar tratamento de erros
- [ ] Implementar testes

## Fase 3 — Persistência
- [ ] Configurar PostgreSQL
- [ ] Configurar Flyway
- [ ] Criar modelo de dados
- [ ] Implementar consultas de histórico
- [ ] Implementar agregações

## Fase 4 — Autenticação e autorização
- [ ] Implementar autenticação
- [ ] Implementar autorização
- [ ] Proteger endpoints administrativos
- [ ] Criar testes de segurança

## Fase 5 — Frontend
- [ ] Criar aplicação Angular
- [ ] Configurar PrimeNG
- [ ] Implementar autenticação
- [ ] Implementar dashboard
- [ ] Implementar histórico
- [ ] Implementar gráficos

## Fase 6 — Infraestrutura
- [ ] Containerizar aplicações
- [ ] Configurar ambiente na OCI
- [ ] Configurar PostgreSQL
- [ ] Configurar Nginx
- [ ] Configurar HTTPS
- [ ] Configurar domínio
- [ ] Documentar deployment

## Fase 7 — Evolução
- [ ] Implementar alertas
- [ ] Avaliar MQTT
- [ ] Adicionar observabilidade
- [ ] Configurar CI/CD
- [ ] Avaliar melhorias arquiteturais