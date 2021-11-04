#include <iostream>
#include <Windows.h>
#include <string>

bool GetFileMapping() {
    std::string mapName, data;
    HANDLE openMap;
    LPVOID mapFileAddress;

    std::cout << "Введите название отображения: ";
    std::getline(std::cin, mapName);

    openMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, false, mapName.c_str());
    if (!openMap) {
        std::cout << "Ошибка, отображение не найдено, код: " << GetLastError();
        return false;
    }

    mapFileAddress = MapViewOfFile(openMap, FILE_MAP_ALL_ACCESS, NULL, NULL, NULL);
    if (!mapFileAddress) {
        std::cout << "Ошибка, файл не спроецирован, код: " << GetLastError();
        return false;
    }

    data.assign((char*)mapFileAddress);
    std::cout << "Ваши данные: " << data << std::endl;
    return true;
}

int main()
{
    system("chcp 1251");
    system("cls");
    bool result = GetFileMapping();
    if (result) {
        std::cout << "Читатель и писатель завершили свою работу корректно, их можно закрыть!";
    }
}

