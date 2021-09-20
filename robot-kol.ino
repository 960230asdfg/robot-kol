  
#include <Servo.h>

#define BUTON_SURESI  500
#define pot_el A0
#define pot_yukseklik A1
#define pot_donus A2
#define pot_aci A3

#define LED_PIN 8
#define BUTON_1 5
#define BUTON_2 2
#define BASILI LOW
#define SERBEST HIGH


Servo servo_yukseklik;
Servo servo_el;
Servo servo_aci;
Servo servo_donus;

int buton_1_eski_durum = SERBEST; // LOW ise basılı demek
int buton_2_eski_durum = SERBEST;

int buton_1_basma_say;
int buton_2_basma_say;

unsigned long buton_1_son_basma ;
unsigned long buton_2_son_basma ;

int pot_el_hafiza = -1;
int pot_yukseklik_hafiza = -1;
int pot_donus_hafiza = -1;
int pot_aci_hafiza = -1;




void setup() {
  Serial.begin(115200);
  pinMode(BUTON_1,INPUT);
  pinMode(BUTON_2,INPUT);
  pinMode(LED_PIN,OUTPUT);
  
  servo_yukseklik.attach(6);
  servo_el.attach(9);
  servo_aci.attach(11);
  servo_donus.attach(10); 
  delay(100); 
  Serial.println("setup");
}

void loop() {
  int deger;
  int derece;
  
  buton_1_kontrol();
  buton_2_kontrol();

  if(pot_yukseklik_hafiza!=-1)
    deger=pot_yukseklik_hafiza;
  else
    deger = analogRead(pot_yukseklik);
  derece = map(deger, 0,1023,95,0);
  servo_yukseklik.write(derece);
  //Serial.print("yukseklik:"+String(derece)+"  |  "  );
    
  if(pot_el_hafiza!=-1)
    deger=pot_el_hafiza;
  else
    deger = analogRead(pot_el);
  derece = map(deger, 0,1023,0,180);
  servo_el.write(derece);
  //Serial.print("el:"+String(derece)+"  |  "  );  
   

  if(pot_donus_hafiza!=-1)
    deger=pot_donus_hafiza;
  else
    deger = analogRead(pot_donus);
  derece = map(deger, 0,1023,150,30);
  servo_donus.write(derece);
  //Serial.print("donus:"+String(derece)+"  |  "  );


  if(pot_aci_hafiza!=-1)
    deger=pot_aci_hafiza;
  else
    deger = analogRead(pot_aci);
  derece = map(deger, 0,1023,80,180);
  servo_aci.write(derece);
  //Serial.println("aci:"+String(derece) );


  /*
  Serial.print("A0:"+ String(analogRead(A0))); 
  Serial.print("  |  A1:"+ String(analogRead(A1))); 
  Serial.print("  |  A2:"+ String(analogRead(A2))); 
  Serial.println("  |  A3:"+ String(analogRead(A3))); 
  */

  delay(30);
}



void buton_1_kontrol()
{ 
  // BUTON 1
  int yeni_durum = digitalRead(BUTON_1);
  if (yeni_durum != buton_1_eski_durum) //değişti
  {  
    if(yeni_durum==BASILI && buton_1_eski_durum==SERBEST)//BASTIM
    {
      if(buton_1_basma_say>0 && (millis()-buton_1_son_basma)<BUTON_SURESI)//2basma
      {
        buton_1_cift_basma();
        buton_1_son_basma=0;
        buton_1_basma_say=0;
        Serial.println("/");
      }
      else if(buton_1_basma_say==0 && buton_1_son_basma==0)// ilk bastığım an                                          
      {
        buton_1_basma_say = arttir(buton_1_basma_say);
        buton_1_son_basma = millis();
        Serial.print("/");
      }
    }   
    else if(yeni_durum==SERBEST && buton_1_eski_durum==BASILI) 
    {
       Serial.println("\\");
    } 
  } 
   
  if( buton_1_basma_say>0 && millis()-buton_1_son_basma>=BUTON_SURESI)
  {
    Serial.println("*");
    if(yeni_durum==BASILI) //loong cick
    {
      buton_1_uzun_basma();      
    }
    else if(yeni_durum==SERBEST) // tek click
    {
      buton_1_tek_basma();      
    }
    buton_1_son_basma=0;
    buton_1_basma_say=0;
  }  
  buton_1_eski_durum = yeni_durum;

}


void buton_1_tek_basma()
{
  Serial.println("B1 Single click");
  if(pot_donus_hafiza==-1)
    pot_donus_hafiza = analogRead(pot_donus);
  else
    pot_donus_hafiza = -1;
}  

void buton_1_cift_basma() //el
{
  Serial.println("B1 Double click");
  if(pot_el_hafiza==-1)
    pot_el_hafiza = analogRead(pot_el);
  else
    pot_el_hafiza = -1;
  
}  

void buton_1_uzun_basma() // reset
{
  Serial.println("B1 Long click");
  pot_el_hafiza = -1;
  pot_yukseklik_hafiza = -1;
  pot_donus_hafiza = -1;
  pot_aci_hafiza = -1;
}


void buton_2_kontrol()
{ 
  // BUTON 2
  int yeni_durum = digitalRead(BUTON_2);
  if (yeni_durum != buton_2_eski_durum) //değişti
  {  
    if(yeni_durum==BASILI && buton_2_eski_durum==SERBEST)//BASTIM
    {
      if(buton_2_basma_say>0 && (millis()-buton_2_son_basma)<BUTON_SURESI)//2basma
      {
        buton_2_cift_basma();
        buton_2_son_basma=0;
        buton_2_basma_say=0;
        Serial.println("/");
      }
      else if(buton_2_basma_say==0 && buton_2_son_basma==0)// ilk bastığım an                                          
      {
        buton_2_basma_say = arttir(buton_2_basma_say);
        buton_2_son_basma = millis();
        Serial.print("/");
      }
    }   
    else if(yeni_durum==SERBEST && buton_2_eski_durum==BASILI) 
    {
       Serial.println("\\");
    } 
  }       
  if( buton_2_basma_say>0 && millis()-buton_2_son_basma>=BUTON_SURESI)
  {
    Serial.println("*");
    if(yeni_durum==BASILI) //loong cick
    {
      buton_2_uzun_basma();      
    }
    else if(yeni_durum==SERBEST) // tek click
    {
      buton_2_tek_basma();      
    }
    buton_2_son_basma=0;
    buton_2_basma_say=0;
  }  
  buton_2_eski_durum = yeni_durum;

}


void buton_2_tek_basma() //donus
{
  Serial.println("B2 Single click");
  if(pot_donus_hafiza==-1)
    pot_donus_hafiza = analogRead(pot_donus);
  else
    pot_donus_hafiza = -1;
}  

void buton_2_cift_basma() // yukseklik
{
  Serial.println("B2 Double click");
  if(pot_yukseklik_hafiza==-1)
    pot_yukseklik_hafiza = analogRead(pot_yukseklik);
  else
    pot_yukseklik_hafiza = -1;
}  

void buton_2_uzun_basma() // ısık
{
  Serial.println("B2 Long click");
  int durum = digitalRead(LED_PIN); 
  if (durum == HIGH)
    digitalWrite(LED_PIN,LOW);
  else
    digitalWrite(LED_PIN,HIGH);

}
int arttir(int a)
{
  a = a +1; // a++;
  return a;  
}
