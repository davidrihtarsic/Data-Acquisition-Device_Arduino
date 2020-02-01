void setup() {
  // put your setup code here, to run once:
  pinMode(18,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int stanje_vhoda =0;
  stanje_vhoda = digitalRead(16); // Prva vrata smo priključili na vhod števila 16.

   while(digitalRead(16) == 0){  
   }
   long t1 = millis();
   delay(10);         //Čakam...
   //Serial.println("prekinjeno"); // Ko so prve svetlobna vrata prekinjena nam izpiše 0 oziroma prekinjeno. Začnemo beležiti čas (t1), ko se prekinejo.
  
   while(digitalRead(16) == 1){
   }
   long t2 = millis ();
   delay(10);     //Čakam...
   //Serial.println("prosto");  //Ko prva svetlobna vrata niso prekinjena nam izpiše 1 oziroma prosto. Zabeležimo čas(t2), ko so zopet prosta.
   
   long dt = (t2 - t1) ;  //Izračun spremembe zabeleženih časov na prvih svetlobnih vratih.
   //Serial.println(dt);
   delay(100);    //Čakam...

    Serial.println("hitrost je:");
    float v  = 1300 / (dt);     //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v);//Izpiše se nam hitrost na prvih svetlobnih vratih. 
    delay(100);     //Čakam...


    stanje_vhoda = digitalRead(17);   // Druga vrata smo priključili na vhod števila 17 (A3).

   while(digitalRead(17) == 0){  
   }
   long t3 = millis();
   delay(10);    //Čakam...
   //Serial.println("prekinjeno1");    //Ko so druga svetlobna vrata prekinjena nam izpiše 0 oziroma prekinjeno1. Začnemo beležiti čas (t3), ko se prekinejo.
  
   while(digitalRead(17) == 1){
   }
   long t4 = millis ();
   delay(10);    //Čakam...
   //Serial.println("prosto1");       //Ko prva svetlobna vrata niso prekinjena nam izpiše 1 oziroma prosto1. Zabeležimo čas(t4), ko so zopet prosta.
   
   long dt1 = (t4 - t3) ;           //Izračun spremembe zabeleženih časov na drugih svetlobnih vratih.
   //Serial.println(dt1);
   delay(100);    //Čakam...

    Serial.println("hitrost 1 je:");
    float v1  = 1300/ (dt1);         //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v1);           //Izpiše se nam hitrost na drugih svetlobnih vratih. 
    delay(100);    //Čakam...
    
   Serial.println("pospesek je:");  // Izračun pospešeka naše prepreke skozi prva in druga svetlobna vrata.
   float a = (v1-v)/(dt-dt1) *100;
   Serial.println(a);
   delay(100);   //Čakam...




    
   }
