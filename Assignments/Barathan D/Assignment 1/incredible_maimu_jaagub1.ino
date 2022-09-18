void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  pinMode(12,OUTPUT);
}
void loop()
{
  digitalWrite(13,LOW);
  int a =digitalRead(2);
  if(a==1){
    Serial.println("Mention detected!!");
    digitalWrite(13,HIGH);
  }
  delay(1000);
  {
    double a=analogRead(A0);
   double t=(((a/1024)*5)-0.5)*100;
  Serial.print("temprature sensor");
  Serial.println(t);
  if(t>35)
    digitalWrite(12,1);
  else
    digitalWrite(12,0);
   delay(1000);
}
}
