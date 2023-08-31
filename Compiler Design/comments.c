#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void comments(char *input_filename, char *output_filename) {
    FILE *inputFile = fopen(input_filename, "r");
    FILE *outputFile = fopen(output_filename, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }

    char currentChar, nextChar;
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == '/') {
            nextChar = fgetc(inputFile);
            if (nextChar == '/') {
                // Ignore the rest of the line
				fprintf(outputFile, "\n");
                while ((currentChar = fgetc(inputFile)) != '\n' && currentChar != EOF);
            }
            else if (nextChar == '*') {
                // Ignore until the closing */
                while (!((currentChar = fgetc(inputFile)) == '*' && (nextChar = fgetc(inputFile)) == '/')) {
                    if (currentChar == EOF) {
                        printf("Error: Unclosed multi-line comment.\n");
                        exit(1);
                    }
                }
            }
            else {	
                fputc(currentChar, outputFile);
                fputc(nextChar, outputFile);
            }
        }
        else {
	            fputc(currentChar, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

}

int main(){
	char input1_filename[] = "input.c"; // Replace with your input file's name
    char input2_filename[] = "input1.c";
	char output_filename[] = "output.c";
	comments(input1_filename, input2_filename);
	remove_extra_lines(input2_filename, output_filename);

	return 0;
}
