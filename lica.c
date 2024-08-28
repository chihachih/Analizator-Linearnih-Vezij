/*
[SI] LiCA - Analizator linearnih vezij

LiCA je v programskem jeziku C narejen kalkulator, ki je zmožen računanja osnovnih veličin v linearnih elektronskih vezjih. Sposoben je izračunov večine veličin v zaporednih in vzporednih vezjih (upornost, napetost, tok, itd.)

KAKO UPORABLJATI:

    odprite v terminalu (v mojem primeru Visual Studio Code vgrajen terminal (Ctrl + Shift + ¸)
    s pomočjo GCC-ja prevedemo kodo
    po uspešnem prevajanju, kodo zaženemo v terminalu in se nam pojavijo možnosti računov (1. Series resistance (Zaporedna upornost), 2. Parallel resistance (Vzporedna upornost), in tako dalje)
    v terminal napišemo številko pred želenim računom
    po izbiri, vpišteve želene vrednosti, ki jih program zahteva glede na vezje (pazite, da za decimalno vejico uporabite piko (.)!)
    s pritiskom na tipko ENTER ste končali!

V primeru, da kalkulator ne prevede programa, preverite ali imate drugo verzijo programa.

(nadgradnja je v delu)

In case of crash: Ctrl + C.
*/
    
    

#include <stdio.h>

void calculate_series_resistance();
void calculate_parallel_resistance();
void calculate_ohms_law();
void calculate_power();
void calculate_series_capacitance();
void calculate_parallel_capacitance();
void calculate_series_inductance();
void calculate_parallel_inductance();

int main() {
    int choice;

    while (1) {
        printf("Linear Circuit Calculator (Kalkulator linearnih vezij)\n");
        printf("1. Series Resistance (Zaporedna vezava)\n");
        printf("2. Parallel Resistance (Vzporedna vezava)\n");
        printf("3. Ohm's Law (Ohmov zakon)\n");
        printf("4. Power (Moc)\n");
        printf("5. Series Capacitance (Zaporedna kapacitivnost)\n");
        printf("6. Parallel Capacitance (Vzporedna kapacitivnost)\n");
        printf("7. Series Inductance (Zaporedna induktivnost)\n");
        printf("8. Parallel Inductance (Vzporedna induktivnost)\n");
        printf("9. Exit (Izhod)\n");
        printf("Enter your choice (Vpisi svojo izbiro): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_series_resistance();
                break;
            case 2:
                calculate_parallel_resistance();
                break;
            case 3:
                calculate_ohms_law();
                break;
            case 4:
                calculate_power();
                break;
            case 5:
                calculate_series_capacitance();
                break;
            case 6:
                calculate_parallel_capacitance();
                break;
            case 7:
                calculate_series_inductance();
                break;
            case 8:
                calculate_parallel_inductance();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again. (Nepravilna izbira, prosim poskusite še enkrat.\n");
        }
    }

    return 0;
}

void calculate_series_resistance() {
    int n;
    printf("Enter the number of resistors (Vpisite stevilo uporov): ");
    scanf("%d", &n);

    double total_resistance = 0.0, resistance;

    for (int i = 0; i < n; i++) {
        printf("Enter resistance (Vpisi upornost) %d (in ohms(v ohmih)): ", i + 1);
        scanf("%lf", &resistance);
        total_resistance += resistance;
    }

    printf("Total series resistance (Celotna upornost zaporedne vezave): %.2f ohms (ohmov)\n", total_resistance);
}

void calculate_parallel_resistance() {
    int n;
    printf("Enter the number of resistors (Vpisite stevilo uporov): ");
    scanf("%d", &n);

    double total_resistance = 0.0, resistance;

    for (int i = 0; i < n; i++) {
        printf("Enter resistance (Vpisi upornost) %d (in ohms(v ohmih)): ", i + 1);
        scanf("%lf", &resistance);
        total_resistance += 1.0 / resistance;
    }

    total_resistance = 1.0 / total_resistance;
    printf("Total parallel resistance (Celotna upornost vzporedne vezave): %.2f ohms (ohmov)\n", total_resistance);
}

void calculate_ohms_law() {
    double voltage, current, resistance;
    int choice;

    printf("Ohm's Law Calculator (Kalkulator Ohmovega zakona)\n");
    printf("1. Calculate Voltage (Izracunaj napetost) (V = IR)\n");
    printf("2. Calculate Current (Izracunaj napetost) (I = V/R)\n");
    printf("3. Calculate Resistance (Izracunaj napetost) (R = V/I)\n");
    printf("Enter your choice (Vpisi svojo izbiro): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter current (Vpisi tok) (in amps (v amperih)): ");
            scanf("%lf", &current);
            printf("Enter resistance (Vpisi upornost) (in ohms (v ohmih)): ");
            scanf("%lf", &resistance);
            voltage = current * resistance;
            printf("Voltage (Napetost): %.2f V\n", voltage);
            break;
        case 2:
            printf("Enter voltage (Vpisi napetost) (in volts (v voltih)): ");
            scanf("%lf", &voltage);
            printf("Enter resistance (Vpisi upornost)(in ohms (v ohmih)): ");
            scanf("%lf", &resistance);
            current = voltage / resistance;
            printf("Current (Tok): %.2f A\n", current);
            break;
        case 3:
            printf("Enter voltage (Vpisi napetost) (in volts (v voltih)): ");
            scanf("%lf", &voltage);
            printf("Enter current (Vpisi tok) (in amps (v amperih)): ");
            scanf("%lf", &current);
            resistance = voltage / current;
            printf("Resistance (Upornost): %.2f ohms(ohmi)\n", resistance);
            break;
        default:
            printf("Invalid choice. Please try again. (Nepravlina izbira, poskusite še enkrat.)\n");
    }
}

void calculate_power() {
    double voltage, current, power;
    printf("Enter voltage (Vpisite napetost) (in volts (v voltih)): ");
    scanf("%lf", &voltage);
    printf("Enter current (Vpisite tok) (in amps (v amperih)): ");
    scanf("%lf", &current);
    power = voltage * current;
    printf("Power (Moc): %.2f W\n", power);
}

void calculate_series_capacitance() {
    int n;
    printf("Enter the number of capacitors (Vpisite stevilo kondenzatorjev): ");
    scanf("%d", &n);

    double total_capacitance = 0.0, capacitance;

    for (int i = 0; i < n; i++) {
        printf("Enter capacitance (Vpisite kapacitivnost) %d (in farads (v faradih)): ", i + 1);
        scanf("%lf", &capacitance);
        total_capacitance += 1.0 / capacitance;
    }

    total_capacitance = 1.0 / total_capacitance;
    printf("Total series capacitance (Celotna kapacitivnost zaporedne vezave): %.2f F\n", total_capacitance);
}

void calculate_parallel_capacitance() {
    int n;
    printf("Enter the number of capacitors (Vpisite stevilo kondenzatorjev): ");
    scanf("%d", &n);

    double total_capacitance = 0.0, capacitance;

    for (int i = 0; i < n; i++) {
        printf("Enter capacitance (Vpisite kapacitivnost) %d (in farads (v faradih)): ", i + 1);
        scanf("%lf", &capacitance);
        total_capacitance += capacitance;
    }

    printf("Total parallel capacitance (Celotna vzporedna kapacitivnost vezave): %.2f F\n", total_capacitance);
}

void calculate_series_inductance() {
    int n;
    printf("Enter the number of inductors (Vpisite stevilo tuljav): ");
    scanf("%d", &n);

    double total_inductance = 0.0, inductance;

    for (int i = 0; i < n; i++) {
        printf("Enter inductance (Vpisite induktivnost) %d (in henrys (v henryjih)): ", i + 1);
        scanf("%lf", &inductance);
        total_inductance += inductance;
    }

    printf("Total series inductance (Celotna induktivnost zaporedne vezave): %.2f H\n", total_inductance);
}

void calculate_parallel_inductance() {
    int n;
    printf("Enter the number of inductors (Vpisi stevilo tuljav): ");
    scanf("%d", &n);

    double total_inductance = 0.0, inductance;

    for (int i = 0; i < n; i++) {
        printf("Enter inductance (Vpisite induktivnost) %d (in henrys (v henryjih)): ", i + 1);
        scanf("%lf", &inductance);
        total_inductance += 1.0 / inductance;
    }

    total_inductance = 1.0 / total_inductance;
    printf("Total parallel inductance (Celotna induktivnost vzporedne vezave): %.2f H\n", total_inductance);
}
