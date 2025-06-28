#include <stdio.h>

typedef struct {
    char licPlateNum[9];
    char *brand;
    int brand_size;
    unsigned int year;
    unsigned int mileage;
    char *VIN;
    int VIN_size;
    struct car *cars;
} car;

void add();

void remove();

void display();

void displayBrandRegion();

void displayYearRange();

void change();

void saveNewFile();

void fileExport();

void changeSettings();

int main()
{
    FILE *dataFile = fopen("data.bin", "wb");
}