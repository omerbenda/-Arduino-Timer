// Pins variable setup for the 4 7 segment component
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

// Refresh rate of the 4 7 segment component (1/waitTime Hz)
int waitTime = 6;

// Variable for button and potentiometer
int potPin = A0;
int buttonPin = 1;
int pressed = false;
int val = 0;

// Counting variable for display
int ms = 0;
int units = 0;
int tens = 0;
int hundreds = 5;
int thousands = 4;

void zero()
{
  // Changes digits displayed to zero
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
  // Changes digits displayed to one
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
  // Changes digits displayed to two
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
  // Changes digits displayed to three
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
  // Changes digits displayed to four
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
  // Changes digits displayed to five
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
  // Changes digits displayed to six
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
  // Changes digits displayed to seven
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
  // Changes digits displayed to eight
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
  // Changes digits displayed to nine
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
  // Turns the first digit on (The units digit) and turns all other digits off
  digitalWrite(D1, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
}

void digit2()
{
  // Turns the second digit on (The tens digit) and turns all other digits off
  digitalWrite(D2, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D1, LOW);
}

void digit3()
{
  // Turns the third digit on (The hundreds digit) and turns all other digits off
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
}

void digit4()
{
  // Turns the fourth digit on (The thousands digit) and turns all other digits off
  digitalWrite(D4, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
}

void change(int num)
{
  // Changes digit displayed based on the num parameter
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
  // Turns the 4 7 segment component pins to output
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

  // Changes the button pin to input mode
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (pressed)
  {
    if (ms >= 1000) // if a second has passed
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
    val = map(analogRead(potPin), 0, 1023, 0, 5959); // Gets value for timer's interval
    thousands = val / 1000;
    hundreds = (val / 100) % 10;
    tens = val / 10 % 10;
    if (tens >= 6)
    {
      tens = 0;
    }
    units = val % 10;
  }
  
  // Changes the digits, timed by waitTime
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

  // Checks if button was ever pressed
  if (pressed == false)
  {
    if (digitalRead(buttonPin) == HIGH)
    {
      pressed = true;
    }
  }
}
