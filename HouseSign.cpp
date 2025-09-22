#include <iostream>
#include <string>

// ----- Named constants -----
const double SIGN_BASE_CHARGE = 35.00;
const double OAK_CHARGE       = 20.00;
const double GOLD_CHARGE      = 15.00;
const double EXTRA_CHAR_FEE   = 4.00;

// ----- Inputs / required variables -----
int         numChars = 8;         // per spec
std::string color    = "gold";    // "black", "white", or "gold"
std::string woodType = "oak";     // "oak" or "pine"
double      charge   = 0.00;      // per spec

// ----- Computed -----
int extraChars = 0;

// Housekeeping: get inputs
void housekeeping() {
    std::cout << "How many letters/numbers? (first 5 included): ";
    std::cin  >> numChars;

    std::cout << "Enter wood type (oak or pine): ";
    std::cin  >> woodType;

    std::cout << "Enter letter color (black, white, or gold): ";
    std::cin  >> color;
}

// Detail: compute total charge
void computeCharge() {
    charge = SIGN_BASE_CHARGE;

    if (numChars > 5) {
        extraChars = numChars - 5;
        charge += extraChars * EXTRA_CHAR_FEE;
    } else {
        extraChars = 0;
    }

    if (woodType == "oak" || woodType == "Oak" || woodType == "OAK") {
        charge += OAK_CHARGE;
    }

    if (color == "gold" || color == "Gold" || color == "GOLD") {
        charge += GOLD_CHARGE;
    }
}

// End-of-Job: show breakdown
void endOfJob() {
    std::cout << "Extra characters: " << extraChars
              << " x " << EXTRA_CHAR_FEE
              << " = " << (extraChars * EXTRA_CHAR_FEE) << "\n";
    std::cout << "Base charge: " << SIGN_BASE_CHARGE << "\n";
    std::cout << "----------------------------\n";
    std::cout << "Total charge: " << charge << "\n";
}

int main() {
    housekeeping();
    computeCharge();   // <-- was 'detail()' (nonexistent)
    endOfJob();
    return 0;
}
