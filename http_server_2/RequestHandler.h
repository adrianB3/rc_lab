//
// Created by adrianb3 on 6/8/19.
//

#ifndef HTTP_SERVER_2_REQUESTHANDLER_H
#define HTTP_SERVER_2_REQUESTHANDLER_H


#include "Request.h"
#include <vector>

class RequestHandler {

public:

    static Request parseRequest(std::string raw_req);
    static std::vector<std::string> split(const std::string& str, const std::string& delim);

};


#endif //HTTP_SERVER_2_REQUESTHANDLER_H
