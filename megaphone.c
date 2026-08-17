#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main() {
    int ch;

    // STDIN_FILENO is usually 0. isatty() returns 1 if it's a real terminal screen.
    if (isatty(STDIN_FILENO)) {
        // Human interactive mode
        fprintf(stdout, "🎤 Megaphone active! Type something and press Enter.\n");
        fprintf(stdout, "   (Press Ctrl+D when you are done)\n> ");
    } else {
        // Piped data mode! Let's print a status to stderr so it doesn't mix with the real output
        fprintf(stderr, "[Megaphone: Detected piped input. Processing data...]\n");
    }

    // Read from stdin character-by-character until EOF (End Of File)
    while ((ch = getchar()) != EOF) {
        
        // Convert the character to uppercase and print it to stdout
        putchar(toupper(ch));
        
        // If we are in interactive mode, reprint the prompt after every Enter key
        if (ch == '\n' && isatty(STDIN_FILENO)) {
            fprintf(stdout, "> ");
        }
    }

    if (!isatty(STDIN_FILENO)) {
        fprintf(stderr, "[Megaphone: Finished eating piped data!]\n");
    } else {
        fprintf(stdout, "\n🎤 Megaphone powering down.\n");
    }

    return 0;
}