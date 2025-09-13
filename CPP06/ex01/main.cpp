#include <iostream>

#include "Serializer.hpp"

int main()
{
    // 1. Bir Data nesnesi oluştur ve içini doldur
    Data myData(42, "Selamun Aleykum Dunya");

    // 2. Orijinal pointer'ı al ve bilgilerini yazdır
    Data* originalPtr = &myData;
    std::cout << "--- Orijinal Veri ---" << std::endl;
    std::cout << "Adres: " << originalPtr << std::endl;
    std::cout << "Number: " << originalPtr->getNumber() << std::endl;
    std::cout << "Text: " << originalPtr->getText() << std::endl;
    std::cout << std::endl;

    // 3. Pointer'ı serialize et (tamsayıya çevir)
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "--- Serialization ---" << std::endl;
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;
    std::cout << "(Bu, bellek adresinin tamsayı halidir)" << std::endl;
    std::cout << std::endl;

    // 4. Tamsayıyı deserialize et (pointer'a geri çevir)
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "--- Deserialization ---" << std::endl;
    std::cout << "Deserialized (pointer): " << deserializedPtr << std::endl;
    std::cout << std::endl;

    // 5. Yeni pointer'ın doğruluğunu kontrol et ve veriye eriş
    std::cout << "--- Doğrulama ---" << std::endl;
    if (originalPtr == deserializedPtr)
    {
        std::cout << "Pointer'lar eşleşti! Doğrulama başarılı." << std::endl;
        std::cout << "Yeni pointer üzerinden veriye erişim:" << std::endl;
        std::cout << "Number: " << deserializedPtr->getNumber() << std::endl;
        std::cout << "Text: " << deserializedPtr->getText() << std::endl;
    }
    else
    {
        std::cout << "HATA: Pointer'lar eşleşmedi!" << std::endl;
    }


}