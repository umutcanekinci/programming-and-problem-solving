#include "stdio.h"

/*
 * Giriş tamponu (input buffer), kullanıcıdan gelen verilerin geçici olarak depolandığı bir bellek alanıdır.
 * İngilizcedeki terimi "input buffer" olarak bilinir.
 * Bu tampon, scanf gibi işlevlerin kullanıcıdan veri alırken kullandığı yerdir.
 * Örneğin, kullanıcı bir sayı girmek yerine harfler veya semboller yazarsa,
 * scanf bu hatalı girişi okuyamaz ve input buffer'da kalır.
 * Bu durumda, tamponu temizlemek (örneğin getchar() ile) gerekir,
 * aksi halde bir sonraki scanf işlemi bu eski veriyi okumaya çalışır.
 * @return: int
 * @arguments: void
*/

int getInt() {

    int value;
    printf(" =>");
    int result = scanf_s("%d", &value);

    if(result !=1) {
        while (getchar() != '\n');
        printf("Please enter a valid number!");
        return getInt();
    }
    return value;
}
