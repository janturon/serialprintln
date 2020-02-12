#include <stdarg.h>

void Serialprintln(const char* format, ...) {
  va_list args;
  va_start(args, format);
  for(const char* i=format; *i!=0; ++i) {
    if(*i!='%') Serial.print(*i);
    else switch(*(++i)) {
      case 0: Serial.print('%'); --i; break; // % at the EOS
      case '%': Serial.print('%'); break;
      case 's': Serial.print(va_arg(args, char*)); break;
      case 'c': Serial.print((char)va_arg(args, int)); break;
      case 'd': Serial.print(va_arg(args, int), DEC); break;
      case 'b': Serial.print(va_arg(args, int), BIN); break;
      case 'o': Serial.print(va_arg(args, int), OCT); break;
      case 'x': Serial.print(va_arg(args, int), HEX); break;
      case 'f': Serial.print(va_arg(args, double), 2); break;
      default: Serial.print('%'); Serial.print(*i); break;
    }
  }
  Serial.println();
  va_end(args);
}

void setup() {
  int n = 42;
  float f = 42.42;
  const char* s = "answer";
  char c = '!';
  Serial.begin(9600);

  // The answer was 42 (101010 BIN, 2A HEX), refined as 42.42!
  Serialprintln("The %s was %d (%b BIN, %x HEX), refined as %f%c", s, n, n, n, f, c);
}

void loop() {
}