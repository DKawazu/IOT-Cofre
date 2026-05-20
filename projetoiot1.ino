#include <LiquidCrystal.h>
#include <Servo.h>

// ===== LCD =====
// RS no pino 12, E no A1, D4 no A2, D5 no A3, D6 no A4, D7 no A5
LiquidCrystal lcd(12, A1, A2, A3, A4, A5);

// ===== SERVO =====
Servo servoMotor;

// ===== SENHA =====
String senha = "4567";
String entrada = "";

// ===== PINOS =====
int buzzer = 8;
int pinoServo = 9;
int botaoEmergencia = 10;
int botaoConfirmar = 11;
int potenciometro = A0;

// ===== CONTROLE =====
int tentativas = 0;
bool bloqueado = false;

int ultimoNumero = -1;
bool botaoPressionado = false;

void setup() {
  lcd.begin(16, 2);

  pinMode(buzzer, OUTPUT);
  pinMode(botaoEmergencia, INPUT_PULLUP);
  pinMode(botaoConfirmar, INPUT_PULLUP);

  servoMotor.attach(pinoServo);
  servoMotor.write(180);

  mostrarTelaInicial();
}

void loop() {

  // ===== EMERGÊNCIA =====
  if (digitalRead(botaoEmergencia) == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("EMERGENCIA");

    lcd.setCursor(0, 1);
    lcd.print("SISTEMA TRAVADO");

    servoMotor.write(180);
    tone(buzzer, 400);

    while (true) {
    }
  }

  if (bloqueado) {
    return;
  }

  int valorPot = analogRead(potenciometro);
  int numeroSelecionado = map(valorPot, 0, 1023, 0, 9);

  if (numeroSelecionado != ultimoNumero) {
    ultimoNumero = numeroSelecionado;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Numero: ");
    lcd.print(numeroSelecionado);

    lcd.setCursor(0, 1);
    lcd.print("Senha: ");
    lcd.print(entrada);
  }

  // ===== CONFIRMAR NUMERO =====
  if (digitalRead(botaoConfirmar) == LOW && !botaoPressionado) {
    botaoPressionado = true;

    somTecla();

    entrada += String(numeroSelecionado);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Numero salvo");

    lcd.setCursor(0, 1);
    lcd.print("Senha: ");
    lcd.print(entrada);

    delay(500);

    if (entrada.length() == 4) {
      delay(300);

      if (entrada == senha) {
        abrirPorta();
        tentativas = 0;
      } else {
        erroSenha();
        tentativas++;
      }

      entrada = "";

      if (tentativas >= 3) {
        ativarBloqueio();
      }
    }
  }

  if (digitalRead(botaoConfirmar) == HIGH) {
    botaoPressionado = false;
  }
}

// ===== TELA =====
void mostrarTelaInicial() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("GIRE O BOTAO");

  lcd.setCursor(0, 1);
  lcd.print("E CONFIRME");
}

// ===== SOM =====
void somTecla() {
  tone(buzzer, 1000);
  delay(70);
  noTone(buzzer);
}

// ===== ABRIR =====
void abrirPorta() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("ACESSO LIBERADO");

  lcd.setCursor(3, 1);
  lcd.print("ABRINDO");

  tone(buzzer, 1500);
  delay(200);
  noTone(buzzer);

  servoMotor.write(0);

  delay(5000);

  lcd.clear();

  lcd.setCursor(3, 0);
  lcd.print("FECHANDO");

  servoMotor.write(180);

  delay(1000);

  mostrarTelaInicial();
}

// ===== ERRO =====
void erroSenha() {
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("SENHA ERRADA");

  lcd.setCursor(0, 1);
  lcd.print("TENTE NOVAMENTE");

  tone(buzzer, 300);
  delay(1000);
  noTone(buzzer);

  delay(1000);

  mostrarTelaInicial();
}

// ===== BLOQUEIO =====
void ativarBloqueio() {
  bloqueado = true;

  for (int tempo = 10; tempo > 0; tempo--) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("SISTEMA BLOQ.");

    lcd.setCursor(0, 1);
    lcd.print("AGUARDE ");
    lcd.print(tempo);

    tone(buzzer, 500);
    delay(200);

    noTone(buzzer);
    delay(800);
  }

  tentativas = 0;
  bloqueado = false;

  mostrarTelaInicial();
}