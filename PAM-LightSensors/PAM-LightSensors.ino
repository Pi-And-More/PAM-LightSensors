// Repeat the header after STEPCOUNT steps
#define STEPCOUNT 10
byte step = STEPCOUNT;

void setup() {
// Setup serial
  Serial.begin(115200);
  Serial.println("Ready");
// Set the reference 
  analogReference(EXTERNAL);
// Setup all analog inputs. We are using 5 which is the maximum
// for the Nano on which I tested.
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
// Increase our counter
  step++;
// If we are over our STEPCOUNT then we repeat the header
  if (step>STEPCOUNT) {
    Serial.println("* 5506  5516  5528  5537  5539");
    step = 0;
  }
// Print all analog values to serial
  Serial.print("  ");
  Serial.print(analogRead(A0));
  Serial.print("   ");
  Serial.print(analogRead(A1));
  Serial.print("   ");
  Serial.print(analogRead(A2));
  Serial.print("   ");
  Serial.print(analogRead(A3));
  Serial.print("   ");
  Serial.print(analogRead(A4));
  Serial.println();
  delay(250);
}

