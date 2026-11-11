/* Codigo Segue Linha Robô Pinoquio 
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
Segue Linha Digital com 3 sensores TCRT5000.
Esperado: O robô deve identificar a linha preta sobre o fundo branco e corrigir 
sua trajetória automaticamente usando os motores A e B.
Status: Em testes.
-------------------------------------------------------------------------------
Historico de versionamento
_____________________________________________________________________________
Versão: 1.0.0 Data: 04/11/2026
Descrição: Teste de motores A e B.

Versão: 1.1.0 Data: 11/11/2026
Descrição: Implementação da leitura Digital com 3 sensores TCRT5000 e lógica segue-linha.
*/

// Definindo os pinos do L298P Shield V1.2
const int M1_DIR = 4; // Direção Motor 1 (Esquerdo)
const int M1_PWM = 5; // Velocidade Motor 1 (Esquerdo)
const int M2_PWM = 6; // Velocidade Motor 2 (Direito)
const int M2_DIR = 7; // Direção Motor 2 (Direito)

// Definindo os pinos dos 3 sensores TCRT5000 (Saída Digital D0)
const int S_ESQ = 8;  // Sensor da Esquerda
const int S_MEIO = 9; // Sensor do Meio
const int S_DIR = 10; // Sensor da Direita

// Configurações de Velocidade (0 a 255) - Ajuste conforme o peso do robô
const int VEL_NORMAL = 150; // Velocidade em linha reta
const int VEL_CURVA = 180;  // Velocidade para girar nas curvas
const int VEL_LENTA = 60;   // Velocidade da roda interna na curva suave

// Lógica do sensor TCRT5000 (Geralmente: 1 = Preto, 0 = Branco)
// Se o seu sensor funcionar ao contrário, basta inverter os valores abaixo
const int PRETO = LOW;
const int BRANCO = HIGH;

void setup() {
  // Configuração dos motores
  pinMode(M1_DIR, OUTPUT);
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M2_PWM, OUTPUT);

  // Configuração dos sensores
  pinMode(S_ESQ, INPUT);
  pinMode(S_MEIO, INPUT);
  pinMode(S_DIR, INPUT);
}

void loop() {
  // Faz a leitura dos 3 sensores
  int esq = digitalRead(S_ESQ);
  int meio = digitalRead(S_MEIO);
  int dir = digitalRead(S_DIR);

  // CENÁRIO 1: Apenas o sensor do meio vê a linha (Seguir em frente)
  if (esq == BRANCO && meio == PRETO && dir == BRANCO) {
    moverFrente(VEL_NORMAL, VEL_NORMAL);
  }
  
  // CENÁRIO 2: Sensor da esquerda vê a linha (Curva para a esquerda)
  else if (esq == PRETO && dir == BRANCO) {
    virarEsquerda();
  }
  
  // CENÁRIO 3: Sensor da direita vê a linha (Curva para a direita)
  else if (esq == BRANCO && dir == PRETO) {
    virarDireita();
  }
  
  // CENÁRIO 4: Cruzamento ou encruzilhada (Todos no preto)
  else if (esq == PRETO && meio == PRETO && dir == PRETO) {
    // Na OBR, geralmente passa reto em cruzamentos simples
    moverFrente(VEL_NORMAL, VEL_NORMAL);
  }
  
  // CENÁRIO 5: Perdeu a linha (Todos no branco)
  else {
    // Continua devagar para frente tentando reencontrar a linha
    moverFrente(VEL_LENTA, VEL_LENTA);
  }
}
