# Sistema de Fechadura Inteligente com Arduino

## Descrição do Projeto
Este projeto consiste em uma fechadura eletrônica inteligente utilizando Arduino, display LCD, servo motor, buzzer, potenciômetro e botão de confirmação.

O sistema permite que o usuário selecione números utilizando um potenciômetro e confirme cada dígito através de um botão. Após inserir os 4 dígitos da senha corretamente, o servo motor realiza a abertura da trava.

O projeto também possui:
- aviso sonoro com buzzer;
- bloqueio temporário após várias tentativas erradas;
- interface visual com LCD;
- sistema de emergência/reset utilizando interrupção.

---

# Componentes Utilizados

- Arduino Uno
- Display LCD 16x2
- Servo Motor SG90
- Potenciômetro
- Push Button
- Buzzer
- Protoboard
- Jumpers
- Resistores

---

# Funcionamento

## Entrada da Senha
1. O usuário gira o potenciômetro.
2. O LCD mostra o número selecionado.
3. O usuário pressiona o botão para confirmar o dígito.
4. O processo se repete até completar 4 números.

---

## Senha Correta
Quando a senha está correta:
- o LCD exibe “Acesso Liberado”;
- o buzzer emite um som;
- o servo motor abre a trava;
- após alguns segundos o sistema fecha automaticamente.

---

## Senha Incorreta
Quando a senha está errada:
- o LCD exibe “Senha Errada”;
- o buzzer emite um alerta;
- o número de tentativas é incrementado.

Após várias tentativas incorretas:
- o sistema entra em modo bloqueado temporariamente.

---

# Sistema de Emergência
O projeto utiliza interrupção externa para um botão de emergência/reset.

Funções:
- travar imediatamente o sistema;
- reiniciar o funcionamento;
- aumentar a segurança do projeto.

---

# Estrutura do Circuito

## Potenciômetro
- Terminal esquerdo → GND
- Terminal direito → 5V
- Terminal central → entrada analógica do Arduino

## Botão de Confirmação
- Um lado → GND
- Outro lado → pino digital configurado com `INPUT_PULLUP`

## Servo Motor
- VCC → 5V
- GND → GND
- Sinal → pino PWM

## LCD
Utilizado para:
- mostrar números selecionados;
- mensagens do sistema;
- status da trava.

---

# Tecnologias Utilizadas

- Linguagem C++
- Arduino IDE
- Tinkercad

---

# Objetivos do Projeto

- Aplicar conceitos de sistemas embarcados;
- Utilizar entradas analógicas e digitais;
- Implementar controle de acesso;
- Trabalhar com automação utilizando servo motor;
- Utilizar interrupções em Arduino;
- Desenvolver integração entre hardware e software.

---

# Melhorias Futuras

- armazenamento de senha em EEPROM;
- utilização de RFID;
- conexão Bluetooth/Wi-Fi;
- aplicativo para controle remoto;
- sensor de presença;
- bateria de emergência.

---

# Autor
Dante Ryuichi Kawazu — R.A: 22.125.083-0
Leonardo Pera Chacon Guadagni — R.A: 22.125.081-4
Felipe Franco Falcon — R.A: 22.125.073-1


