////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                      Photo resistors in depth
//
// https://piandmore.wordpress.com/2016/10/14/photo-resistors-in-depth/
//
////////////////////////////////////////////////////////////////////////////////////
//
// The number of steps after which the header is repeated
//
#define STEPCOUNT 10
//
// The current step count
//
byte step = STEPCOUNT;

void setup() {
  //
  // Setup serial
  //
  Serial.begin(115200);
  Serial.println("Ready");
  //
  // Set the reference for measuring the analog signals
  // For some reason I got incorrect readings without connecting
  // the 3.3v (on my Arduino Nano) to AREF and setting this
  // reference
  analogReference(EXTERNAL);
  //
  // Setup all analog inputs. We are using 5 which is the maximum
  // for the Nano on which I tested.
  //
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
  //
  // Increase our counter
  //
  step++;
  //
  // If we are over our STEPCOUNT then we repeat the header
  //
  if (step>STEPCOUNT) {
    //
    // The reference to the different photo resistors
    // GL5506, GL5516, GL5528, GL5537 and GL 5539
    //
    Serial.println("* 5506  5516  5528  5537  5539");
    step = 0;
  }
  //
  // Print all analog values to serial
  //
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

