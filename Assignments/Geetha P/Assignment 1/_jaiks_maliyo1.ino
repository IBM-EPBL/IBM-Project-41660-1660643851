int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 4;
int const LED = 7;
int sensor = 2;

void setup()
{
  pinMode (LED,OUTPUT);
   pinMode(sensor, INPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT); 
	pinMode(buzzPin, OUTPUT);
}

void loop()
{
 
   int sensor = digitalRead(sensor);
  Serial.println(sensor);
  
  if (sensor == HIGH) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
    
  int duration, distance;
	
	digitalWrite(trigPin, HIGH); 
	delay(1);
	digitalWrite(trigPin, LOW);
	
	duration = pulseIn(echoPin, HIGH);
	// Distance is half the duration devided by 29.1 (from datasheet)
	distance = (duration/2) / 29.1;
	// if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance <= 50 && distance >= 0) {
    	
    	digitalWrite(buzzPin, HIGH);
    } else {
    	
    	digitalWrite(buzzPin, LOW);
    }
    // Waiting 60 ms won't hurt any one
    delay(60);
}