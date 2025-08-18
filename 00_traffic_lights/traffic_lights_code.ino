// C++ code
void setup()
{
  // Defino los pines 2, 3 y 4 como salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite (2, HIGH);  //Enciendo pin verde
  delay (5000);            //Pausa de 5 segundos
  digitalWrite (2, LOW);   //Apago pin verde
  
  digitalWrite (3, HIGH);  //Enciendo pin Amarillo
  delay (3000);            //Pausa de 5 segundos
  digitalWrite (3, LOW);   //Apago pin Amarillo
  
  digitalWrite (4, HIGH);  //Enciendo pin Rojo
  delay (5000);            //Pausa de 5 segundos
  digitalWrite (4, LOW);   //Apago pin Rojo
  
  digitalWrite (3, HIGH);  //Enciendo pin Amarillo
  delay (3000);            //Pausa de 5 segundos
  digitalWrite (3, LOW);   //Apago pin Amarillo
}
