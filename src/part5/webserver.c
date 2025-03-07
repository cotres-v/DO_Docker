#include <fcgiapp.h>
#include <stdio.h>

int main() {
    FCGX_Init();
    int sck = FCGX_OpenSocket("127.0.0.1:8080", 100);

    FCGX_Request reqst;
    if (FCGX_InitRequest(&reqst, sck, 0) == 0) {
        while (FCGX_Accept_r(&reqst) >= 0)
        {
            FCGX_FPrintF(reqst.out, "Content-Type: text/html\n\n");
            FCGX_FPrintF(reqst.out, "Hello World!");
            FCGX_Finish_r(&reqst);
        }    
    }   else {
        printf("ERROR");
    }
    return 0;
}