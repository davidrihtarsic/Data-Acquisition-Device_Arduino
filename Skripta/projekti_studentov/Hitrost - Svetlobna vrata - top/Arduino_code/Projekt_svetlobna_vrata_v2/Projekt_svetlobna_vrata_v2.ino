/*Avtorja: Nejc Urbas
           Matjaž Jerala
  Datum: 2018-03-21

  OPIS PROJEKTA:
  Program je namenjen meritvi hitrosti izstrelka iz balističnega topa.
*/
#define number_of_gates 3
byte gate_input_pins[] = {
  14,
  15,
  16
};

bool pull_up_resistor[] = {
  0,
  0,
  0
};

byte normal_gate_state[] = {
  0,
  0,
  0
};

long gate_time[] = {
  0,
  0,
  0
};
void print_table_header(){
  Serial.println("t0 [us],  t1 [us], t2 [us]");
}
void print_table_data(){
  for (byte i = 0; i < number_of_gates; i++) {
    if (i == (number_of_gates - 1)){
      Serial.println(gate_time[i]);
    } else{
      Serial.print(gate_time[i]);
      Serial.print(", ");
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("Number of gates:");Serial.println(number_of_gates);
  for (byte i = 0; i < number_of_gates; i++) {
    if ( pull_up_resistor[i] ){
      pinMode(gate_input_pins[i], INPUT_PULLUP);
    }else{
      pinMode(gate_input_pins[i], INPUT);
    }
    normal_gate_state[i] = digitalRead(gate_input_pins[i]);
    Serial.print("Gate[");Serial.print(i);Serial.print("] = ");Serial.println(normal_gate_state[i]);
  }
  Serial.println("= = = = = = = =");
  print_table_header();
}

void loop() {
  for (byte i = 0; i < number_of_gates; i++) {
    //Serial.println(i);
    while (digitalRead(gate_input_pins[i]) == normal_gate_state[i]){}
    gate_time[i] = micros();
    //Serial.println(gate_time[i]);
  }
  print_table_data();
}
