#include<16f887.h>
#fuses hs,put,noprotect,nolvp,nowdt
#use delay(clock=40M)
unsigned INT8 y;
void on(void){
  y=0xFF;// 11111111
  output_d(y);
  delay_ms(500);

}
void off(void){
  y=0x00;//00000000
  output_d(y);
  delay_ms(500);

}
void sangduoi(){
  unsigned char a;
  for(a=0;a<4;a++) {        //y=10111111
  y=(((y<<2)|0x03)&0x7F);//   y=11011111
  output_d(y);//           0xBF=10111111=10011111
  delay_ms(700);
}//         0x7F=01111111 =00001111
}
void sangduoi1(){
  unsigned char a;
  for(a=0;a<5;a++)
  {
    y=((y>>1)|0x20);
    delay_ms(500);
    output_d(y);
  }

}
void tatduoi(){
  unsigned char a;
  for(a=0;a<7;a++)
  {
    y=((y>>1)&0xBF);
    delay_ms(500);
    output_d(y);
  }
}

void main(void){
  while(1){
    on();
    off();
    sangduoi();
    off();
    sangduoi();
    off();
    sangduoi1();
    off();
    sangduoi1();
    off();
    on();
    tatduoi();
    on();
    tatduoi();

  }
}
