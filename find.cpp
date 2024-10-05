#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

std::string context = "that";   // Строка контекста
int ctxLen = context.length();  // Размер буфера и контекста

float txtFile(std::string pathFile) {   // Получение коэфицента схожести в *.txt
    std::ifstream in;       // поток для чтения
    in.open(pathFile);       // загружает файл в Оперативную Память
    if (in.is_open()) {      // открылся ли файл
        char* a = new char[ctxLen];   //буфер для сравнения-поиска
        
        int c = 0;  // итоговая сумма баллов схожести буфера и строки контекста
        char ch;    // слейдущий символ в тексте файла
        int i = 0;  // номер слейдущего символа
        while(in.get(ch)) {    // Цикл по символам в тексте
            a[i%ctxLen] = ch;   // Запись символа в буфер
            for(int k = 0; k < ctxLen; k++) {  // Цикл по контексту
                if(*(a+k)==context[(k+i)%ctxLen]) { // Проверка схожести символа
                    c += 1;       // + 1 балл, Если символ текста равен символу
                }                 // в строке контекста
            }
            i++; // увеличение итератора
        }
        
        if(i==0){return 0; } // Выход 0, если размер текста 0
        return (((float)c)/i);  //Итоговый результат (баллы / размер текста)
    }
    return 0; // Если не открылся файл
}

int main() {
    std::string path = "/home"; // Путь к папке
    for (const auto& entry : fs::recursive_directory_iterator(path)){ // проходит все файлы рекурсивно
        std::string extensionFile = {entry.path().extension()}; // расширение файла
        std::string extensionTxt  = {".txt"};                   // расширение .txt
        if(extensionFile.compare(extensionTxt)==0) {     // только при расширении .txt
            std::cout << txtFile(entry.path()) << entry.path() << std::endl;                 //работа с файлом.txt
        }
        
    }
    return 0;
}


