#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string input;
    cout << "Пример сторки которую можно вести :  qwe1qwe17qwe177qwe1777"<< endl;
    cout << "Введите строку: ";
    getline(std::cin, input);
    const char* cstr = input.c_str();
    size_t length = std::strlen(cstr);

    bool insideGroup = false;
    size_t sevenCount = 0;
    
    int m=0;
    int valueSeven=0;

    int error=0;
    bool eer=true;
    
    for (size_t i = 0; i < length; ++i) {
        if (isdigit(cstr[i])) {
            m=i;
            while (eer){
                if (isdigit(cstr[m])){
                    if (cstr[m] == '7'){
                        valueSeven++;
                    }
                }
                else{
                    if (valueSeven>2||valueSeven==0){
                        i=m;
                        error++;
                    }
                    valueSeven=0;
                    eer=false;
                    break;
                }
                
                if (m < length)
                {
                    m++;
                }
                else
                {
                    break;
                }
                
            }
            if ( error!=0)
            {
                error=0;
                eer=true;
                continue;
            }

            // Начало новой группы цифр
            if (!insideGroup) {
                insideGroup = true;
            }
            cout << cstr[i];
        } else {
            // Конец группы цифр
            if (insideGroup) {
                insideGroup = false;
                eer=true;
                cout << endl;
            }
        }
    }

    return 0;
}
