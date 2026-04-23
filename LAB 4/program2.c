#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int n, fd;
    char buf[50];

    // Read up to 10 bytes from standard input (keyboard)
    n = read(0, buf, 10);

    // Open (or create) the file with write permissions
    fd = open("target.txt", O_RDONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Write the data to the file
    write(fd, buf, n);

    // Print number of bytes written
    printf("%d\n", n);

    // Close the file
    close(fd);

    return 0;
}