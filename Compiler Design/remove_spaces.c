#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

	FILE* output_file = fopen("output.c", "w");
	if(output_file == NULL) {
		printf("Error opening output file.\n");
		exit(1);
	}

	int line_number = 1;
	char line[MAX_LINE_LENGTH];
	while(fgets(line, MAX_LINE_LENGTH, input_file)) {

		int comment_start = strstr(line, "//");
		if(comment_start != NULL) line[comment_start - line] = '\0';

		line = strtrim(line);

		fprintf(output_file, "%d: %s\n", line_number++, line);
	}

	fclose(input_file);
	fclose(output_file);

	return 0;
}

char* strtrim(char* str) {
	int i = 0;
	int j = strlen(str) - 1;
	while (str[i] == ' ') i++;
	while (str[j] == ' ') j--;

	str[j + 1] = '\0';
	return str + i;
}
