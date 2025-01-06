#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Aksam {
    int ariza;
    int tamir_maliyeti;
};

struct Araba {
    char model[50];
    int uretim_yili;
    int km;
    int fiyat;
    struct Aksam sanziman;
    struct Aksam motor;
    struct Aksam disliler;
    struct Aksam balata;
    struct Aksam suspansiyon;
    struct Aksam gosterge_paneli;
    struct Aksam egzoz;
    struct Aksam sag_on_camurluk;
    struct Aksam sol_on_camurluk;
};

struct Araba ekspertiz(struct Araba araba) {
    araba.sanziman.ariza = rand() % 2;
    araba.motor.ariza = rand() % 2;
    araba.disliler.ariza = rand() % 2;
    araba.balata.ariza = rand() % 2;
    araba.suspansiyon.ariza = rand() % 2;
    araba.gosterge_paneli.ariza = rand() % 2;
    araba.egzoz.ariza = rand() % 2;
    araba.sag_on_camurluk.ariza = rand() % 2;
    araba.sol_on_camurluk.ariza = rand() % 2;
    return araba;
}

int toplamFiyatVeTamirMaliyeti(struct Araba araba, int *tamirMaliyeti) {
    *tamirMaliyeti = 0;
    if (araba.sanziman.ariza) *tamirMaliyeti += araba.sanziman.tamir_maliyeti;
    if (araba.motor.ariza) *tamirMaliyeti += araba.motor.tamir_maliyeti;
    if (araba.disliler.ariza) *tamirMaliyeti += araba.disliler.tamir_maliyeti;
    if (araba.balata.ariza) *tamirMaliyeti += araba.balata.tamir_maliyeti;
    if (araba.suspansiyon.ariza) *tamirMaliyeti += araba.suspansiyon.tamir_maliyeti;
    if (araba.gosterge_paneli.ariza) *tamirMaliyeti += araba.gosterge_paneli.tamir_maliyeti;
    if (araba.egzoz.ariza) *tamirMaliyeti += araba.egzoz.tamir_maliyeti;
    if (araba.sag_on_camurluk.ariza) *tamirMaliyeti += araba.sag_on_camurluk.tamir_maliyeti;
    if (araba.sol_on_camurluk.ariza) *tamirMaliyeti += araba.sol_on_camurluk.tamir_maliyeti;
    return araba.fiyat + *tamirMaliyeti;
}

void arabaBilgileri(struct Araba araba) {
    printf("Model: %s\n", araba.model);
    printf("Uretim Yili: %d\n", araba.uretim_yili);
    printf("Kilometre: %d\n", araba.km);
    printf("Fiyat: %d\n", araba.fiyat);
    printf("\n");
    printf("Sanziman: %s\n", araba.sanziman.ariza ? "Arizali" : "Saglam");
    printf("Motor: %s\n", araba.motor.ariza ? "Arizali" : "Saglam");
    printf("Disli: %s\n", araba.disliler.ariza ? "Arizali" : "Saglam");
    printf("Balata: %s\n", araba.balata.ariza ? "Arizali" : "Saglam");
    printf("Suspansiyon: %s\n", araba.suspansiyon.ariza ? "Arizali" : "Saglam");
    printf("Gosterge Paneli: %s\n", araba.gosterge_paneli.ariza ? "Arizali" : "Saglam");
    printf("Egzoz: %s\n", araba.egzoz.ariza ? "Arizali" : "Saglam");
    printf("Sag On Camurluk: %s\n", araba.sag_on_camurluk.ariza ? "Arizali" : "Saglam");
    printf("Sol On Camurluk: %s\n", araba.sol_on_camurluk.ariza ? "Arizali" : "Saglam");
    printf("\n");
}

void pazarlikEtme(int *fiyat) {
    int cevap;
    int pazarlikSayisi = 0;
    int pazarlikMiktari = *fiyat * 0.03;

    while (pazarlikSayisi < 4) { // toplamda pazarlik sayisi 4 ile sinirli
        printf("Pazarlik etmek ister misiniz? (1=evet / 1 disindaki sayilar = hayir): ");
        scanf("%d", &cevap);
        if (cevap == 1) {
            if (pazarlikSayisi < 2) {
                *fiyat -= pazarlikMiktari;
            } else {
                *fiyat += pazarlikMiktari;
            }
            printf("Yeni fiyat: %d\n", *fiyat);
            pazarlikSayisi++;
        } else {
            break;
        }
    }
}

void arabaOnGosterim(struct Araba arabalar[], int boyut) {
    printf("Mevcut arabalar:\n");
    for (int i = 0; i < boyut; i++) {
        printf("%d. %s (Model: %d, Km: %d, Fiyat: %d)\n", i + 1, arabalar[i].model, arabalar[i].uretim_yili, arabalar[i].km, arabalar[i].fiyat);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    struct Araba galeridekiArabalar[4] = {
        {"Fiat Egea", 2020, 50000, 850000, {0, 50000}, {0, 100000}, {0, 13000}, {0, 7000}, {0, 4000}, {0, 3000}, {0, 2000}, {0, 15000}, {0, 15000}},
        {"Toyota Corolla", 2018, 75000, 700000, {0, 60000}, {0, 120000}, {0, 14000}, {0, 8500}, {0, 5000}, {0, 3500}, {0, 2500}, {0, 15000}, {0, 15000}},
        {"Honda Civic", 2016, 125000, 650000, {0, 70000}, {0, 140000}, {0, 15000}, {0, 9500}, {0, 6000}, {0, 4000}, {0, 3000}, {0, 15000}, {0, 15000}},
        {"Audi A4", 2021, 75000, 1250000, {0, 80000}, {0, 160000}, {0, 10000}, {0, 15500}, {0, 7000}, {0, 4500}, {0, 3500}, {0, 15000}, {0, 15000}}
    };
    
    arabaOnGosterim(galeridekiArabalar, 4);
    int secim;
    printf("Hangi arabayi seciyorsunuz? (1-4): ");
    scanf("%d", &secim);
    printf("\n");

    if (secim < 1 || secim > 4) {
        printf("Gecersiz secim!\n");
        return 1;
    }

    struct Araba secilenAraba = galeridekiArabalar[secim - 1];
    secilenAraba = ekspertiz(secilenAraba);

    arabaBilgileri(secilenAraba);

    int tamirMaliyeti;
    int toplamFiyatAraba = toplamFiyatVeTamirMaliyeti(secilenAraba, &tamirMaliyeti);

    printf("Ariza Tamir Maliyeti: %d\n", tamirMaliyeti);
    printf("Araba Fiyati: %d\n", secilenAraba.fiyat);
    printf("Toplam Fiyat: %d\n", toplamFiyatAraba);
    
    pazarlikEtme(&toplamFiyatAraba);
    printf("Son Fiyat: %d\n", toplamFiyatAraba);
    
    return 0;
}
