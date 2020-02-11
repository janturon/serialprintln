#include <stdarg.h>

void Serialprintln(const char* input...) {
  va_list args;
  va_start(args, input);
  for(const char* i=input; *i!=0; ++i) {
    if(*i!='%') { Serial.print(*i); continue; }
    switch(*(++i)) {
      case '%': Serial.print('%'); break;
      case 's': Serial.print(va_arg(args, char*)); break;
      case 'd': Serial.print(va_arg(args, int), DEC); break;
      case 'b': Serial.print(va_arg(args, int), BIN); break;
      case 'o': Serial.print(va_arg(args, int), OCT); break;
      case 'x': Serial.print(va_arg(args, int), HEX); break;
      case 'f': Serial.print(va_arg(args, double), 2); break;
    }
  }
  Serial.println();
  va_end(args);
}

void setup() {
  int n = 42;
  float f = 42.42;
  const char* s = "answer";
  Serial.begin(9600);

  // The answer is 42 (101010 BIN, 2A HEX), in float 42.42
  Serialprintln("The %s is %d (%b BIN, %x HEX), in float %f", s, n, n, n, f);
}

void loop() {
}