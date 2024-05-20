#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
int argumenti(int argc, char *argv[], int *argument);
void printick(int argc, char *argv[], int argument);
const char *short_options = ":?benstvAET";
static struct option const long_options[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {"show-nonprinting", no_argument, NULL, 'v'},
    {"show-ends", no_argument, NULL, 'E'},
    {"show-tabs", no_argument, NULL, 'T'},
    {"show-all", no_argument, NULL, 'A'},
    {NULL, 0, NULL, 0}};