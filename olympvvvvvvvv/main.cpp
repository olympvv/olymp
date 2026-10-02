#include <iostream>
#include <string>

// Функция для шифрования текста
std::string caesarCipher(std::string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        // Проверяем заглавные буквы
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            if (text[i] < 'A') text[i] += 26; // Для отрицательных сдвигов
        }
        // Проверяем строчные буквы
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            if (text[i] < 'a') text[i] += 26;
        }
    }
    return text;
}

int main() {
    std::string text = "Hello, World!";
    int shift = 3;

    std::string encrypted = caesarCipher(text, shift);
    std::string decrypted = caesarCipher(encrypted, -shift);

    std::cout << "Исходный текст: " << text << std::endl;
    std::cout << "Зашифрованный: " << encrypted << std::endl;
    std::cout << "Расшифрованный: " << decrypted << std::endl;

    return 0;
}
