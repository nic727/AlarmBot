int redPin=9;  //set red LED pin to 11
int greenPin=7; //set green LED pin to 10
int bluePin=8; //set blue LED pin to 6

int brightness=100;
const int sequence_len = 5;
int sequence[sequence_len];
bool is_done = false;
int red_light = 0;
int blue_light = 0;
int green_light = 0;
int count = 0;
  

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //Turn on Serial port
pinMode(redPin, OUTPUT); //Set redPin to be an output
pinMode(greenPin, OUTPUT); //Set greenPin to be an output
pinMode(bluePin, OUTPUT); //set bluePin to be an output

}

void loop() {
  // put your main code here, to run repeatedly:
  if(count == 0){
    generateSequence();
  }

  if(count < 5) {
    switch (sequence[count]) {
      case 1:
        red_light = brightness;
        analogWrite(redPin, red_light);
        break;
      case 2:
        blue_light = brightness;
        analogWrite(bluePin, blue_light);
        break;
      case 3:
        green_light = brightness;
        analogWrite(greenPin, green_light);
        break;
      case 4:
        green_light = brightness;
        red_light = brightness;
        analogWrite(greenPin, green_light);
        analogWrite(bluePin, blue_light);
        
      default:
        red_light = 0;
        blue_light = 0;
        green_light = 0;
    }
  }else {
        analogWrite(greenPin, 100);
        analogWrite(bluePin, 100);
        analogWrite(redPin, 100);
    }
      delay(2000);
      red_light = 0;
      blue_light = 0;
      green_light = 0;
      analogWrite(greenPin, green_light);
      analogWrite(bluePin, blue_light);
      analogWrite(redPin, red_light);
      count++;
}
void generateSequence() {
  for(int i =0; i<sequence_len;i++) {
      sequence[i] = random(1, 5);
    }
  }


void generateColor() {

for (int i=0; i < sequence_len; i++){
  switch (sequence[i]) {
    case 1:
      red_light = brightness;
      analogWrite(redPin, red_light);
      break;
    case 2:
      blue_light = brightness;
      analogWrite(bluePin, blue_light);
      break;
    case 3:
      green_light = brightness;
      analogWrite(greenPin, green_light);
      break;
    case 4:
      green_light = brightness;
      red_light = brightness;
      
    default:
      red_light = 0;
      blue_light = 0;
      green_light = 0;
  }
  delay(2000);
}
  }
