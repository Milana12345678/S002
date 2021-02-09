// S002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    char s[256];
    char t[256];
    char m1[] = "First string\n";
    char m2[] = "Second string\n";
    char f[] = "%s";
    char fgs[] = "1\n";
    char fls[] = "-1\n";
    char fes[] = "0\n";
    _asm {
        // Печать First string
        lea ebx, m1
        push ebx
        lea ecx, f
        push ecx 
        call printf
        add esp, 8
        // Чтение First string
        lea ebx, s
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        // Печать Second string
        lea ebx, m2
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8
        // Чтение Second string
        lea ebx, t
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        // Подготовка цикла прохода первой строки
        lea ebx,s
        dec ebx 
        lea ecx,t
        dec ecx 
       
        b1: 
            inc ebx 
            inc ecx
            mov al,[ebx]
            mov dl,[ecx]
          
            cmp al, 0
            je b2 // Обнаружение конца первой строки

            cmp dl,0
            je f3 // Обнаружили конец второй строки - первая больше 
            cmp al,dl 
            je b1 // Символы в перой и второй строке равны - продолжаем цикл

            jb f4 // Символ в первой строке меньше символа во второй
            jmp f3 // Символ во второй больше (в первой меньше)
        
        b2: // Конец в первой строке
            cmp dl,0
            je f5 // Конец второй строки - строки равны
            jmp f4 // Вторая строка больше
  
    f3:  // Первая строка больше
            lea ebx, fgs 
                push ebx
                lea ecx, f 
                push ecx
                call printf
                add esp, 8
                jmp end
    f4: // Вторая строка больше
            lea ebx, fls
                push ebx
                lea ecx, f 
                push ecx
                call printf
               add esp, 8
                jmp end
    f5 : // Строки равны
            lea ebx, fes
                push ebx
                lea ecx, f
                push ecx
                call printf
                add esp, 8
                
            end:
    }
}

