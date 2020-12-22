#include "monty.h"

/**
 * sanitize_input - tokenizes a line down to 2 strings, opcode and any argument
 *
 * @line: line from input/read_line
 * Return: returns a double pointer containing the input tokens,
 * or NULL on failure
 */
char **sanitize_input(char *line)
{
	char **input;
	char *saveptr;
	char *tok;

	input = check_malloc(sizeof(char *) * 2);
	tok = strtok_r(line, " ", &saveptr);
	input[0] = tok;
	tok = strtok_r(NULL, " ", &saveptr);
	input[1] = tok;

	return (input);
}

/**
 * read_line - tokenizes a line from the buffer
 * strtok_r requires a NULL argument to be passed on every tokenization
 * but the first.
 *
 * @buffer: buffer created by input/get_buffer
 * Return: Returns the tokenized line
 */
char *read_line(char *buffer)
{
	static int flag = 1; /* static flag because betty
			      * won't let me set linesave to NULL?
			      */
	static char *linesave;
	char *line;

	if (flag == 1)
	{
		linesave = NULL;
		line = strtok_r(buffer, "\n", &linesave);
		flag = 0;
	}
	else
		line = strtok_r(NULL, "\n", &linesave);
	return (line);
}

/**
 * get_buffer - reads a buffer in from a previously opened file descriptor
 * is opened and error handling done by errcheck/check_file function
 *
 * @filename: file name, provided by argv[1]
 * @fd: open file descriptor
 * Return: returns buffer created from text file, or exits on failure
 */
char *get_buffer(char *filename, int fd)
{
	char *buffer;
	struct stat st;
	unsigned int size, readval;

	stat(filename, &st);
	size = st.st_size;
	buffer = check_malloc((size * sizeof(char)) + 1);
	readval = read(fd, buffer, size);
	if (readval <= 0)
	{
		printf("Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	buffer[size] = '\0';
	return (buffer);
}
