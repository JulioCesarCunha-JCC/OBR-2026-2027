/* Codigo Teste de Motores Robô Pinoquio 
 -------------------------------------------------------------------------------
  Autor: Julio César Acacio Cunha
  Matutenção: ---
  Email para contato: julio.cunha@edu.senai.br
 -------------------------------------------------------------------------------
  Temporada 2026-2027
  Equipe Mentes Do Futuro
  Olimpiada Brasileira De Robotica
  Modalidade Pratica Nivel 2
 -------------------------------------------------------------------------------
  Teste de Motores do Robô Pinoquio.
  Esprerado: Motores A e B aguentace o pesso do robõ, obedece os comandos,
  andar para frente e para tras e realizar curvas simples.
  Status: Concluido com exatidão.
  Resultado: Exito.
 ------------------------------------------------------------------------------- 
  Dicionario de Versonamento
  V. = Versão
  0. = Primeira versão
  0.0.X = Implementação no versionamento
  -----------------------------------------------------------------------------
  Historico de versonamento
  _____________________________________________________________________________
  Versão: 1.0.0
  Data: 04/11/2026
  Descrição:
  Teste de motores A e B.

 */


// Definindo os pinos do L298P Shield V1.2
 const int M1_DIR = 4; // Direção Motor 1
 const int M1_PWM = 5; // Velocidade Motor 1
 const int M2_PWM = 6; // Velocidade Motor 2
 const int M2_DIR = 7; // Direção Motor 2

void setup() {
  pinMode(M1_DIR, OUTPUT);
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
 }

void loop() {
  // Motor 1 para frente na velocidade máxima
  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, 255); // 0 a 255
  // Motor 2 
  digitalWrite(M2_DIR, HIGH);
  analogWrite(M2_PWM, 255);
  delay(2000);
  // Para o Motor 1
  analogWrite(M1_PWM, 0);
  delay(1000);
  analogWrite(M2_PWM, 0);
  delay(1000);
  // Motor 2 para trás na metade da velocidade
  digitalWrite(M2_DIR, LOW); // Ou HIGH, dependendo da montagem
  analogWrite(M2_PWM, 128);
  delay(2000);
  digitalWrite(M1_DIR, LOW); // Ou HIGH, dependendo da montagem
  analogWrite(M1_PWM, 128);
  delay(2000);
  // Para o Motor 2
  analogWrite(M2_PWM, 0);
  delay(1000);
 }
