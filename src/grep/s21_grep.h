#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int f;

  char patern[50][10000];
  char srtochka[10000];
} flags;
void parser(int argc, char *argv[], flags *bukva, flags *poryadok,
            int *kol_patern);
void func_f(char *argv[], flags *bukva, int *kol_patern, flags poryadok);
void func_e(char *argv[], flags *bukva, int *kol_patern, flags poryadok);
void numb_file(int argc, int *kol_failov);
void out_put(int argc, char *argv[], flags bukva, int kol_failov,
             int kol_patern);

void func_o(char *argv[], flags bukva, int strochka_nomer, int kol_failov,
            int ii, int i);