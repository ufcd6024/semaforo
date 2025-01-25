// Definir pinos dos LEDs
const int red1 = 2;
const int yellow1 = 3;
const int green1 = 4;
const int red2 = 5;
const int yellow2 = 6;
const int green2 = 7;

// Pino do sensor de luz
const int ldrPin = A0;

// Limite para alternar entre dia e noite (ajustável)
const int lightThreshold = 500;

void setup() {
  // Configurar pinos dos LEDs como saída
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  // Inicializar comunicação serial (opcional, para debug)
  Serial.begin(9600);
}

void loop() {
  // Ler valor do LDR
  int lightLevel = analogRead(ldrPin);

  // (Opcional) Imprimir o valor lido no monitor serial para calibração
  Serial.println(lightLevel);

  if (lightLevel < lightThreshold) {
    // Modo noturno: Piscar LED amarelo
    // Apagar todos os LEDs
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
   

    delay(500); // 500ms ligado
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    delay(500); // 500ms desligado
  } else {
    // Modo diurno: Semáforo normal
    // Semáforo da via 1: Verde
    digitalWrite(green1, HIGH);
    digitalWrite(red2, HIGH); // Via 2: Vermelho
    delay(5000); // 5 segundos

    // Semáforo da via 1: Amarelo
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
    delay(2000); // 2 segundos

    // Semáforo da via 1: Vermelho
    digitalWrite(yellow1, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, LOW); // Via 2: Verde
    digitalWrite(green2, HIGH);
    delay(5000); // 5 segundos

    // Semáforo da via 2: Amarelo
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
    delay(2000); // 2 segundos

    // Semáforo da via 2: Vermelho
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, HIGH);
    digitalWrite(red1, LOW); // Volta para a via 1: Verde
  }
}