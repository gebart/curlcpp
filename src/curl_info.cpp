/**
 * File:   curl_info.cpp
 * Author: Giuseppe Persico
 */

#include "curl_info.h"

using curl::curl_info;

// Implementation of default constructor.
curl_info::curl_info() {
    this->version = curl_version_info(CURLVERSION_NOW);
}

// Implementation of overloaded constructor.
curl_info::curl_info(const CURLversion version) {
    this->version = curl_version_info(version);
}

// Implementation of get_protocols method.
std::list<std::string> curl_info::get_protocols() const NOEXCEPT {
    std::list<std::string> protocols;
    const char *const *const prot = this->version->protocols;
    unsigned int i = 0;
    while (*(prot+i) != NULL) {
        protocols.push_back(std::string(*(prot+i)));
        i++;
    }
    return protocols;
}
