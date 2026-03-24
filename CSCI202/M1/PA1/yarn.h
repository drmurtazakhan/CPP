/* Program name: yarn.h
   Author: Murtaza Ali Khan
   Date last updated: 3/13/2026
   Purpose: Defines the YarnSkein class, including enums for weight and fiber, 
            static maps for string conversion, and basic yarn attributes.
*/

#ifndef YARN_H
#define YARN_H

#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class YarnSkein
{
public:
    // Enums nested within the class scope
    enum weightType { LACE, SUPERFINE, FINE, LIGHT, MEDIUM, BULKY, SUPERBULKY, JUMBO };
    enum fiberType { WOOL, ACRYLIC, COTTON, BAMBOO, SILK };

    // Constant static maps for converting between strings and enums
    const static std::map<weightType, std::string> weightToStr;
    const static std::map<std::string, weightType> strToWeight;
    const static std::map<fiberType, std::string> fiberToStr;
    const static std::map<std::string, fiberType> strToFiber;

    // Constructors and Destructor (Rule of Three)
    YarnSkein(std::string strandWeight, std::string color, double length, std::string fiber, 
              double skeinWeight, double needleSize, double hookSize);
    YarnSkein(const YarnSkein &);
    const YarnSkein &operator=(const YarnSkein &);
    ~YarnSkein();

    // Setters
    void setColor(std::string color);
    void setLength(double length);

    // Getters - getStrandWeight returns int per UML requirement
    int getStrandWeight();
    std::string getStrandWeightName();
    std::string getColor();
    double getLength();
    std::string getFiberList();
    double getSkeinWeight();
    double getNeedleSize();
    double getHookSize();

private:
    // Helper functions for internal logic
    void setFiber(std::string fiber);
    void copyYarn(const YarnSkein &);
    
    // Private member variables
    weightType strandWeight;
    std::string color;
    double length;
    fiberType *fiber; // Dynamic array
    int numFiberType;
    double skeinWeight;
    double needleSize;
    double hookSize;
};

// Global utility function for string whitespace removal
std::string trim(const std::string &str, const std::string &whitespace = " ");

#endif