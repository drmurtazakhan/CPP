/* Program name: yarn.cpp
   Author: Murtaza Ali Khan
   Date last updated: 3/13/2026
   Purpose: Implements the YarnSkein class logic, including parsing of 
            CSV fiber strings and validation of numeric inputs.
*/

#include "yarn.h"

// Initialization of static maps
const std::map<YarnSkein::weightType, std::string> YarnSkein::weightToStr = {
    {LACE, "Lace"}, {SUPERFINE, "Super Fine"}, {FINE, "Fine"}, {LIGHT, "Light"}, 
    {MEDIUM, "Medium"}, {BULKY, "Bulky"}, {SUPERBULKY, "Super Bulky"}, {JUMBO, "Jumbo"}
};

const std::map<std::string, YarnSkein::weightType> YarnSkein::strToWeight = {
    {"LACE", LACE}, {"SUPER FINE", SUPERFINE}, {"FINE", FINE}, {"MEDIUM", MEDIUM}, 
    {"LIGHT", LIGHT}, {"BULKY", BULKY}, {"SUPER BULKY", SUPERBULKY}, {"JUMBO", JUMBO}
};

const std::map<YarnSkein::fiberType, std::string> YarnSkein::fiberToStr = {
    {WOOL, "Wool"}, {ACRYLIC, "Acrylic"}, {BAMBOO, "Bamboo"}, {COTTON, "Cotton"}, {SILK, "Silk"}
};

const std::map<std::string, YarnSkein::fiberType> YarnSkein::strToFiber = {
    {"WOOL", WOOL}, {"ACRYLIC", ACRYLIC}, {"BAMBOO", BAMBOO}, {"COTTON", COTTON}, {"SILK", SILK}
};

// Main Constructor
YarnSkein::YarnSkein(std::string strandWeight, std::string color, double length, std::string fiber, 
                     double skeinWeight, double needleSize, double hookSize) : fiber(nullptr) {
    
    // Normalize string for map lookup
    std::transform(strandWeight.begin(), strandWeight.end(), strandWeight.begin(), ::toupper);
    
    if (strToWeight.count(strandWeight)) {
        this->strandWeight = strToWeight.at(strandWeight);
    } else {
        throw std::invalid_argument(strandWeight + " is not a valid strand weight.");
    }

    setColor(color);
    setLength(length);
    setFiber(fiber);

    // Validate physical attributes
    if (skeinWeight > 0) this->skeinWeight = skeinWeight;
    else throw std::invalid_argument("Skein weight must be positive.");

    if (hookSize > 0) this->hookSize = hookSize;
    else throw std::invalid_argument("Hook size must be positive.");

    if (needleSize > 0) this->needleSize = needleSize;
    else throw std::invalid_argument("Needle size must be positive.");
}

// Copy Constructor
YarnSkein::YarnSkein(const YarnSkein &y) : fiber(nullptr) {
    copyYarn(y);
}

// Assignment Operator
const YarnSkein &YarnSkein::operator=(const YarnSkein &y) {
    if (this != &y) {
        copyYarn(y);
    }
    return *this;
}

// Destructor
YarnSkein::~YarnSkein() {
    delete[] fiber;
}

// Basic setters/getters
void YarnSkein::setColor(std::string color) { this->color = color; }

void YarnSkein::setLength(double length) {
    if (length >= 0) this->length = length;
    else throw std::invalid_argument("Length cannot be negative.");
}

int YarnSkein::getStrandWeight() { 
    return static_cast<int>(this->strandWeight); 
}

std::string YarnSkein::getStrandWeightName() { return weightToStr.at(this->strandWeight); }
std::string YarnSkein::getColor() { return this->color; }
double YarnSkein::getLength() { return length; }
double YarnSkein::getSkeinWeight() { return skeinWeight; }
double YarnSkein::getNeedleSize() { return needleSize; }
double YarnSkein::getHookSize() { return hookSize; }

// Logic to convert dynamic array of fibers back to a string
std::string YarnSkein::getFiberList() {
    std::ostringstream outStr;
    if (numFiberType > 0) {
        outStr << fiberToStr.at(this->fiber[0]);
        for (int i = 1; i < numFiberType; i++) {
            outStr << ", " << fiberToStr.at(this->fiber[i]);
        }
    }
    return outStr.str();
}

// Private helper to parse the comma-separated input string
void YarnSkein::setFiber(std::string fiberInput) {
    std::istringstream inStr(fiberInput);
    std::string f;
    int i = 0;

    // Determine number of elements
    this->numFiberType = std::count(fiberInput.begin(), fiberInput.end(), ',') + 1;
    this->fiber = new fiberType[numFiberType];

    while (std::getline(inStr, f, ',')) {
        f = trim(f);
        std::transform(f.begin(), f.end(), f.begin(), ::toupper);
        
        if (strToFiber.count(f)) {
            this->fiber[i++] = strToFiber.at(f);
        } else {
            delete[] this->fiber; // Prevent memory leak on exception
            throw std::invalid_argument(f + " is not a valid fiber.");
        }
    }
}

// Deep copy logic for Rule of Three
void YarnSkein::copyYarn(const YarnSkein &y) {
    this->skeinWeight = y.skeinWeight;
    this->strandWeight = y.strandWeight;
    this->color = y.color;
    this->hookSize = y.hookSize;
    this->needleSize = y.needleSize;
    this->length = y.length;
    this->numFiberType = y.numFiberType;

    if (this->fiber != nullptr) {
        delete[] this->fiber;
    }

    this->fiber = new fiberType[numFiberType];
    for (int i = 0; i < numFiberType; i++) {
        this->fiber[i] = y.fiber[i];
    }
}

// Utility function to remove extra spaces during CSV parsing
std::string trim(const std::string &str, const std::string &whitespace) {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos) return ""; 

    const auto strEnd = str.find_last_not_of(whitespace);
    return str.substr(strBegin, strEnd - strBegin + 1);
}