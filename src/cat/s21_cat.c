#include "s21_cat.h"
int main(int argc, char *argv[]) {
  int argument = 0;
  argument = argumenti(argc, argv, &argument);
  printick(argc, argv, argument);
}

int argumenti(int argc, char *argv[], int *argument) {
  char bukva = '|';
  for (int i = 1; (bukva = getopt_long(argc, argv, short_options, long_options,
                                       NULL)) != -1;
       i++) {
    if (bukva == 'v') *argument += 1;
    if (bukva == 'e' || bukva == 'E') *argument += 10;
    if (bukva == 's') *argument += 100;
    if (bukva == 'n') *argument += 1000;
    if (bukva == 't' || bukva == 'T') *argument += 10000;
    if (bukva == 'b') *argument += 100000;
    if (bukva == 'A') *argument = 10011;
  }

  return *argument;
}
void printick(int argc, char *argv[], int argument) {
  int chetchik = 0, flag = 0;
  char b_pred = 10, s_p = 10, ss_p = 1;
  if (argv[0][10] != '-') argument = 0;
  for (int i = 1; i < argc; i++) {
    FILE *file = NULL;
    file = fopen(argv[i], "r");
    flag = 0;
    b_pred = 10;
    if (file) {
      chetchik = 1;
      char out = '0';
      s_p = 10;
      while ((out = fgetc(file)) != -1) {
        if (argument % 1000 / 100 == 1 && s_p == 10 && out == 10 &&
            ss_p == 10) {
          continue;
        }
        if (argument % 1000000 / 100000 != 1 && argument % 10000 / 1000 == 1 &&
            flag == 0) {  //-n
          printf("%6d\t", chetchik);
          chetchik += 1;
          flag += 1;
        }
        if (out == 10 || out == -1) flag = 0;
        if (argument % 100 / 10 == 1 && out == 10) {
          printf("$");
        }
        if (argument % 1000000 / 100000 == 1 && b_pred == 10 && out != 10) {
          printf("%6d\t", chetchik);
          chetchik += 1;
        }
        if ((argument % 10 == 1 || argument % 100000 / 10000 == 1 ||
             argument % 100 / 10 == 1) &&
            (out >= -110 && out < 32 && out != 10 && out != 9)) {
          printf("^");
          out += 64;
        }
        if ((argument % 10 == 1 || argument % 100000 / 10000 == 1 ||
             argument % 100 / 10 == 1) &&
            (out > 126)) {
          printf("^");
          out -= 64;
        }
        if (argument % 100000 / 10000 == 1 && out == 9) {
          printf("^");
          out = 73;
          //-t
        }
        ss_p = s_p;
        s_p = out;
        b_pred = out;
        printf("%c", out);
      }
      fclose(file);

    } else {
      if (argv[i][0] != '-')
        fprintf(stderr, "%s", "No such file or directory\n");
    }
  }
}
