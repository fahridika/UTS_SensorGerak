#define ledHijau 2
#define ledMerah 5
#define trigPin 7
#define echoPin 6
#define echo_gerak 3
#define trig_gerak 4

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trig_gerak, OUTPUT);
  
  pinMode(echoPin, INPUT);
  pinMode(echo_gerak, INPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);

}
void loop() {
  long duration_awal, distance_awal, duration_after, distance_after;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration_awal = pulseIn(echoPin, HIGH);
  distance_awal = (duration_awal/2) / 29.1;

  digitalWrite(trig_gerak, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_gerak, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_gerak, LOW);
  duration_after = pulseIn(echo_gerak, HIGH);
  distance_after = ((duration_after)/2) / 29.1;

  

   

  

  if (distance_awal == distance_after ) //ga gerak
{
      digitalWrite(ledHijau, LOW);
     
      digitalWrite(ledMerah, HIGH);   
  }

  if (distance_awal > distance_after) //Jika kurang dari 20cm
{
      digitalWrite(ledHijau, HIGH); //Menyala
      digitalWrite(ledMerah, LOW); //Mati
  }

  if (distance_awal < distance_after) //Jika kurang dari 10cm
{
      digitalWrite(ledHijau, HIGH); //Menyala
      digitalWrite(ledMerah, LOW); //Mati
}

 Serial.print("Pergerakan :");
 Serial.print(distance_after - distance_awal );
 Serial.println("cm");
 
 delay(100);
}
