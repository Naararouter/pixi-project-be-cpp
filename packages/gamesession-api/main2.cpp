#include <unicode/uidna.h>
#include <unicode/ustring.h>
#include <iostream>

int main() {
    UErrorCode status = U_ZERO_ERROR;

    // Initialize the UIDNA object
    UIDNA* idna = uidna_openUTS46(0, &status);
    if(U_FAILURE(status)) {
        std::cerr << "An error occurred: " << u_errorName(status) << std::endl;
        return 1;
    }

    // Populate the UChar array
    UChar src[100];
    const char* utf8_src = "www.google.com";
    int32_t srcLength;
    u_strFromUTF8(src, 100, &srcLength, utf8_src, -1, &status);

    // Initialize the destination buffer
    UChar dest[100];
    int32_t destCapacity = 100;

    // Initialize UIDNAInfo structure
    UIDNAInfo info = UIDNA_INFO_INITIALIZER;

    // Convert IDN to ASCII
    int32_t processedLen = uidna_nameToASCII(idna, src, srcLength, dest, destCapacity, &info, &status);

    if(U_FAILURE(status)) {
        std::cerr << "An error occurred: " << u_errorName(status) << std::endl;
        uidna_close(idna);
        return 1;
    }

    std::cout << "Successfully converted IDN to ASCII" << std::endl;
    for(int i = 0; i < processedLen; ++i) {
        std::cout << (char)dest[i];
    }
    std::cout << std::endl;

    // Clean up
    uidna_close(idna);

    return 0;
}



//#include <iostream>
//#include <unicode/uversion.h>
//
//int main() {
//    UVersionInfo versionInfo;
//    u_getVersion(versionInfo);
//
//    char versionString[20];  // Manually specify the size of the array
//    u_versionToString(versionInfo, versionString);
//
//    std::cout << "ICU version: " << versionString << std::endl;
//
//    return 0;
//}

//#include <iostream>
//
//int main() {
//
//    std::cout << "ICU version: " << "1111" << std::endl;
//
//    return 0;
//}

