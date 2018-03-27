int xPin = A0;
int yPin = A1;
int xPos = 0;
int yPos = 0;

int rgbPin = A2;
int rgb = 0;

unsigned long targetTime=0;
const unsigned long interval=200; //TODO: How fast should we read
int buttonPin = 4;
int buttonState = 0;

void setup(){
	Serial.begin(115200);
	pinMode(buttonPin, INPUT);
}


void loop(){
	if(millis()>=targetTime){
		buttonState = digitalRead(buttonPin);
		if(buttonState == HIGH){
			Serial.println("rst");
		}
		else{
			xPos = analogRead(xPin);
			yPos = analogRead(yPin);
			rgb = analogRead(rgbPin);
			rgb = map(rgb, 0, 1023, 0, 255);
			String data = String(xPos) + "," + String(yPos) + "," + String(rgb) + "\r\n";
			Serial.println(data);
		}
		targetTime = millis() + interval;
	}
}
