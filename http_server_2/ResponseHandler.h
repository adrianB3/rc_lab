#ifndef HTTP_SERVER_2_RESPONSEHANDLER_H
#define HTTP_SERVER_2_RESPONSEHANDLER_H


#include <string>
#include "Request.h"

class ResponseHandler {
public:
    static std::string getResponse(Request req);
};


#endif //HTTP_SERVER_2_RESPONSEHANDLER_H
