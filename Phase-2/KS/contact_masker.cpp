#include "contact_masker.hpp"
#include <cstdlib>

ContactMasker::ContactMasker() : rawPhoneNumber("0000000000"), studentID("NONE"), sessionToken(1000) {}

ContactMasker::ContactMasker(const std::string& phone, const std::string& id)
    : rawPhoneNumber(phone), studentID(id), sessionToken(1001 + (rand() % 8999)) {}

void ContactMasker::updatePhone(const std::string& newPhone) {
    if (newPhone.length() >= 10) {
        rawPhoneNumber = newPhone;
    }
}

// Generates masked proxy string +91-XXXXX-1849 without exposing raw member
std::string ContactMasker::getMaskedNumber() const {
    if (rawPhoneNumber.length() < 10) {
        return "+91-XXXXX-0000";
    }
    // Extract last 4 digits using substring manipulation
    std::string lastFour = rawPhoneNumber.substr(rawPhoneNumber.length() - 4, 4);
    return "+91-XXXXX-" + lastFour;
}

// Generates one-time coordination token for driver
std::string ContactMasker::generateSessionProxyToken() {
    sessionToken = 1000 + (rand() % 9000);
    return "TKN-" + studentID + "-" + std::to_string(sessionToken);
}

void ContactMasker::displaySecurityProfile() const {
    std::cout << "[Privacy Shield] Student ID: " << studentID 
              << " | Masked Contact: " << getMaskedNumber()
              << " | Session Token: TKN-" << sessionToken
              << std::endl;
}