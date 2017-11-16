#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

double vref = 5;

int escolha = 1;

bool btn_pressed[3] = {false, false, false};

String comando = "";

#define botao_1 8

#define botao_2 9

#define botao_3 10

unsigned long tempoAtual = 0, tempoAnterior = 0;

//Variáveis Voltímetro
  double tensao = 0;
  int controleEscalaVolt[3] = {5,6,7};
  #define portaVoltimetro A0
//--------------------

//Variáveis Ohmimetro
  double resistencia = 0;
  double resistorRef[3] = {2015, 100600, 10000000};
  int controleEscala[3] = {2,3,4};
  #define portaOhmimetro A1
//--------------------

//Variáveis Amperimetro
  double corrente = 0;
  #define portaAmperimetro A2
//--------------------
