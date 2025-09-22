#include <string>
using namespace std;

double      charge   = 0.00;
int         numChars = 8;
string      color    = "gold";
string      woodType = "oak";

const double SIGN_BASE_CHARGE = 35.00;
const double OAK_CHARGE       = 20.00;
const double GOLD_CHARGE      = 15.00;
const double EXTRA_CHAR_FEE   = 4.00;

void detail() {
    charge = SIGN_BASE_CHARGE;
    if (numChars > 5) charge = charge + (numChars - 5) * EXTRA_CHAR_FEE;
    if (woodType == "oak") charge = charge + OAK_CHARGE;
    if (color == "gold")   charge = charge + GOLD_CHARGE;
}


void computeCharge() { detail(); }
