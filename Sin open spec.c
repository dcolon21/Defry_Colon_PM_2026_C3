#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

#define MAX_VEHICLES 100
#define MAX_FUELS 20
#define MAX_TRIPS 500
#define TEXT_LEN 64
#define LABEL_LEN 160
#define ERROR_LEN 256
#define HEAVY_MAINTENANCE_INTERVAL 100000.0

typedef struct {
    double insuranceAnnual;
    double marbeteAnnual;
    double revistaAnnual;
    double loanMonthly;
    double taxesAnnual;
    double parkingMonthly;
    double cleaningMonthly;
    double unforeseenAnnual;
    double residualValue;
    int usefulLifeYears;
} FixedCosts;

typedef struct {
    double maintenanceCost;
    double maintenanceIntervalKm;
    double tireSetPrice;
    double tireLifeKm;
    double oilChangeCost;
    double oilIntervalKm;
    double heavyMaintenanceCost;
    double repairsAnnualReserve;
    double parkingHourlyRate;
    double washCost;
} VariableCosts;

typedef struct {
    int id;
    char brand[TEXT_LEN];
    char model[TEXT_LEN];
    int year;
    int fuelId;
    double purchasePrice;
    double currentValue;
    double odometer;
    double annualKm;
    double cityEfficiency;
    double highwayEfficiency;
    FixedCosts fixed;
    VariableCosts variable;
} Vehicle;

typedef struct {
    int id;
    char name[TEXT_LEN];
    double pricePerLiter;
} Fuel;

typedef struct {
    double totalKm;
    double cityPct;
    double highwayPct;
    double parkingHours;
    int washes;
    double extraExpenses;
} TripInput;

typedef struct {
    double cityKm;
    double highwayKm;
    double liters;
    double fuelPrice;
    double fuelCost;
    double maintenanceCost;
    double tireCost;
    double oilCost;
    double heavyCost;
    double repairsCost;
    double fixedCostEconomic;
    double fixedCostCash;
    double parkingCost;
    double washCost;
    double extraCost;
    double totalEconomic;
    double totalCash;
    double costPerKmEconomic;
    double costPerKmCash;
    double annualFixedEconomic;
    double annualFixedCash;
    double depreciationAnnual;
    double variablePerKm;
} TripResult;

typedef struct {
    int id;
    int vehicleId;
    char vehicleLabel[LABEL_LEN];
    char date[32];
    TripInput input;
    TripResult result;
    int mode; /* 1 = economico, 2 = efectivo */
} TripRecord;

typedef struct {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount;
    int nextVehicleId;
    Fuel fuels[MAX_FUELS];
    int fuelCount;
    int nextFuelId;
    TripRecord trips[MAX_TRIPS];
    int tripCount;
    int nextTripId;
} AppState;

void copy_text(char *dst, size_t dstSize, const char *src);
void trim_text(char *text);
int parse_double_value(const char *text, double *value);
int parse_int_value(const char *text, int *value);
int text_is_valid(const char *text);
void vehicle_label(const Vehicle *vehicle, char *buffer, size_t bufferSize);
void format_money(char *buffer, size_t bufferSize, double value);
const char *mode_name(int mode);

#endif
