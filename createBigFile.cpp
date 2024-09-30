#include <iostream>
#include <fstream>
#include <string>

const char alfavit[] = " 0123456789!@#$%^&*()_+-=`~[]{}:;.,/|<>qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";


int main(int argc, char *argv[])
{
    int t = 0;
    int len = 1000000;
    char tx[] = "hello.txt";
    char* path = tx;
    
    srand(time(0));
    
    if(argc>1)
        path = *(argv+1);
    if(argc>2)
        len = std::stoi(*(argv+2));
    
    
    std::ofstream out;          // поток для записи
    out.open(path);      // открываем файл для записи
    
    //Создание случайных символов в файле
    char s[len];
    for(int i = 0; i<len; i++){
        t = rand()%90;
        s[i] = alfavit[t];
    }
    //Запись файла
    if (out.is_open())
        out << s << '\0' << std::endl;
    
    out.close(); 
    return 0;
}
