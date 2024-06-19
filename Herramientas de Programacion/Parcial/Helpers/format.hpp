#ifndef FORMAT_H
#define FORMAT_H
string format(string cadena){
  for (int i = 0; i < cadena.length(); i++) cadena[i] = toupper(cadena[i]);
  return cadena;
}
#endif
