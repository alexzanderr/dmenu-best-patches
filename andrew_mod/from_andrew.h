
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



char * string_formatting(char * string_template, char * string) {
    /*
        works with only one string and one insertion
    */

    // charcters from both string and both NULLs
    const int allocation_size = strlen(string_template) + strlen(string) + 2;

    // memory space for string formatting
    char * mem_aloc_template = (char*) malloc(allocation_size * sizeof(char));

    // formatation
    sprintf(mem_aloc_template, string_template, string);
    return mem_aloc_template;
}

char * string_formatting_2(
    char * string_template,
    char * string1,
    char * string2
) {
    /*
        works with only two strings and two insertions
    */

    // charcters from both string and both NULLs
    const int allocation_size = strlen(string_template) + strlen(string1) + strlen(string2) + 3;

    // memory space for string formatting
    char * mem_aloc_template = (char*) malloc(allocation_size * sizeof(char));

    // formatation
    sprintf(mem_aloc_template, string_template, string1, string2);
    return mem_aloc_template;
}



int is_valid_url(char *url) {
    // need to start with http:// or https://
    return (strchr(url, '/') != NULL) && (strchr(url, '.') != NULL) && \
           ((strstr(url, "https://") != NULL) || (strstr(url, "http://") != NULL));
}


void open_in_default_browser(char *url)
{
    // if (!is_valid_url(url)) {
    //     puts("error. invalid url!");
    //     return;
    // }
    char *open_url_template = (char*)malloc((strlen(url) + 5) * sizeof(char));
    sprintf(open_url_template, "xdg-open %s", url); // string formatting in C
    system(open_url_template); // url opening using system
}


int is_math_exression(char * math_expression)
{
    if (strstr(math_expression, "http")) {
        return 0;
    }

    return (strchr(math_expression, '*') != NULL) \
        || (strchr(math_expression, '-') != NULL) \
        || (strchr(math_expression, '+') != NULL) \
        || (strchr(math_expression, '/') != NULL) \
        || (strchr(math_expression, '%') != NULL) \
        || (strchr(math_expression, '^') != NULL) \
        || (strchr(math_expression, '&') != NULL) \
        || (strstr(math_expression, "str") != NULL) \
        || (strstr(math_expression, "log") != NULL);
}

static char * python_shell_command_template = "python3 -c \"from math import log, sqrt; print(eval('%s'))\"";


char * compute_math_expression(char * math_expression)
{
    // if (!is_math_exression(math_expression)) {
    //     printf("%s\n", "invalid math expression. abort.");
    //     return;
    // }

    char *python_shell_command = (char*) malloc(100 * sizeof(char));
    sprintf(python_shell_command, python_shell_command_template, math_expression);

    FILE *command = popen(python_shell_command, "r");
    if (command) {
        char * process_result = malloc(24 * sizeof(char));
        fgets(process_result, sizeof(process_result), command);
        if (process_result != NULL) {
            // printf("\n%s == %s", math_expression, process_result);
            pclose(command);
            return process_result;
        }
    }
    return NULL;
}