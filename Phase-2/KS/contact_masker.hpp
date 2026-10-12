#ifndef CONTACT_MASKER_HPP
#define CONTACT_MASKER_HPP

#include <iostream>
#include <string>

// Class providing privacy proxies and number masking (CPP Unit 2)
class ContactMasker {
private:
    std::string rawPhoneNumber; // Private member for data hiding (CPP Unit 2)
    std::string studentID;
    int sessionToken;

public:
    // Constructors (CPP Unit 2)
    ContactMasker();
    ContactMasker(const std::string& phone, const std::string& id);

    // Member functions
    void updatePhone(const std::string& newPhone);
    std::string getMaskedNumber() const;
    std::string generateSessionProxyToken();
    void displaySecurityProfile() const;
};

#endif // CONTACT_MASKER_HPP