#include "RequestHandler.h"
#include <iostream>

Request RequestHandler::parseRequest(std::string raw_req) {
    Request reqToReturn;

    std::vector<std::string> lines = split(raw_req, "\n");
    std::vector<std::string> lineThatICareAbout = split(lines[0], " ");

    reqToReturn.setReqVerb(lineThatICareAbout[0]);
    reqToReturn.setReqFile(lineThatICareAbout[1]);

    return reqToReturn;
}

std::vector<std::string> RequestHandler::split(const std::string& str, const std::string& delim){
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
