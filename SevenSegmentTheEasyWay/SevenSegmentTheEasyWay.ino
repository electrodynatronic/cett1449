/*
  Seven segment display driver the simple minded way
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int mycount = 0;     //keeps track of how many times I have pressed the buttons
int previous_count =0;     //keeps track of how many times I have pressed the buttons

#define IS_PRESSED 0

// The following named constants define the IO pin connections to the LED segments 
#define DECIMAL_POINT 11
#define SEGMENT_A 7
#define SEGMENT_B 6
#define SEGMENT_C 10
#define SEGMENT_D 9
#define SEGMENT_E 8
#define SEGMENT_F 4
#define SEGMENT_G 5
// The following named constants define the IO pin connections to the up and down buttons
#define BTN_UP 2
#define BTN_DOWN 3
//// The following named constants define the segments needed to display a digit on a seven segment display
//#define DIGIT_ZERO SEGMENT_A|SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F
//#define DIGIT_ONE SEGMENT_B|SEGMENT_C
//#define DIGIT_TWO SEGMENT_A|SEGMENT_B|SEGMENT_D|SEGMENT_E|SEGMENT_G
//#define DIGIT_THREE SEGMENT_E SEGMENT_A|SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_G
//#define DIGIT_FOUR SEGMENT_B|SEGMENT_C|SEGMENT_F|SEGMENT_G
//#define DIGIT_FIVE SEGMENT_A|SEGMENT_C|SEGMENT_D|SEGMENT_F|SEGMENT_G
//#define DIGIT_SIX SEGMENT_A|SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_SEVEN SEGMENT_A|SEGMENT_B|SEGMENT_C
//#define DIGIT_EIGHT SEGMENT_A|SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_NINE SEGMENT_A|SEGMENT_B|SEGMENT_C|SEGMENT_D|SEGMENT_F|SEGMENT_G
//#define DIGIT_A SEGMENT_A|SEGMENT_B|SEGMENT_C|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_B SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_C SEGMENT_A|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_D SEGMENT_C|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_E SEGMENT_A|SEGMENT_D|SEGMENT_E|SEGMENT_F|SEGMENT_G
//#define DIGIT_F SEGMENT_A|SEGMENT_E|SEGMENT_F|SEGMENT_G

//char digits[16] = {DIGIT_ZERO,
//                   DIGIT_ONE,
//                   DIGIT_TWO,
//                   DIGIT_THREE,
//                   DIGIT_FOUR,
//                   DIGIT_FIVE,
//                   DIGIT_SIX,
//                   DIGIT_SEVEN,
//                   DIGIT_EIGHT,
//                   DIGIT_NINE,
//                   DIGIT_A,
//                   DIGIT_B,
//                   DIGIT_C,
//                   DIGIT_D,
//                   DIGIT_E,
//                   DIGIT_F
//                   };

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  for(int i=4;i<=11;i++){  //sets 4 to 11 as outputs
     pinMode(i, OUTPUT); 
  }
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(BTN_UP)==IS_PRESSED){
    mycount+=1;
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  }
  if(digitalRead(BTN_DOWN)==IS_PRESSED){
    mycount-=1;
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  }

  if(mycount != previous_count){
    for(int i=4;i<=11;i++){ //clear all outputs
       digitalWrite(i,HIGH);
    }
    Serial.print("previous_count=");
    Serial.print(previous_count);
    previous_count=mycount;

    Serial.print("\tmycount=");
    Serial.println(mycount);

    switch (mycount%16) {
      case 0:
        disp_zero();
        ser_print_0();
        break;
      case 1:
        disp_one();
        ser_print_1();
        break;
      case 2:
        disp_two();
        ser_print_2();
        break;
      case 3:
        disp_three();
        ser_print_3();
        break;
      case 4:
        disp_four();
        ser_print_4();
        break;
      case 5:
        disp_five();
        ser_print_5();
        break;
      case 6:
        disp_six();
        ser_print_6();
        break;
      case 7:
        disp_seven();
        ser_print_7();
        break;
      case 8:
        disp_eight();
        ser_print_8();
        break;
      case 9:
        disp_nine();
        ser_print_9();
        break;
      case 0xa:
        disp_A();
        ser_print_A();
        break;
      case 11:
        disp_B();
        ser_print_B();
        break;
      case 12:
        disp_C();
        ser_print_C();
        break;
      case 13:
        disp_D();
        ser_print_D();
        break;
      case 14:
        disp_E();
        ser_print_E();
        break;
      case 15:
        disp_F();
        ser_print_F();
        break;
      default: 
        break;
    }
  }
//  digitalWrite((mycount%8)+4,LOW);
//      Serial.print("out=");
//    Serial.println((mycount%8)+4);
//    Serial.println((mycount%16), HEX);
delay(100);
}

void disp_zero(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,1);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_C,0);
}
void disp_one(){
  digitalWrite(SEGMENT_A,1);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,1);
  digitalWrite(SEGMENT_G,1);


}
void disp_two(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,1);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,1);
  digitalWrite(SEGMENT_G,0);


}
void disp_three(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,1);
  digitalWrite(SEGMENT_G,0);


}
void disp_four(){
  digitalWrite(SEGMENT_A,1);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);


}
void disp_five(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);


}
void disp_six(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);


}
void disp_seven(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,1);
  digitalWrite(SEGMENT_G,1);


}
void disp_eight(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);


}
void disp_nine(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,1);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);

}
void disp_A(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);

}
void disp_B(){
  digitalWrite(SEGMENT_A,1);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);

}
void disp_C(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,1);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,1);

}
void disp_D(){
  digitalWrite(SEGMENT_A,1);
  digitalWrite(SEGMENT_B,0);
  digitalWrite(SEGMENT_C,0);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,1);
  digitalWrite(SEGMENT_G,0);

}
void disp_E(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,1);
  digitalWrite(SEGMENT_D,0);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);

}
void disp_F(){
  digitalWrite(SEGMENT_A,0);
  digitalWrite(SEGMENT_B,1);
  digitalWrite(SEGMENT_C,1);
  digitalWrite(SEGMENT_D,1);
  digitalWrite(SEGMENT_E,0);
  digitalWrite(SEGMENT_F,0);
  digitalWrite(SEGMENT_G,0);

}

void ser_print_0(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print(" ");      //G
  Serial.println("|");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C

}
void ser_print_1(){
  Serial.println("  ");   //A
  Serial.print(" ");      //F
  Serial.print(" ");      //G
  Serial.println("|");    //B
  Serial.print(" ");      //E
  Serial.print(" ");      //D
  Serial.println("|");    //C
}
void ser_print_2(){
  Serial.println(" _");   //A
  Serial.print(" ");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("");    //C
}
void ser_print_3(){
  Serial.println(" _");   //A
  Serial.print(" ");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print(" ");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_4(){
  Serial.println(" ");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print(" ");      //E
  Serial.print(" ");      //D
  Serial.println("|");    //C
}
void ser_print_5(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("");    //B
  Serial.print(" ");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_6(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_7(){
  Serial.println(" _");   //A
  Serial.print(" ");      //F
  Serial.print(" ");      //G
  Serial.println("|");    //B
  Serial.print(" ");      //E
  Serial.print(" ");      //D
  Serial.println("|");    //C
}
void ser_print_8(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_9(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print(" ");      //E
  Serial.print(" ");      //D
  Serial.println("|");    //C
}
void ser_print_A(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print("|");      //E
  Serial.print(" ");      //D
  Serial.println("|");    //C
}
void ser_print_B(){
  Serial.println(" ");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_C(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("");      //G
  Serial.println("");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("");    //C
}
void ser_print_D(){
  Serial.println("");   //A
  Serial.print(" ");      //F
  Serial.print("_");      //G
  Serial.println("|");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("|");    //C
}
void ser_print_E(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("");    //B
  Serial.print("|");      //E
  Serial.print("_");      //D
  Serial.println("");    //C
}
void ser_print_F(){
  Serial.println(" _");   //A
  Serial.print("|");      //F
  Serial.print("_");      //G
  Serial.println("");    //B
  Serial.print("|");      //E
  Serial.print("");      //D
  Serial.println("");    //C
}

