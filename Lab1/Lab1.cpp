#include <iostream>
#include <bitset>

using namespace std;

class Asm
{
public:

    //Мат. операции
    int Sum(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            add eax, b
            mov c, eax
        }
        return c;
    }
    int Minus(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            Sub eax, b
            mov c, eax
        }
        return c;
    }
    int Multy(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mul b
            mov c, eax
        }
        return c;
    }
    int Div(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov edx, 0
            mov ebx, b
            idiv ebx
            mov c, eax
        }
        return c;
    }

    //Сравнение
    int More(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            ja above
            mov edx, 0
            above:
            mov c, edx
        }
        return c;
    }
    int MoreEq(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jae abeq
            mov edx, 0
            abeq:
            mov c, edx
        }
        return c;
    }
    int Less(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jb below
            mov edx, 0
            below:
            mov c, edx
        }
        return c;
    }
    int LessEq(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jbe beeq
            mov edx, 0
            beeq:
            mov c, edx
        }
        return c;
    }
    int Eq(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            je equ
            mov edx, 0
            equ:
            mov c, edx
        }
        return c;
    }
    int NotEq(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jne nequ
            mov edx, 0
            nequ:
            mov c, edx
        }
        return c;
    }  

    //Логические операции
    int Not(int a)
    {
        int c = 0;
        _asm
        {
            mov eax, a;
            not eax; 
            mov c, eax;
        }
        return c;
    }
    int And(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a;
            mov ebx, b;
            and ebx, eax; 
            mov c, ebx;
        }
        return c;
    }
    int Or(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov ebx, a;
            mov eax, b;
            or ebx, eax; 
            mov c, ebx;
        }
        return c;
    }
    int Xor(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov ebx, a;
            mov eax, b;
            xor ebx, eax; 
            mov c, ebx;
        }
        return c;
    }

    //Массив
    int Index(int* a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov ebx, [eax + 4 * ebx]
            mov c, ebx
        }
        return c;
    }

    //Сдвиги
    int LogRight(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ecx, b
            shr eax, cl
            mov c, eax
        }
        return c;
    }
    int LogLeft(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            shl al, cl
            mov c, al
        }
        return c;
    }
    int CycRight(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            ror al, cl
            mov c, al
        }
        return c;
    }
    int CycLeft(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            rol al, cl
            mov c, al
        }
        return c;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Asm object;

    //Базовые мат. операции
    cout <<  "Сумма 8 + 24 = " << object.Sum(8, 24)<<endl;
    cout << "Разность 8 - 24 = " << object.Minus(8, 24) << endl;
    cout << "Произведение 8 * 24 = " << object.Multy(8, 24) << endl;
    cout << "Деление 24 / 4 = " << object.Div(24, 4) << endl << endl;

    //Операции сравнения

    cout << "100 > 50: ";
    if (object.More(100, 50)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    cout << "100 < 50: ";
    if (object.Less(100, 50)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    cout << "100 >= 100: ";
    if (object.MoreEq(100, 100)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    cout << "100 <= 100: ";
    if (object.LessEq(100, 100)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    cout << "100 = 50: ";
    if (object.Eq(100, 50)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    cout << "100 != 50: ";
    if (object.NotEq(100, 50)) cout << "Истина" << endl << endl;
    else cout << "Ложь" << endl;

    //Логические операции

    cout << "Not от 25: " << object.Not(25) << endl;
    cout << "25 and 7: " << object.And(25, 7) << endl;
    cout << "25 or 7: " << object.Or(25, 7) << endl;
    cout << "25 xor 7: " << object.Xor(25, 7) << endl << endl;

    //Индексация по массиву

    int a[] = { 2, 4, 6, 8, 10, 20, 30 };
    cout << "В массиве [2, 4, 6, 8, 10, 20, 30] 4-й элемент: " << object.Index(a, 3) << endl << endl;

    //Операции сдвига

    cout << "Логический сдвиг для числа 99, в двоичной сс : ";
    bitset<8> f(99);
    cout << f.to_string() << endl;
    cout << "Вправо на 2 позиции: "<<endl;

    int k = object.LogRight(99, 2);

    cout << "Результат: ";
    bitset<8> ff(k);
    cout << ff.to_string() << "; "<< k <<endl;

    cout << "Влево на 2 позиции: " << endl;

    k = object.LogLeft(99, 2);

    cout << "Результат: ";
    bitset<8> fff(k);
    cout << fff.to_string() << "; " << k << endl << endl;

    cout << "Циклический сдвиг " << endl;

    cout << "Вправо на 2 позиции: " << endl;

     k = object.CycRight(99, 2);

    cout << "Результат: ";
    bitset<8> r(k);
    cout << r.to_string() << "; " << k << endl;

    cout << "Влево на 2 позиции: " << endl;

    k = object.CycLeft(99, 2);

    cout << "Результат: ";
    bitset<8> rr(k);
    cout << rr.to_string() << "; " << k << endl << endl;
}
