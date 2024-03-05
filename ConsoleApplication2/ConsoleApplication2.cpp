#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale>
#include <codecvt>
#include <Windows.h>

using namespace std;

// Функция для настройки консоли
void setupConsole() {
    // Устанавливаем кодировку для ввода
    SetConsoleCP(1251);
    // Устанавливаем кодировку для вывода
    SetConsoleOutputCP(1251);
    // Устанавливаем русскую локаль
    setlocale(LC_ALL, "Russian");
}

// Шаблонная функция для обращения слова
template<typename StringType>
StringType reverseWord(const StringType& word) {
    // Создаем копию слова
    StringType reversed = word;
    // Инвертируем слово
    reverse(reversed.begin(), reversed.end());
    // Возвращаем инвертированное слово
    return reversed;
}

// Шаблонная функция для удаления гласных
template<typename StringType>
StringType removeVowels(const StringType& word) {
    // Определяем гласные для разных языков
    StringType vowels;
    if constexpr (is_same_v<StringType, wstring>) {
        vowels = L"aeiouаеёиоуыэюяAEIOUАЕЁИОУЫЭЮЯ";
    }
    else {
        vowels = "aeiou";
    }
    // Создаем результирующую строку
    StringType result;
    // Перебираем символы в слове
    for (auto c : word) {
        // Если символ не является гласной, добавляем его к результату
        if (vowels.find(c) == StringType::npos) {
            result.push_back(c);
        }
    }
    // Возвращаем слово без гласных
    return result;
}

// Шаблонная функция для удаления согласных
template<typename StringType>
StringType removeConsonants(const StringType& word) {
    // Определяем согласные для разных языков
    StringType consonants;
    if constexpr (is_same_v<StringType, wstring>) {
        consonants = L"bcdfghjklmnpqrstvwxyzбвгджзйклмнпрстфхцчшщBCDFGHJKLMNPQRSTVWXYZБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    }
    else {
        consonants = "bcdfghjklmnpqrstvwxyz";
    }
    // Создаем результирующую строку
    StringType result;
    // Перебираем символы в слове
    for (auto c : word) {
        // Если символ не является согласной, добавляем его к результату
        if (consonants.find(c) == StringType::npos) {
            result.push_back(c);
        }
    }
    // Возвращаем слово без согласных
    return result;
}

// Шаблонная функция для перемешивания букв в слове
template<typename StringType>
StringType shuffleWord(const StringType& word) {
    // Создаем копию слова
    StringType shuffled = word;
    // Инициализируем генератор случайных чисел
    random_device rd;
    mt19937 g(rd());
    // Перемешиваем буквы в слове
    shuffle(shuffled.begin(), shuffled.end(), g);
    // Возвращаем перемешанное слово
    return shuffled;
}

int main() {
    // Вызываем функцию для настройки консоли
    setupConsole();
    // Создаем переменные для хранения введенного слова, выбора пользователя и результатов операций
    wstring wword;
    string sword;
    int choice;

    // Выводим приглашение для ввода слова и считываем введенное слово
    wcout << L"Введите слово: ";
    wcin >> wword;
    // Преобразуем широкую строку в обычную строку для дальнейшей работы
    sword = wstring_convert<codecvt_utf8<wchar_t>, wchar_t>{}.to_bytes(wword);

    // Выводим меню выбора операции
    wcout << L"Меню:\n";
    wcout << L"1. Перевернуть слово\n";
    wcout << L"2. Удалить гласные\n";
    wcout << L"3. Удалить согласные\n";
    wcout << L"4. Перемешать буквы\n";
    wcout << L"Введите ваш выбор: ";
    // Считываем выбор пользователя
    wcin >> choice;

    // Выполняем соответствующую операцию в зависимости от выбора пользователя
    switch (choice) {
    case 1:
        // Выводим инвертированное слово
        wcout << L"Перевернутое слово: " << reverseWord(wword) << endl;
        break;
    case 2:
        // Выводим слово без гласных
        wcout << L"Слово без гласных: " << removeVowels(wword) << endl;
        break;
    case 3:
        // Выводим слово без согласных
        wcout << L"Слово без согласных: " << removeConsonants(wword) << endl;
        break;
    case 4:
        // Выводим перемешанное слово
        wcout << L"Перемешанное слово: " << shuffleWord(wword) << endl;
        break;
    default:
        // Выводим сообщение об ошибке при некорректном выборе
        wcout << L"Неверный выбор\n";
        break;
    }

    return 0;
}
