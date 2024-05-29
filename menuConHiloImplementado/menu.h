#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int mainMenu(int anchoConsola, int altoConsola);
int inicio(int x, int y);
void menuInicio(int x, int y);
void cursosClean(int ver);
void cuadroMenu(int x, int y);
void tituloMenu(int x, int y);
void selectCrearUsuario(x,y);
void selectIniciarSesion(x,y);
void detallesMenu(int x, int y);
void leerLimite(char *digitos, int max);
void leerLimiteNumeros(char *digitos, int max);
void crearUsuario(int x, int y, char dni[], char contra[]);
void cuadroEscritura(int x,int y);
void ingresaUsuario(int x, int y, char dni[], char contra[]);

#endif // MENU_H_INCLUDED
