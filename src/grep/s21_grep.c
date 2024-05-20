#include "s21_grep.h"
int main(int argc, char *argv[]) {
  int kol_patern = 0;
  int kol_failov = 0;
  flags bukva = {0};
  flags poryadok = {0};
  parser(argc, argv, &bukva, &poryadok, &kol_patern);
  func_f(argv, &bukva, &kol_patern, poryadok);
  func_e(argv, &bukva, &kol_patern, poryadok);
  numb_file(argc, &kol_failov);
  out_put(argc, argv, bukva, kol_failov, kol_patern);
  return 0;
}

void parser(int argc, char *argv[], flags *bukva, flags *poryadok,
            int *kol_patern) {
  int CurrentFlag = 0, flag_flagov = 0, nomer = 0;
  while ((CurrentFlag = getopt_long(argc, argv, ":?eivclnhsof", NULL, 0)) !=
         -1) {
    flag_flagov++;
    nomer--;
    switch (CurrentFlag) {
      case 'e':
        bukva->e = 1;
        if (poryadok->e == 0) poryadok->e = nomer;
        if (poryadok->e < poryadok->f && poryadok->f != 0) bukva->e = 0;
        break;
      case 'i':
        bukva->i = 1;
        if (poryadok->i == 0) poryadok->i = nomer;
        if (poryadok->i < poryadok->f && poryadok->f != 0) bukva->i = 0;
        if (poryadok->i < poryadok->e && poryadok->e != 0) bukva->i = 0;
        break;
      case 'v':
        bukva->v = 1;
        if (poryadok->v == 0) poryadok->v = nomer;
        if (poryadok->v < poryadok->f && poryadok->f != 0) bukva->v = 0;
        if (poryadok->v < poryadok->e && poryadok->e != 0) bukva->v = 0;
        break;
      case 'c':
        bukva->c = 1;
        if (poryadok->c == 0) poryadok->c = nomer;
        if (poryadok->c < poryadok->f && poryadok->f != 0) bukva->c = 0;
        if (poryadok->c < poryadok->e && poryadok->e != 0) bukva->c = 0;
        break;
      case 'l':
        bukva->l = 1;
        if (poryadok->l == 0) poryadok->l = nomer;
        if (poryadok->l < poryadok->f && poryadok->f != 0) bukva->l = 0;
        if (poryadok->l < poryadok->e && poryadok->e != 0) bukva->l = 0;
        break;
      case 'n':
        bukva->n = 1;
        if (poryadok->n == 0) poryadok->n = nomer;
        if (poryadok->n < poryadok->f && poryadok->f != 0) bukva->n = 0;
        if (poryadok->n < poryadok->e && poryadok->e != 0) bukva->n = 0;
        break;
      case 'h':
        bukva->h = 1;
        if (poryadok->h == 0) poryadok->h = nomer;
        if (poryadok->h < poryadok->f && poryadok->f != 0) bukva->h = 0;
        if (poryadok->h < poryadok->e && poryadok->e != 0) bukva->h = 0;
        break;
      case 's':
        bukva->s = 1;
        if (poryadok->s == 0) poryadok->s = nomer;
        if (poryadok->s < poryadok->f && poryadok->f != 0) bukva->s = 0;
        break;
      case 'o':
        bukva->o = 1;
        if (poryadok->o == 0) poryadok->o = nomer;
        if (poryadok->o < poryadok->e && poryadok->e != 0) bukva->o = 0;
        if (poryadok->o < poryadok->f && poryadok->f != 0) bukva->o = 0;
        break;
      case 'f':
        bukva->f = 1;
        if (poryadok->f == 0) poryadok->f = nomer;
        if (poryadok->f < poryadok->e && poryadok->e != 0) bukva->f = 0;
        break;
      default:
        break;
    }
    if (!bukva->e && argv[optind][0] != '-') {
      strcat(bukva->patern[*kol_patern], argv[optind]);
      *kol_patern += 1;
      optind++;
    }
  }
  if (flag_flagov == 0) {
    strcat(bukva->patern[*kol_patern], argv[1]);
    *kol_patern += 1;
    optind++;
  }
}
void func_f(char *argv[], flags *bukva, int *kol_patern, flags poryadok) {
  char bufflag[100] = {'0'};
  char bufflag_f[100] = {'0'};

  if (bukva->f && (poryadok.f > poryadok.e || poryadok.e == 0)) {
    strcpy((bufflag_f), (strchr(argv[1], 'f') + 1));  // copy  str after -f

    strcpy((bufflag), argv[1]);

    if (*(strchr(argv[1], 'f') + 1) != 0) {
      strcpy(bufflag, bufflag_f);
      optind--;

    } else {
      strcpy(bufflag, argv[2]);
    }

    FILE *file_f = NULL;

    file_f = fopen(bufflag, "r");
    if (file_f) {
      *kol_patern = *kol_patern * 0;
      while ((fgets(bukva->patern[*kol_patern], 10000, file_f)) != NULL) {
        *kol_patern += 1;
      }
      fclose(file_f);
    }
  }
}
void func_e(char *argv[], flags *bukva, int *kol_patern, flags poryadok) {
  char bufflag_e[100] = {'0'};
  char bufflag[100] = {'0'};

  if (bukva->e && (poryadok.f < poryadok.e || poryadok.f == 0)) {
    strcpy((bufflag_e), (strchr(argv[1], 'e') + 1));  // copy  str after -e
    strcpy((bufflag), argv[1]);
    if (*(strchr(argv[1], 'e') + 1) != 0)
      strcpy(bukva->patern[*kol_patern], bufflag_e);
    else {
      strcpy(bukva->patern[*kol_patern], argv[2]);
      optind++;
    }
    *kol_patern += 1;
  }
}
void numb_file(int argc, int *kol_failov) {
  for (int i = optind; i < argc; i++) {
    *kol_failov += 1;
  }
}
void out_put(int argc, char *argv[], flags bukva, int kol_failov,
             int kol_patern) {
  regex_t finder;
  for (int ii = 0; ii < kol_patern; ii++) {
    regcomp(&finder, bukva.patern[ii], REG_EXTENDED);

    if (bukva.i) {
      regfree(&finder);
      regcomp(&finder, bukva.patern[ii], REG_ICASE);
    }

    for (int i = optind; i < argc; i++) {
      int strochka_nomer = 0;
      FILE *file = NULL;
      regmatch_t sndt;
      file = fopen(argv[i], "r");
      int match = 0;
      int k = 0;
      int kk = 0;
      int flag_file = 0;
      if (file) {
        int flag_filematch = 0;
        while ((fgets(bukva.srtochka, 10000, file)) != NULL) {
          match = regexec(&finder, bukva.srtochka, 1, &sndt, 0);
          strochka_nomer++;
          if (bukva.v) match = !match;  //-v
          if (!match) {
            if (flag_filematch == 0) {
              kk++;
              flag_filematch = 1;
            }
            flag_file = 1;
            k++;
            if (!bukva.c && (!bukva.o || bukva.v)) {
              if (kol_failov > 1 && bukva.h == 0 && !bukva.l) {
                printf("%s:", argv[i]);
              }
              if (bukva.n & !bukva.l) printf("%d:", strochka_nomer);  //-n
              if (!bukva.l) {
                printf("%s", bukva.srtochka);
              }
            }
            func_o(argv, bukva, strochka_nomer, kol_failov, ii, i);
          }
        }
        if ((bukva.v && !bukva.c && !bukva.l)) printf("\n");
        fclose(file);
      } else {
        if (!bukva.s) fprintf(stderr, "%s", "No such file or directory");
        flag_file = 0;
      }
      if (bukva.c && file) {
        if (kol_failov > 1 && bukva.h == 0) {
          printf("%s:", argv[i]);
        }
        if (!bukva.l) printf("%d\n", k);
        if (bukva.l) printf("%d\n", kk);
      }
      if (bukva.l && (strchr(argv[i], '.') != NULL) && flag_file == 1)
        printf("%s\n", argv[i]);
    }
  }
  regfree(&finder);
}
void func_o(char *argv[], flags bukva, int strochka_nomer, int kol_failov,
            int ii, int i) {
  if (bukva.o && !bukva.c && !bukva.l && !bukva.v) {
    int dlina_str = 0;
    int dlina_pstr = 0;
    int flag_pstr = 0;
    char strochka[10000] = {'0'};
    char pattern[10000] = {'0'};
    strcpy(strochka, bukva.srtochka);
    strcpy(pattern, bukva.patern[ii]);
    dlina_str = strlen(bukva.srtochka);
    dlina_pstr = strlen(bukva.patern[ii]);
    int fl_o = 0;

    for (int k = 0; k < dlina_str; k++) {
      flag_pstr = 0;

      if (strochka[k] == pattern[ii])
        for (int kk = 0; kk <= dlina_pstr; kk++) {
          if (strochka[k + kk] == '\n') fl_o = 0;
          if (strochka[k + kk] == pattern[kk]) flag_pstr += 1;
        }

      if (flag_pstr == dlina_pstr) {
        if (kol_failov > 1 && bukva.h == 0 && !bukva.l && fl_o == 0) {
          printf("%s:", argv[i]);
          if (!bukva.n) fl_o = 1;
        }
        if (bukva.n && fl_o == 0) {
          printf("%d:", strochka_nomer);
          fl_o = 1;
        }
        printf("%s\n", pattern);
      }
    }
  }
}