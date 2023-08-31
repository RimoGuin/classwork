#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void remove_extra_lines(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch, prev_char;
    bool in_quotes = false;
    bool prev_newline = false;
    
    while ((ch = fgetc(input_file)) != EOF) {
        if (ch == '"') {
            in_quotes = !in_quotes;
        }

        if (!in_quotes) {
            if (ch == '\n') {
                if (!prev_newline) {
                    prev_newline = true;
                    fputc(ch, output_file);
                }
            } else if (ch == ' ') {
                if (prev_newline) {
                    prev_char = ch;
                    ch = fgetc(input_file);
                    while (ch == ' ') {
                        ch = fgetc(input_file);
                    }
                    if (ch != '\n') {
                        fputc(prev_char, output_file);
                    }
                }
                if (ch != EOF) {
                    fputc(ch, output_file);
                }
                prev_newline = false;
            } else {
                fputc(ch, output_file);
                prev_newline = false;
            }
        } else {
            fputc(ch, output_file);
            prev_newline = false;
        }
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_filename[] = "inputw.c"; // Replace with your input file's name
    char output_filename[] = "outputw.c"; // Replace with your desired output file's name
    
    remove_extra_lines(input_filename, output_filename);
    printf("Extra lines removed successfully.\n");
    
    return 0;
}

