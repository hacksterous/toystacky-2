#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to determine if a character is a valid ALPHA character
int is_alpha(char c) {
    return isalpha((unsigned char)c) || (c == '_');
}

// Function to determine if a character is a valid DIGIT character
int is_digit(char c) {
    return isdigit((unsigned char)c);
}

// Function to determine if a character is a valid HEXIT character
int is_hexit(char c) {
    return is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Function to determine if a character is a valid HEXIT character
int is_octit(char c) {
    return (c >= '0' && c <= '7');
}

// Function to determine if a character is a valid BIT character
int is_bit(char c) {
    return c == '0' || c == '1';
}

// Function to determine if a character is a valid ALPHANUM character
int is_alphanum(char c) {
    return is_alpha(c) || is_digit(c) || (c == '_');
}

// Function to skip whitespace and return the new position
char* skip_whitespace(char* input) {
    while (isspace((unsigned char)*input)) {
        input++;
    }
    return input;
}

char* extract_bignum_as_string(char* input, char* output) {
    input = skip_whitespace(input);

    if (*input == '"') {
        *output++ = *input++;
        while (*input && *input != '"') {
            *output++ = *input++;
        }
        if (*input == '"') {
            *output++ = *input++;
        }
        *output = '\0';
    } else {
        *output = '\0';
    }

    return skip_whitespace(input);
}

char* extract_dec_bignum(char *input, char *output) {
    while (is_digit((unsigned char)*input)) *output++ = *input++;
    *output = '\0';
	return skip_whitespace(input);
}

char* extract_hex_bignum(char *input, char *output) {
    while (is_hexit((unsigned char)*input)) *output++ = *input++;
    *output = '\0';
	return skip_whitespace(input);
}

char* extract_oct_bignum(char *input, char *output) {
    while (is_octit((unsigned char)*input)) *output++ = *input++;
    *output = '\0';
	return skip_whitespace(input);
}

char* extract_bin_bignum(char *input, char *output) {
    while (is_bit((unsigned char)*input)) *output++ = *input++;
    *output = '\0';
	return skip_whitespace(input);
}

// Function to parse BIGNUM
char* extract_bignum(char *input, char *output) {
    input = skip_whitespace(input);
	if (input[0] == '0' && input[1] == 'd') {
		input += 2;
		return extract_dec_bignum(input, output);
	}
	else if (input[0] == '0' && input[1] == 'x') {
		input += 2;
		return extract_hex_bignum(input, output);
	}
	else if (input[0] == '0' && input[1] == 'o') {
		input += 2;
		return extract_oct_bignum(input, output);
	}
	else if (input[0] == '0' && input[1] == 'b') {
		input += 2;
		return extract_bin_bignum(input, output);
	}
	else return extract_dec_bignum(input, output);
}

// Function to extract a double-quote delimited string
char* extract_string(char* input, char* output) {
    input = skip_whitespace(input);

    if (*input == '"') {
        *output++ = *input++;
        while (*input && *input != '"') {
            *output++ = *input++;
        }
        if (*input == '"') {
            *output++ = *input++;
        } else if (*input == '\0') {
			//input stream ended before closing '"' was found
			*output++ = '"';
		}
        *output = '\0';
    } else {
        *output = '\0';
    }

    return skip_whitespace(input);
}

// Function to extract a real number (REALNUM)
char* extract_realnum(char* input, char* output) {
	//does not validate the real number
    input = skip_whitespace(input);

    if (*input == '+' || *input == '-') {
        *output++ = *input++;
    }

    int has_digits = 0;
    while (is_digit(*input)) {
        has_digits = 1;
        *output++ = *input++;
    }

    if (*input == '.') {
        *output++ = *input++;
        while (is_digit(*input)) {
            has_digits = 1;
            *output++ = *input++;
        }
    }

    if ((*input == 'e' || *input == 'E') && has_digits) {
        *output++ = *input++;
        if (*input == '+' || *input == '-') {
            *output++ = *input++;
        }
	    if (!is_digit(*input)) {
            // Invalid exponent format
            *output = '\0';
            return input;
        }
        while (is_digit(*input)) {
            *output++ = *input++;
        }
    }

	//real numbers can have RLC specification
	//resistor, inductor or capacitor impedances
	if (*input == 'l' || *input == 'r' || *input == 'c') {
		*output++ = *input++;
	}
    *output = '\0';
    return skip_whitespace(input);
}

// Function to extract a complex number (COMPLEXNUM)
char* extract_complexnum(char* input, char* output) {
    input = skip_whitespace(input);
    if (*input == '(') {
        *output++ = *input++;
		//printf("first number input = '%c'\n", *input);
        input = extract_realnum(input, output);
		//printf("first number done output = \"%s\" input = '%c'\n", output, *input);
        output += strlen(output);
		//printf("first number done after incr output = \"%s\" input = '%c'output char = %d\n", output, *input, *output);

        if (*input != ')') {
			//printf("here input = '%c'\n", *input);
            if (*input != '\0') *output++ = ' '; //don't add space at end of input
            input = extract_realnum(input, output);
            output += strlen(output);

            if (*input == ')') {
                *output++ = *input++;
            } else {
				// Error: Complex number not closed properly
                *output++ = ')';
            }
        } else {
			input++;
            *output++ = ')';
        }
        *output = '\0';
    } else {
        *output = '\0';
    }

    *output = '\0';
    return skip_whitespace(input);
}

// Function to tokenize the input string
char* tokenize(char* input, char* output) {
    input = skip_whitespace(input);

    if (*input == '\0') {
        *output = '\0';
        return input;
    }

	//printf("tokenize: entered. input = %c\n", *input);
    // Handling COMPLEXNUM
    if (*input == '(') {
        return extract_complexnum(input, output);
    }

	// Double character tokens
	if (strncmp(input, "@@", 2) == 0 || strncmp(input, "@!", 2) == 0 || strncmp(input, "<=", 2) == 0 || 
		strncmp(input, ">=", 2) == 0 ||	strncmp(input, "!=", 2) == 0 || strncmp(input, "//", 2) == 0 
		) {
		*output++ = *input++;
		*output++ = *input++;
    }
    // Handling single character tokens like brackets and parentheses
	else if (*input == '-' && !is_digit(*(input + 1))) {
		//this is standalone binary operator '-'
		//prefixed '-' in front of real number (unary '-') is handled as real number
		*output++ = *input++;
    } 
	else if (*input == '[' || *input == ']' || *input == '(' || *input == ')' || *input == '+' || *input == '*' || *input == '/') {
        *output++ = *input++;
    }
    // Handling STRING
    else if (*input == '"') {
		return extract_string(input, output);
    }
    // Handling numbers (including real numbers and bignums)
    else if (is_digit(*input) || *input == '.' || *input == '-' || *input == '+') {
        return extract_realnum(input, output);
    }
    // Handling variables (combinations of alpha and alphanumeric characters)
	//also, x@ stores into ToS into variable x
    else if (is_alpha(*input) || *input == '@' || *input == ':') {
        while (is_alphanum(*input) || *input == '@' || *input == ':') {
			char c = *input;
            *output++ = *input++;
			if (c == '@' || c == ':') break;
        }
    }
    // Handling unexpected characters (still tokenizing them)
    else {
        *output++ = *input++;
    }

    *output = '\0';
    return skip_whitespace(input);
}

