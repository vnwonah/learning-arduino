
 int firstSwitch = 2;
 int secondSwitch = 4;
 int thirdSwitch = 6;
 int fourthSwitch = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(firstSwitch, OUTPUT);
  pinMode(secondSwitch, OUTPUT);
  pinMode(thirdSwitch, OUTPUT);
  pinMode(fourthSwitch, OUTPUT);

}

char *decToBin(int decimalNumber) {

  Serial.print("----------");
  Serial.print(decimalNumber);
  Serial.print("----------");
  Serial.println();
  int i = 0;
  static char x[4] = "0000";  
  if(decimalNumber < 1) {
    Serial.println((String)x);
    return x;
  }
 
  while(i < 4) {

   int val = decimalNumber % 2;
    
   if(val > 0) 
    {
      x[i] = '1';
      Serial.println("pos");
      Serial.println(i);
      Serial.println((String)x);
    } 
    else 
    {
      x[i] = '0';
      Serial.println("neg");
      Serial.println(i);
      Serial.println((String)x);
    }
    i++;
    decimalNumber /= 2;
  }
  
  return x;
}

void printBinary(char *x) {
  // how to print sequence
  // I have these characters coming in
  // 1010
  x[0] == '1' ? digitalWrite(firstSwitch, HIGH) : digitalWrite(firstSwitch, LOW);
  x[1] == '1' ? digitalWrite(secondSwitch, HIGH) : digitalWrite(secondSwitch, LOW);
  x[2] == '1' ? digitalWrite(thirdSwitch, HIGH) : digitalWrite(thirdSwitch, LOW);
  x[3] == '1' ? digitalWrite(fourthSwitch, HIGH) : digitalWrite(fourthSwitch, LOW);
}

void loop() {

  // put your main code here, to run repeatedly:
  // task, count from one to 15

  for(int i = 0; i < 16; i++) {
    char *binaryRep;
    binaryRep = decToBin(i);
    printBinary(binaryRep);   
    delay(5000);
  }

}
