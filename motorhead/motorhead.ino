#include <NewPing.h>
 
/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Motors Constrains
int ENA = 10;
int IN3 = 9; 
int IN4 = 8;

int ENB = 5;
int IN1 = 7;
int IN2 = 6;





void setup() {
  Serial.begin(9600);
  
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);     
  pinMode (IN3, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}
 
void loop() {

  
  // Esperar 1 segundo entre mediciones
  delay(250);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  int cm = uS / US_ROUNDTRIP_CM;

  if(cm <= 20){
   Parar();
   delay(250);
   Derecha();
   
   }else{
    Adelante();
    }
//  Imprimir la distancia medida a la consola serial
  //Serial.print("Distancia: ");
  // Calcular la distancia con base en una constante
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  
  //Adelante();
}


void Adelante(){
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  analogWrite (ENA, 128); //Velocidad motor A

    
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
  analogWrite (ENB, 128); //Velocidad motor B

 }

void Atras(){
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); 
  analogWrite (ENA, 110); //Velocidad motor A

    
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH);
  analogWrite (ENB, 110); //Velocidad motor B
 }

void Derecha(){

 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 105); //Velocidad motor A
 
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 105); //Velocidad motor B
}

void Izquierda(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 105); //Velocidad motor A
  
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);  
  analogWrite (ENB, 105); //Velocidad motor B
}

void Parar(){

 digitalWrite (IN3, LOW);
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 digitalWrite (IN4, LOW);
  
}
