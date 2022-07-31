#define DELAY_TIME 1000
#define SHORT 13
#define LONG 8

#define MESSAGE "DARCY"

static const char *alpha[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
    "/" //" "
};

static const char trans[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

int find_char(char ch){
  int i;
  for(i=0;i < sizeof(trans);i++){
    if(trans[i] == ch){
      break;
    }
  }

  return i;
}
void show_msg(char *position){
  int x = 1;

  while(*position != '\0'){
    digitalWrite(SHORT, LOW);
    digitalWrite(LONG, LOW);
    delay(DELAY_TIME);

    if(*position == '.'){
      digitalWrite(SHORT, HIGH);
      delay(DELAY_TIME + 500);
    }
    else{
      digitalWrite(LONG, HIGH);
      delay(DELAY_TIME + 500);
    }
    position++;
  }
  digitalWrite(SHORT, LOW);
  digitalWrite(LONG, LOW);
  delay(DELAY_TIME);
  digitalWrite(LONG, HIGH);
  digitalWrite(SHORT, HIGH);
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  int position;
  char msg[] = MESSAGE;

  for(int i=0; i<strlen(msg);i++){
    position = find_char(msg[i]);
    show_msg((char *)alpha[position]);
    delay(DELAY_TIME);
  }
}
