// S002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    char s[256];
    char t[256];
    char m1[] = "Enter first string\n";
    char m2[] = "Enter second string\n";
    char f[] = "%s";
    char firstmore[] = "1\n";
    char firstless[] = "-1\n";
    char equal[] = "0\n";
    _asm {
        // Печать первой строки
        lea ebx, m1
        push ebx
        lea ecx, f
        push ecx 
        call printf
        add esp, 8
        // Чтение первой строки
        lea ebx, s
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        // Печать второй строки
        lea ebx, m2
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8
        // Чтение второй строки
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
            je f3 // Найден конец второй строки - первая строка оказалась больше 
            cmp al,dl 
            je b1 // Символы в перой и второй строке равны - продолжаем цикл

            jb f4 // Символ в первой строке меньше символа во второй
            jmp f3 // Символ во второй больше (в первой меньше)
        
        b2: // Конец в первой строке
            cmp dl,0
            je f5 // Конец второй строки - строки равны
            jmp f4 // Вторая строка больше
  
    f3:  // Первая строка больше
            lea ebx, firstmore 
                push ebx
                lea ecx, f 
                push ecx
                call printf
                add esp, 8
                jmp end
    f4: // Вторая строка больше
            lea ebx, firstless
                push ebx
                lea ecx, f 
                push ecx
                call printf
               add esp, 8
                jmp end
    f5 : // Строки равны
            lea ebx, equal
                push ebx
                lea ecx, f
                push ecx
                call printf
                add esp, 8
                
            end:
    }
}

