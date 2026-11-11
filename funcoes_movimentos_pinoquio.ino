void moverFrente(int velEsq, int velDir) {
  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, velEsq);
  
  digitalWrite(M2_DIR, HIGH);
  analogWrite(M2_PWM, velDir);
}

void virarEsquerda() {
  // Motor esquerdo gira para trás (ou para) e direito vai para frente
  digitalWrite(M1_DIR, LOW); 
  analogWrite(M1_PWM, VEL_CURVA);
  
  digitalWrite(M2_DIR, HIGH);
  analogWrite(M2_PWM, VEL_CURVA);
}

void virarDireita() {
  // Motor esquerdo vai para frente e direito gira para trás (ou para)
  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, VEL_CURVA);
  
  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, VEL_CURVA);
}

void pararMotores() {
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
}
