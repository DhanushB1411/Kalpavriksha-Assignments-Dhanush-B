#include <fcntl.h>   // For open()
#include <unistd.h>  // For read(), write(), and close()
#include<stdio.h>

int main() {
    int source = open("source.txt", O_RDONLY);  // Open the file for reading
    int dest = open("dest.txt", O_WRONLY | O_CREAT, 0644);  // Open for writing, create if needed
    
    char buffer[128];
    int bytesRead;

    // Read from source and write to destination
    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0) {
        
        write(dest, buffer, bytesRead);
    }

    close(source);  // Close the source file
    close(dest);    // Close the destination file
    
    return 0;
}
