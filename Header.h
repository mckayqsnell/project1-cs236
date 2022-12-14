#ifndef PROJECT1_HEADER_H
#define PROJECT1_HEADER_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

class Header {
public:
    Header();
    Header(vector<string> attributes) : attributes(attributes){}
    ~Header();
    string toString();
    unsigned int getSize();
    string getAttribute(unsigned int index);
    void addAttribute(string attribute);
    void addAttributeList(vector<string> attributeList);
    vector<string> getAttributes();
    unsigned int getAttributeIndex(string attribute);

    //Project 4
    bool operator==(const Header h) const {
        return attributes == h.attributes;
    }
    //combine headers for natural join
    Header combineHeaders(Header otherHeader);
    // contains attribute
    bool containsAttribute(string attribute);

private:
    vector<string> attributes;

};


#endif //PROJECT1_HEADER_H
