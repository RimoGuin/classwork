#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to remove comments and unnecessary whitespaces from the C program
void remove_comments_and_whitespaces(FILE* input_file, FILE* output_file) {
    int c;
    bool in_single_line_comment = false;
    bool in_multi_line_comment = false;
    bool in_string = false;
    bool is_prev_space = false;
    int current_line = 1;

    while ((c = fgetc(input_file)) != EOF) {
        if (in_single_line_comment) {
            if (c == '\n') {
                in_single_line_comment = false;
                fputc(c, output_file);
                current_line++;
            }
        } else if (in_multi_line_comment) {
            if (c == '*') {
                if ((c = fgetc(input_file)) == '/') {
                    in_multi_line_comment = false;
                }
            }
        } else if (in_string) {
            fputc(c, output_file);
            if (c == '\"') {
                in_string = false;
            }
        } else {
            if (c == '\"') {
                in_string = true;
                fputc(c, output_file);
            } else if (c == '/') {
                if ((c = fgetc(input_file)) == '/') {
                    in_single_line_comment = true;
                } else if (c == '*') {
                    in_multi_line_comment = true;
                } else {
                    fputc('/', output_file);
                    fputc(c, output_file);
                }
            } else if (isspace(c)) {
                if (c == '\n') {
                    is_prev_space = false;
                    fputc(c, output_file);
                    current_line++;
                } else if (!is_prev_space) {
                    is_prev_space = true;
                    fputc(c, output_file);
                }
            } else {
                is_prev_space = false;
                fputc(c, output_file);
            }
        }
    }
}

int main() {
    char input_filename[100];
    char output_filename[100];

    printf("Enter the input C file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    FILE* input_file = fopen(input_filename, "r");
    FILE* output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    remove_comments_and_whitespaces(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Comments and unnecessary whitespaces removed successfully.\n");

    return 0;
}

