#include <iostream>
#include <string.h>

#include <chrono>
using namespace std::chrono;

void print_buf(const char *input)
{
    static char buffer[200];
    if ((strlen(buffer) + strlen(input) < 200) && input[0] != '\0')
    {
        strcat(buffer, input);
    }
    else
    {
        printf("%s", buffer);
        buffer[0] = '\0';
        strcpy(buffer, input);
    }
}

int main(int argc, char **argv)
{

    auto start = high_resolution_clock::now();
    for (int i = 0; i < 200; i++)
    {
        printf("%s","Hello, World!\n");
        printf("%s","Hello, Piter!\n");
    }
    auto stop = high_resolution_clock::now();
    auto duration_printf = duration_cast<microseconds>(stop - start);
    

    start = high_resolution_clock::now();
    for (int i = 0; i < 200; i++)
    {
        print_buf("Hello, World!\n");
        print_buf("Hello, Piter!\n");
    }
    stop = high_resolution_clock::now();
    auto duration_printf_buffered = duration_cast<microseconds>(stop - start);



    start = high_resolution_clock::now();
    for (int i = 0; i < 200; i++)
    {
        std::cout << "Hello, World!\n"
             << "Hello, Piter!\n";
    }
    stop = high_resolution_clock::now();
    auto duration_cout = duration_cast<microseconds>(stop - start);
    
    
    
    std::cout << "printf " << duration_printf.count() << std::endl;
    std::cout << "printf buffered " << duration_printf_buffered.count() << std::endl;
    std::cout << "cout " << duration_cout.count() << std::endl;
    

    return 0;
}