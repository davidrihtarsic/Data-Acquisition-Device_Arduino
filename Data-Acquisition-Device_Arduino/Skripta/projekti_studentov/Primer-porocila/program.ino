const int analogInPin = A0; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;


void vzorcenje(){
	for(int i=0;i<10;i++){ 
		buf[i]=analogRead(analogInPin);
		delay(10);
	}
}

void povprecje(){
	for(int i=0;i<9;i++){
		for(int j=i+1;j<10;j++){
			if(buf[i]>buf[j]){
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}
	avgValue=0;
	for(int i=2;i<8;i++){
		avgValue+=buf[i];
	}
}

void izracun_vrednosti(){
	float pHVol=(float)avgValue*5.0/1024;
	float phValue = -5.70 * pHVol + 21.34;
}

void izpis(){
	Serial.print("sensor = ");
	Serial.println(phValue);
}

void setup() {
 Serial.begin(9600);
}
 
void loop() {
  vzorcenje();
	povprecje();
	izracun_vrednosti();
	izpis();
	delay(20);
}
