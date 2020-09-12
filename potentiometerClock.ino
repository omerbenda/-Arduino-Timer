int D4 = 13;
int A = 12;
int F = 11;
int D3 = 10;
int D2 = 9;
int B = 8;
int E = 7;
int D = 6;
int DP = 5;
int C = 4;
int G = 3;
int D1 = 2;

int waitTime = 6;

int potPin = A0;
int buttonPin = 1;
int pressed = false;
int val = 0;

int ms = 0;
int units = 0;
int tens = 0;
int hundreds = 5;
int thousands = 4;

void zero()
{
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void one()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void two()
{
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void three()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void four()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void five()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void six()
{
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void seven()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void eight()
{
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void nine()
{
  digitalWrite(E, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit1()
{
  digitalWrite(D1, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
}

void digit2()
{
  digitalWrite(D2, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D1, LOW);
}

void digit3()
{
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
}

void digit4()
{
  digitalWrite(D4, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
}

void change(int num)
{
  if (num == 0)
  {
    zero();
  }
  else
  {
    if (num == 1)
    {
      one();
    }
    else
    {
      if (num == 2)
      {
        two();
      }
      else
      {
        if (num == 3)
        {
          three();
        }
        else
        {
          if (num == 4)
          {
            four();
          }
          else
          {
            if (num == 5)
            {
              five();
            }
            else
            {
              if (num == 6)
              {
                six();
              }
              else
              {
                if (num == 7)
                {
                  seven();
                }
                else
                {
                  if (num == 8)
                  {
                    eight();
                  }
                  else
                  {
                    nine();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void loop() {
  if (pressed)
  {
    if (ms >= 1000)
    {
      units = units - ms / 1000;
      ms = 0;
    }
    if (units < 0)
    {
      units = 9;
      tens = tens - 1;
      if (tens < 0)
      {
        tens = 5;
        hundreds = hundreds - 1;
        if (hundreds < 0)
        {
          thousands = thousands - 1;
          if (thousands > 0)
          {
            hundreds = 9;
            tens = 0;
            units = 0;
          }
        }
      }
    }
  }else
  {
    ms = 0;
    val = map(analogRead(potPin), 0, 1023, 0, 5959);
    thousands = val / 1000;
    hundreds = (val / 100) % 10;
    tens = val / 10 % 10;
    if (tens >= 6)
    {
      tens = 0;
    }
    units = val % 10;
  }
  

  digit1();
  change(units);
  delay(waitTime);
  digit2();
  change(tens);
  delay(waitTime);
  digit3();
  change(hundreds);
  delay(waitTime);
  digit4();
  change(thousands);
  delay(waitTime);
  ms = ms + waitTime * 4;

  if (pressed == false)
  {
    if (digitalRead(buttonPin) == HIGH)
    {
      pressed = true;
    }
  }
}
