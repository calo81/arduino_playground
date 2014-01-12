
char inData[20];
char inChar=-1; 
byte index = 0;
int led = 13;
 
void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}
 
void loop() {
    if(Comp("lightsOn")==0){
       digitalWrite(led, HIGH);
       Serial.println("lights on;");
    }
    else if(Comp("lightsOff")==0){       
       digitalWrite(led, LOW);
       Serial.println("lights off;");
    }   
}
 
char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }
 
    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else {
        return(1);
    }
}
